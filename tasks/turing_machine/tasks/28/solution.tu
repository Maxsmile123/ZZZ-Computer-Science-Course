// Решите поставленную задачу в формате четвёрок
00,1,>,00 //перемещаемся в конец слова
00,0,>,00
00, ,<,01


//обрабатываем 1 цифру
01,1,=,to_end1    pr1, ,|,to_work1           
01,0,<,02      
01, ,#,01        

to_end1,0,>,to_end1    to_work1,|,<,to_work1
to_end1,1,>,to_end1    to_work1, ,<,to_work1
to_end1, ,>,pr1        to_work1,1,=,02       
//вернулись в место работы


//обрабатываем 2 цифру
02,1,=,to_end2    cycle_20,|,>,cycle_20  cycle_21,|,>,cycle_21    // !!!!!! ЗДЕСЬ И ДАЛЕЕ ПЕРВАЯ ЦИФРА             
02,0,<,03         cycle_20, ,|,cycle_21  cycle_21, ,|,to_work2    // ПОСЛЕ сycle ОЗНАЧАЕТ ЦИФРУ ЧИСЛА,
02, ,#,02                                                         // ПОСЛЕДУЮЩИЕ ЦИФРЫ ОЗНАЧАЮТ НОМЕР 
                                                                  // ИТЕРАЦИИ !!!!!!
        

to_end2,0,>,to_end2    to_work2,|,<,to_work2    cycle_2w,1,<,03
to_end2,1,>,to_end2    to_work2, ,<,to_work2    cycle_2w,0,<,03    
to_end2, ,>,cycle_20   to_work2,0,<,cycle_2w
                       to_work2,1,<,cycle_2w                            
//вернулись в место работы


//обрабатываем 3 цифру
03,1,=,to_end3                   
03,0,<,04         
03, ,#,03        

cycle_30,|,>,cycle_30    cycle_31,|,>,cycle_31     cycle_32,|,>,cycle_32     cycle_33,|,>,cycle_33
cycle_30, ,|,cycle_31    cycle_31, ,|,cycle_32     cycle_32, ,|,cycle_33     cycle_33, ,|,to_work3
//выводим 4 палки

to_end3,0,>,to_end3    to_work3,|,<,to_work3    cycle_3w,1,<,cycle_31w
to_end3,1,>,to_end3    to_work3, ,<,to_work3    cycle_3w,0,<,cycle_31w
to_end3, ,>,cycle_30   to_work3,0,<,cycle_3w    cycle_31w,1,<,04
                       to_work3,1,<,cycle_3w    cycle_31w,0,<,04
//вернулись в место работы


//обрабатываем 4 цифру
04,1,=,to_end4                   
04,0,<,05         
04, ,#,04        

to_end4,0,>,to_end4
to_end4,1,>,to_end4
to_end4, ,>,cycle_40

//выводим 8 палок
cycle_40,|,>,cycle_40    cycle_41,|,>,cycle_41     cycle_42,|,>,cycle_42     cycle_43,|,>,cycle_43
cycle_40, ,|,cycle_41    cycle_41, ,|,cycle_42     cycle_42, ,|,cycle_43     cycle_43, ,|,cycle_44

cycle_44,|,>,cycle_44    cycle_45,|,>,cycle_45    cycle_46,|,>,cycle_46    cycle_47,|,>,cycle_47   
cycle_44, ,|,cycle_45    cycle_45, ,|,cycle_46    cycle_46, ,|,cycle_47    cycle_47, ,|,to_work4
//выводим 8 палок

to_work4,|,<,to_work4    cycle_4w,1,<,cycle_41w     cycle_42w,1,<,05
to_work4, ,<,to_work4    cycle_4w,0,<,cycle_41w     cycle_42w,0,<,05
to_work4,0,<,cycle_4w    cycle_41w,1,<,cycle_42w
                       to_work4,1,<,cycle_4w    cycle_41w,0,<,cycle_42w
//вернулись в место работы


//обрабатываем цифру 5
05,1,=,to_end5                   
05,0,<,06         
05, ,#,05        

to_end5,0,>,to_end5
to_end5,1,>,to_end5
to_end5, ,>,cycle_50

//выводим 16 палок
cycle_50,|,>,cycle_50    cycle_51,|,>,cycle_51     cycle_52,|,>,cycle_52     cycle_53,|,>,cycle_53
cycle_50, ,|,cycle_51    cycle_51, ,|,cycle_52     cycle_52, ,|,cycle_53     cycle_53, ,|,cycle_54

cycle_54,|,>,cycle_54    cycle_55,|,>,cycle_55    cycle_56,|,>,cycle_56    cycle_57,|,>,cycle_57   
cycle_54, ,|,cycle_55    cycle_55, ,|,cycle_56    cycle_56, ,|,cycle_57    cycle_57, ,|,cycle_58

cycle_58,|,>,cycle_58    cycle_59,|,>,cycle_59     cycle_510,|,>,cycle_510    cycle_511,|,>,cycle_511    
cycle_58, ,|,cycle_59    cycle_59, ,|,cycle_510    cycle_510, ,|,cycle_511    cycle_511, ,|,cycle_512

cycle_512,|,>,cycle_512    cycle_513,|,>,cycle_513    cycle_514,|,>,cycle_514   cycle_515,|,>,cycle_515        
cycle_512, ,|,cycle_513    cycle_513, ,|,cycle_514    cycle_514, ,|,cycle_515   cycle_515, ,|,to_work5   
//выводим 16 палок

to_work5,|,<,to_work5    cycle_5w,1,<,cycle_51w     cycle_52w,1,<,cycle_53w        
to_work5, ,<,to_work5    cycle_5w,0,<,cycle_51w     cycle_52w,0,<,cycle_53w
to_work5,1,<,cycle_5w    cycle_51w,1,<,cycle_52w    cycle_53w,1,<,06
to_work5,0,<,cycle_5w    cycle_51w,0,<,cycle_52w    cycle_53w,0,<,06
//вернулись в место работы


//обрабатываем 6 цифру
06,1,=,to_end6                   
06,0,<,07         
06, ,#,06        

to_end6,0,>,to_end6
to_end6,1,>,to_end6
to_end6, ,>,cycle_60

//выводим 32 палки
cycle_60,|,>,cycle_60    cycle_61,|,>,cycle_61     cycle_62,|,>,cycle_62     cycle_63,|,>,cycle_63
cycle_60, ,|,cycle_61    cycle_61, ,|,cycle_62     cycle_62, ,|,cycle_63     cycle_63, ,|,cycle_64

cycle_64,|,>,cycle_64    cycle_65,|,>,cycle_65    cycle_66,|,>,cycle_66    cycle_67,|,>,cycle_67   
cycle_64, ,|,cycle_65    cycle_65, ,|,cycle_66    cycle_66, ,|,cycle_67    cycle_67, ,|,cycle_68

cycle_68,|,>,cycle_68    cycle_69,|,>,cycle_69     cycle_610,|,>,cycle_610    cycle_611,|,>,cycle_611    
cycle_68, ,|,cycle_69    cycle_69, ,|,cycle_610    cycle_610, ,|,cycle_611    cycle_611, ,|,cycle_612

cycle_612,|,>,cycle_612    cycle_613,|,>,cycle_613    cycle_614,|,>,cycle_614   cycle_615,|,>,cycle_615        
cycle_612, ,|,cycle_613    cycle_613, ,|,cycle_614    cycle_614, ,|,cycle_615   cycle_615, ,|,cycle_616 

cycle_616,|,>,cycle_616    cycle_617,|,>,cycle_617     cycle_618,|,>,cycle_618   cycle_619,|,>,cycle_619
cycle_616, ,|,cycle_617    cycle_617, ,|,cycle_618     cycle_618, ,|,cycle_619   cycle_619, ,|,cycle_620

cycle_620,|,>,cycle_620    cycle_621,|,>,cycle_621     cycle_622,|,>,cycle_622   cycle_623,|,>,cycle_623
cycle_620, ,|,cycle_621    cycle_621, ,|,cycle_622     cycle_622, ,|,cycle_623   cycle_623, ,|,cycle_624

cycle_624,|,>,cycle_624    cycle_625,|,>,cycle_625     cycle_626,|,>,cycle_626   cycle_627,|,>,cycle_627
cycle_624, ,|,cycle_625    cycle_625, ,|,cycle_626     cycle_626, ,|,cycle_627   cycle_627, ,|,cycle_628

cycle_628,|,>,cycle_628    cycle_629,|,>,cycle_629     cycle_630,|,>,cycle_630   cycle_631,|,>,cycle_631
cycle_628, ,|,cycle_629    cycle_629, ,|,cycle_630     cycle_630, ,|,cycle_631   cycle_631, ,|,to_work6   
//выводим 32 палки

to_work6,|,<,to_work6    cycle_6w,1,<,cycle_61w     cycle_62w,1,<,cycle_63w    cycle_64w,1,<,07        
to_work6, ,<,to_work6    cycle_6w,0,<,cycle_61w     cycle_62w,0,<,cycle_63w    cycle_64w,0,<,07
to_work6,1,<,cycle_6w    cycle_61w,1,<,cycle_62w    cycle_63w,1,<,cycle_64w
to_work6,0,<,cycle_6w    cycle_61w,0,<,cycle_62w    cycle_63w,0,<,cycle_64w
//Вернулись в место работы


//обрабатываем 7 цифру
07,1,=,to_end7                   
07,0,<,08         
07, ,#,07        

to_end7,0,>,to_end7
to_end7,1,>,to_end7
to_end7, ,>,cycle_70

//выводим 64 палки
cycle_70,|,>,cycle_70    cycle_71,|,>,cycle_71     cycle_72,|,>,cycle_72     cycle_73,|,>,cycle_73
cycle_70, ,|,cycle_71    cycle_71, ,|,cycle_72     cycle_72, ,|,cycle_73     cycle_73, ,|,cycle_74

cycle_74,|,>,cycle_74    cycle_75,|,>,cycle_75    cycle_76,|,>,cycle_76    cycle_77,|,>,cycle_77   
cycle_74, ,|,cycle_75    cycle_75, ,|,cycle_76    cycle_76, ,|,cycle_77    cycle_77, ,|,cycle_78

cycle_78,|,>,cycle_78    cycle_79,|,>,cycle_79     cycle_710,|,>,cycle_710    cycle_711,|,>,cycle_711    
cycle_78, ,|,cycle_79    cycle_79, ,|,cycle_710    cycle_710, ,|,cycle_711    cycle_711, ,|,cycle_712

cycle_712,|,>,cycle_712    cycle_713,|,>,cycle_713    cycle_714,|,>,cycle_714    cycle_715,|,>,cycle_715        
cycle_712, ,|,cycle_713    cycle_713, ,|,cycle_714    cycle_714, ,|,cycle_715    cycle_715, ,|,cycle_716 

cycle_716,|,>,cycle_716    cycle_717,|,>,cycle_717     cycle_718,|,>,cycle_718   cycle_719,|,>,cycle_719
cycle_716, ,|,cycle_717    cycle_717, ,|,cycle_718     cycle_718, ,|,cycle_719   cycle_719, ,|,cycle_720

cycle_720,|,>,cycle_720    cycle_721,|,>,cycle_721     cycle_722,|,>,cycle_722   cycle_723,|,>,cycle_723
cycle_720, ,|,cycle_721    cycle_721, ,|,cycle_722     cycle_722, ,|,cycle_723   cycle_723, ,|,cycle_724

cycle_724,|,>,cycle_724    cycle_725,|,>,cycle_725     cycle_726,|,>,cycle_726   cycle_727,|,>,cycle_727
cycle_724, ,|,cycle_725    cycle_725, ,|,cycle_726     cycle_726, ,|,cycle_727   cycle_727, ,|,cycle_728

cycle_728,|,>,cycle_728    cycle_729,|,>,cycle_729     cycle_730,|,>,cycle_730   cycle_731,|,>,cycle_731
cycle_728, ,|,cycle_729    cycle_729, ,|,cycle_730     cycle_730, ,|,cycle_731   cycle_731, ,|,cycle_732

cycle_732,|,>,cycle_732    cycle_733,|,>,cycle_733     cycle_734,|,>,cycle_734   cycle_735,|,>,cycle_735
cycle_732, ,|,cycle_733    cycle_733, ,|,cycle_734     cycle_734, ,|,cycle_735   cycle_735, ,|,cycle_736

cycle_736,|,>,cycle_736    cycle_737,|,>,cycle_737     cycle_738,|,>,cycle_738   cycle_739,|,>,cycle_739
cycle_736, ,|,cycle_737    cycle_737, ,|,cycle_738     cycle_738, ,|,cycle_739   cycle_739, ,|,cycle_740

cycle_740,|,>,cycle_740    cycle_741,|,>,cycle_741     cycle_742,|,>,cycle_742   cycle_743,|,>,cycle_743
cycle_740, ,|,cycle_741    cycle_741, ,|,cycle_742     cycle_742, ,|,cycle_743   cycle_743, ,|,cycle_744

cycle_744,|,>,cycle_744    cycle_745,|,>,cycle_745     cycle_746,|,>,cycle_746   cycle_747,|,>,cycle_747
cycle_744, ,|,cycle_745    cycle_745, ,|,cycle_746     cycle_746, ,|,cycle_747   cycle_747, ,|,cycle_748

cycle_748,|,>,cycle_748    cycle_749,|,>,cycle_749     cycle_750,|,>,cycle_750   cycle_751,|,>,cycle_751
cycle_748, ,|,cycle_749    cycle_749, ,|,cycle_750     cycle_750, ,|,cycle_751   cycle_751, ,|,cycle_752

cycle_752,|,>,cycle_752    cycle_753,|,>,cycle_753     cycle_754,|,>,cycle_754   cycle_755,|,>,cycle_755
cycle_752, ,|,cycle_753    cycle_753, ,|,cycle_754     cycle_754, ,|,cycle_755   cycle_755, ,|,cycle_756

cycle_756,|,>,cycle_756    cycle_757,|,>,cycle_757     cycle_758,|,>,cycle_758   cycle_759,|,>,cycle_759
cycle_756, ,|,cycle_757    cycle_757, ,|,cycle_758     cycle_758, ,|,cycle_759   cycle_759, ,|,cycle_760

cycle_760,|,>,cycle_760    cycle_761,|,>,cycle_761     cycle_762,|,>,cycle_762   cycle_763,|,>,cycle_763
cycle_760, ,|,cycle_761    cycle_761, ,|,cycle_762     cycle_762, ,|,cycle_763   cycle_763, ,|,to_work7   
//выводим 64 палки

to_work7,|,<,to_work7    cycle_7w,1,<,cycle_71w     cycle_72w,1,<,cycle_73w    cycle_74w,1,<,cycle_75w 
to_work7, ,<,to_work7    cycle_7w,0,<,cycle_71w     cycle_72w,0,<,cycle_73w    cycle_74w,0,<,cycle_75w
to_work7,1,<,cycle_7w    cycle_71w,1,<,cycle_72w    cycle_73w,1,<,cycle_74w    cycle_75w,1,<,08
to_work7,0,<,cycle_7w    cycle_71w,0,<,cycle_72w    cycle_73w,0,<,cycle_74w    cycle_75w,0,<,08
//Вернулись в место работы


//обрабатываем 8 цифру
08,1,=,to_end8                   
08,0,<,final         
08, ,#,08        

to_end8,0,>,to_end8
to_end8,1,>,to_end8
to_end8, ,>,cycle_80

//выводим 128 палок
cycle_80,|,>,cycle_80    cycle_81,|,>,cycle_81     cycle_82,|,>,cycle_82     cycle_83,|,>,cycle_83
cycle_80, ,|,cycle_81    cycle_81, ,|,cycle_82     cycle_82, ,|,cycle_83     cycle_83, ,|,cycle_84

cycle_84,|,>,cycle_84    cycle_85,|,>,cycle_85    cycle_86,|,>,cycle_86    cycle_87,|,>,cycle_87   
cycle_84, ,|,cycle_85    cycle_85, ,|,cycle_86    cycle_86, ,|,cycle_87    cycle_87, ,|,cycle_88

cycle_88,|,>,cycle_88    cycle_89,|,>,cycle_89     cycle_810,|,>,cycle_810    cycle_811,|,>,cycle_811    
cycle_88, ,|,cycle_89    cycle_89, ,|,cycle_810    cycle_810, ,|,cycle_811    cycle_811, ,|,cycle_812

cycle_812,|,>,cycle_812    cycle_813,|,>,cycle_813    cycle_814,|,>,cycle_814    cycle_815,|,>,cycle_815        
cycle_812, ,|,cycle_813    cycle_813, ,|,cycle_814    cycle_814, ,|,cycle_815    cycle_815, ,|,cycle_816 

cycle_816,|,>,cycle_816    cycle_817,|,>,cycle_817     cycle_818,|,>,cycle_818   cycle_819,|,>,cycle_819
cycle_816, ,|,cycle_817    cycle_817, ,|,cycle_818     cycle_818, ,|,cycle_819   cycle_819, ,|,cycle_820

cycle_820,|,>,cycle_820    cycle_821,|,>,cycle_821     cycle_822,|,>,cycle_822   cycle_823,|,>,cycle_823
cycle_820, ,|,cycle_821    cycle_821, ,|,cycle_822     cycle_822, ,|,cycle_823   cycle_823, ,|,cycle_824

cycle_824,|,>,cycle_824    cycle_825,|,>,cycle_825     cycle_826,|,>,cycle_826   cycle_827,|,>,cycle_827
cycle_824, ,|,cycle_825    cycle_825, ,|,cycle_826     cycle_826, ,|,cycle_827   cycle_827, ,|,cycle_828

cycle_828,|,>,cycle_828    cycle_829,|,>,cycle_829     cycle_830,|,>,cycle_830   cycle_831,|,>,cycle_831
cycle_828, ,|,cycle_829    cycle_829, ,|,cycle_830     cycle_830, ,|,cycle_831   cycle_831, ,|,cycle_832

cycle_832,|,>,cycle_832    cycle_833,|,>,cycle_833     cycle_834,|,>,cycle_834   cycle_835,|,>,cycle_835
cycle_832, ,|,cycle_833    cycle_833, ,|,cycle_834     cycle_834, ,|,cycle_835   cycle_835, ,|,cycle_836

cycle_836,|,>,cycle_836    cycle_837,|,>,cycle_837     cycle_838,|,>,cycle_838   cycle_839,|,>,cycle_839
cycle_836, ,|,cycle_837    cycle_837, ,|,cycle_838     cycle_838, ,|,cycle_839   cycle_839, ,|,cycle_840

cycle_840,|,>,cycle_840    cycle_841,|,>,cycle_841     cycle_842,|,>,cycle_842   cycle_843,|,>,cycle_843
cycle_840, ,|,cycle_841    cycle_841, ,|,cycle_842     cycle_842, ,|,cycle_843   cycle_843, ,|,cycle_844

cycle_844,|,>,cycle_844    cycle_845,|,>,cycle_845     cycle_846,|,>,cycle_846   cycle_847,|,>,cycle_847
cycle_844, ,|,cycle_845    cycle_845, ,|,cycle_846     cycle_846, ,|,cycle_847   cycle_847, ,|,cycle_848

cycle_848,|,>,cycle_848    cycle_849,|,>,cycle_849     cycle_850,|,>,cycle_850   cycle_851,|,>,cycle_851
cycle_848, ,|,cycle_849    cycle_849, ,|,cycle_850     cycle_850, ,|,cycle_851   cycle_851, ,|,cycle_852

cycle_852,|,>,cycle_852    cycle_853,|,>,cycle_853     cycle_854,|,>,cycle_854   cycle_855,|,>,cycle_855
cycle_852, ,|,cycle_853    cycle_853, ,|,cycle_854     cycle_854, ,|,cycle_855   cycle_855, ,|,cycle_856

cycle_856,|,>,cycle_856    cycle_857,|,>,cycle_857     cycle_858,|,>,cycle_858   cycle_859,|,>,cycle_859
cycle_856, ,|,cycle_857    cycle_857, ,|,cycle_858     cycle_858, ,|,cycle_859   cycle_859, ,|,cycle_860

cycle_860,|,>,cycle_860    cycle_861,|,>,cycle_861     cycle_862,|,>,cycle_862   cycle_863,|,>,cycle_863
cycle_860, ,|,cycle_861    cycle_861, ,|,cycle_862     cycle_862, ,|,cycle_863   cycle_863, ,|,cycle_864

cycle_864,|,>,cycle_864    cycle_865,|,>,cycle_865     cycle_866,|,>,cycle_866   cycle_867,|,>,cycle_867
cycle_864, ,|,cycle_865    cycle_865, ,|,cycle_866     cycle_866, ,|,cycle_867   cycle_867, ,|,cycle_868

cycle_868,|,>,cycle_868    cycle_869,|,>,cycle_869     cycle_870,|,>,cycle_870   cycle_871,|,>,cycle_871
cycle_868, ,|,cycle_869    cycle_869, ,|,cycle_870     cycle_870, ,|,cycle_871   cycle_871, ,|,cycle_872

cycle_872,|,>,cycle_872    cycle_873,|,>,cycle_873     cycle_874,|,>,cycle_874   cycle_875,|,>,cycle_875
cycle_872, ,|,cycle_873    cycle_873, ,|,cycle_874     cycle_874, ,|,cycle_875   cycle_875, ,|,cycle_876

cycle_876,|,>,cycle_876    cycle_877,|,>,cycle_877     cycle_878,|,>,cycle_878   cycle_879,|,>,cycle_879
cycle_876, ,|,cycle_877    cycle_877, ,|,cycle_878     cycle_878, ,|,cycle_879   cycle_879, ,|,cycle_880

cycle_880,|,>,cycle_880    cycle_881,|,>,cycle_881     cycle_882,|,>,cycle_882   cycle_883,|,>,cycle_883
cycle_880, ,|,cycle_881    cycle_881, ,|,cycle_882     cycle_882, ,|,cycle_883   cycle_883, ,|,cycle_884

cycle_884,|,>,cycle_884    cycle_885,|,>,cycle_885     cycle_886,|,>,cycle_886   cycle_887,|,>,cycle_887
cycle_884, ,|,cycle_885    cycle_885, ,|,cycle_886     cycle_886, ,|,cycle_887   cycle_887, ,|,cycle_888

cycle_888,|,>,cycle_888    cycle_889,|,>,cycle_889     cycle_890,|,>,cycle_890   cycle_891,|,>,cycle_891
cycle_888, ,|,cycle_889    cycle_889, ,|,cycle_890     cycle_890, ,|,cycle_891   cycle_891, ,|,cycle_892

cycle_892,|,>,cycle_892    cycle_893,|,>,cycle_893     cycle_894,|,>,cycle_894   cycle_895,|,>,cycle_895
cycle_892, ,|,cycle_893    cycle_893, ,|,cycle_894     cycle_894, ,|,cycle_895   cycle_895, ,|,cycle_896

cycle_896,|,>,cycle_896    cycle_897,|,>,cycle_897    
cycle_896, ,|,cycle_897    cycle_897, ,|,cycle_898  
       
cycle_898,|,>,cycle_898    cycle_899,|,>,cycle_899
cycle_898, ,|,cycle_899    cycle_899, ,|,cycle_8100

cycle_8100,|,>,cycle_8100   cycle_8101,|,>,cycle_8101
cycle_8100, ,|,cycle_8101   cycle_8101, ,|,cycle_8102

cycle_8102,|,>,cycle_8102   cycle_8103,|,>,cycle_8103
cycle_8102, ,|,cycle_8103   cycle_8103, ,|,cycle_8104

cycle_8104,|,>,cycle_8104   cycle_8105,|,>,cycle_8105
cycle_8104, ,|,cycle_8105   cycle_8105, ,|,cycle_8106

cycle_8106,|,>,cycle_8106   cycle_8107,|,>,cycle_8107
cycle_8106, ,|,cycle_8107   cycle_8107, ,|,cycle_8108

cycle_8108,|,>,cycle_8108   cycle_8109,|,>,cycle_8109
cycle_8108, ,|,cycle_8109   cycle_8109, ,|,cycle_8110

cycle_8110,|,>,cycle_8110   cycle_8111,|,>,cycle_8111
cycle_8110, ,|,cycle_8111   cycle_8111, ,|,cycle_8112

cycle_8112,|,>,cycle_8112   cycle_8113,|,>,cycle_8113
cycle_8112, ,|,cycle_8113   cycle_8113, ,|,cycle_8114

cycle_8114,|,>,cycle_8114   cycle_8115,|,>,cycle_8115
cycle_8114, ,|,cycle_8115   cycle_8115, ,|,cycle_8116

cycle_8116,|,>,cycle_8116   cycle_8117,|,>,cycle_8117
cycle_8116, ,|,cycle_8117   cycle_8117, ,|,cycle_8118

cycle_8118,|,>,cycle_8118   cycle_8119,|,>,cycle_8119
cycle_8118, ,|,cycle_8119   cycle_8119, ,|,cycle_8120

cycle_8120,|,>,cycle_8120   cycle_8121,|,>,cycle_8121
cycle_8120, ,|,cycle_8121   cycle_8121, ,|,cycle_8122

cycle_8122,|,>,cycle_8122   cycle_8123,|,>,cycle_8123
cycle_8122, ,|,cycle_8123   cycle_8123, ,|,cycle_8124

cycle_8124,|,>,cycle_8124   cycle_8125,|,>,cycle_8125
cycle_8124, ,|,cycle_8125   cycle_8125, ,|,cycle_8126

cycle_8126,|,>,cycle_8126   cycle_8127,|,>,cycle_8127
cycle_8126, ,|,cycle_8127   cycle_8127, ,|,to_work8
//выводим 128 палок

to_work8,|,<,to_work8    cycle_8w,1,<,cycle_81w     cycle_82w,1,<,cycle_83w    cycle_84w,1,<,cycle_85w 
to_work8, ,<,to_work8    cycle_8w,0,<,cycle_81w     cycle_82w,0,<,cycle_83w    cycle_84w,0,<,cycle_85w
to_work8,1,<,cycle_8w    cycle_81w,1,<,cycle_82w    cycle_83w,1,<,cycle_84w    cycle_85w,1,<,cycle_86w
to_work8,0,<,cycle_8w    cycle_81w,0,<,cycle_82w    cycle_83w,0,<,cycle_84w    cycle_85w,0,<,cycle_86w

cycle_86w,0,<,final
cycle_86w,1,<,final
//Вернулись в начало

final, ,#,final
