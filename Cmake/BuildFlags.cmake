set(CMAKE_CXX_STANDARD             20)
set(CMAKE_C_STANDARD             11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -g")
set(GCC_COMPILE_FLAGS "${GCC_COMPILE_FLAGS} -Werror -Wall -Wextra -Wpedantic -g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-sanitize-recover=all"
    CACHE STRING "Compiler flags in asan build"
    FORCE)

set(GCC_COMPILE_FLAGS "${GCC_COMPILE_FLAGS} -fsanitize=address,undefined -fno-sanitize-recover=all"
    CACHE STRING "Compiler flags in asan build"
    FORCE)

