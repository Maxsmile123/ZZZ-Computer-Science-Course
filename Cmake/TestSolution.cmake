option(TEST_SOLUTION "Build solution" OFF)
option(ENABLE_PRIVATE_TESTS "Enable private tests" OFF)
option(GRADER "Building on CI" OFF)

function(patch_include_directories TARGET)
  if (TEST_SOLUTION)
    get_filename_component(TASK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    target_include_directories(${TARGET}
      PRIVATE ../private/${TASK_NAME})
  endif()

  target_include_directories(${TARGET}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endfunction()

function(prepend VAR PREFIX)
  set(LIST_VAR "")
  foreach(ELEM ${ARGN})
    list(APPEND LIST_VAR "${PREFIX}/${ELEM}")
  endforeach()
  set(${VAR} "${LIST_VAR}" PARENT_SCOPE)
endfunction()

function(add_shad_executable NAME)
  set(MULTI_VALUE_ARGS PRIVATE_TESTS SOLUTION_SRCS)
  cmake_parse_arguments(SHAD_LIBRARY "" "" "${MULTI_VALUE_ARGS}" ${ARGN})

  get_filename_component(TASK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  if (TEST_SOLUTION)
    prepend(SHAD_LIBRARY_SOLUTION_SRCS "../private/${TASK_NAME}" ${SHAD_LIBRARY_SOLUTION_SRCS})
  endif()

  if (ENABLE_PRIVATE_TESTS)
    prepend(SHAD_LIBRARY_PRIVATE_TESTS "../private/${TASK_NAME}" ${SHAD_LIBRARY_PRIVATE_TESTS})
  endif()

  add_executable(${NAME}
    ${SHAD_LIBRARY_UNPARSED_ARGUMENTS}
    ${SHAD_LIBRARY_SOLUTION_SRCS}
    ${SHAD_LIBRARY_PRIVATE_TESTS})

  patch_include_directories(${NAME})
endfunction()

function(add_shad_python_module NAME)
  set(MULTI_VALUE_ARGS SOLUTION_SRCS)
  cmake_parse_arguments(SHAD_LIBRARY "" "" "${MULTI_VALUE_ARGS}" ${ARGN})

  get_filename_component(TASK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  if (TEST_SOLUTION)
    prepend(SHAD_LIBRARY_SOLUTION_SRCS "../private/${TASK_NAME}" ${SHAD_LIBRARY_SOLUTION_SRCS})
  endif()

  add_library(${NAME} SHARED
    ${SHAD_LIBRARY_UNPARSED_ARGUMENTS}
    ${SHAD_LIBRARY_SOLUTION_SRCS})

  if (APPLE)
    target_link_libraries(${NAME} PRIVATE "-undefined dynamic_lookup")
  endif()

  patch_include_directories(${NAME})

  target_include_directories(${NAME} PRIVATE ${PYTHON_INCLUDE_DIRS})

  set_target_properties(${NAME} PROPERTIES PREFIX "")
  if (APPLE)
    set_target_properties(${NAME} PROPERTIES SUFFIX .so)
  endif()
endfunction()

add_custom_target(test-all)

function(add_catch TARGET)
  add_shad_executable(${TARGET}
    ${ARGN})

  target_link_libraries(${TARGET}
    contrib_catch_main)

  if (TEST_SOLUTION)
    add_custom_target(
      run_${TARGET}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      DEPENDS ${TARGET}
      COMMAND ${CMAKE_BINARY_DIR}/${TARGET})

    add_dependencies(test-all run_${TARGET})
  endif()
endfunction()
