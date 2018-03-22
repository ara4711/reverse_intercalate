# reverse_intercalate
play around with c++, iterators and ranges


### HOWTO Build and run tests
1. download depedencies
  
    1 download [https://github.com/ericniebler/range-v3/]
     into Task1/ranges/range-v3-master
     
    2 download [https://github.com/Microsoft/Range-V3-VS2015]
     into Task1/ranges/Range-V3-VS2015-master

      (Note: at the time of writing, mar 2018, from hearsay that that project is not yet stable for vs2017).
     
    3 download [https://github.com/google/googletest]
     into Task1/googletest-master 
     
2. run  `start.bat`  -- starts a shell with the evironment variables set

in the shell do:

    1. `mkdir tmp & cd tmp` 

    2. `cmake  -G "Visual Studio 14" -Dgtest_force_shared_crt=ON ..`

    3. `cmake --build . --target ALL_BUILD --config Debug`   

    4. `"Task1\task1\Debug\testsTask1.exe"`
  
  ### Future plans
  
  compile with gcc and clang
