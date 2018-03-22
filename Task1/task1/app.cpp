#include <cstddef>
#include "pg_list.h"
#include "task1.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>



// Task1:
// intercalate with L'.' a reversed generic list-like structure.
// method: use iterators and buffers you can append to
/* 
   Haskell

   task1 :: Traversable t => String -> t String -> String
   task1 =  intercalate "." . reverse
*/





void main(){
    /*list*/ 
    {
        // List(ListCell(Ident(name:"MyApp"))->ListCell(Ident(name:"MyModule"))->ListCell(Ident(name:"MyTable"))->null)
        // TODO supply an allocator to mkIdent to avoid using "new"
        List l;
        l = list_cons(*mkIdent(L"MyTable"), NIL);
        l = list_cons(*mkIdent(L"MyModule"), &l);
        l = list_cons(*mkIdent(L"MyApp"), &l);
        std::cout << "len: " << list_length(&l) << std::endl;

        list_traverse(l);

        std::wcout << "reverse is " << list_reverse_concat_v1(l) << std::endl;
    } 


    std::vector<std::string> x = {  "foo", "bar", "baz"   };
    std::vector<std::wstring> wx = {  L"föoo", L"bar", L"baz"   };
    std::string  delim(".");
    std::wstring wdelim(L".");
    
    {
        auto y = task1_v1(x, delim);     std::cout << "y is " << y << std::endl;
        auto z = task1_v1(wx, wdelim);   std::wcout << "z is " << z << std::endl;
    }

#ifdef HAS_CPP_RANGES
    {
        auto y = task1_v2(x, delim);     std::cout << "y is " << y << std::endl;
        auto z = task1_v2(wx, wdelim);    std::wcout << "z is " << z << std::endl;
    }
#endif
    std::cout << "Hello world" << std::endl;

    /*
    Plan:
    - gör först en snygg c++ version. 
    - gör v2: composability: gör att intercalate tar en iterator som argument. Skicka in en reverse_iterator
    - gör c++-wrapper för list-datatypen 
    - *TODO* gör  range-wrapper för list-datatype
    - *HÄR* gör tester  med gtest 
       får länkningsfel 
       SVCRTD.lib(initializers.obj) : warning LNK4098: defaultlib 'libcmtd.lib' conflicts with use of other libs; use /NODEFAULTLIB:library
       och mer om jag har kod i tests.cpp
       Aha jag måste ändra mina tester till att använd /MTd de defaultade till /MDd.
       Ev kan jag ändra gtest och gtest_main till /MDd istället..
    - gör ev tester med RapidCheck (QuickCheck-klon)
    - kompilera med gcc
    - prestanda-testa?
    - lägg till cmake koll av tillåtna kompilatorer   VC++ >= 14.1 and gcc >= 5.3 , ev clang

    Status:
    - har en "vanlig" c++17 version
    - har en "ranges" version som wrapp:ar ranges.

    Observationer:

    - (c++20) Ranges / Range adaptors / view adaptors i c++ verkar motsvara traversals
    - (c++20) Concepts  är C++-termen för typeclass-constraints, verkar det som. 
    -  Traits är lite som typeclasses, fast på nåt annat sätt..
    */
}

