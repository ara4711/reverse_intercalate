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
    std::vector<std::wstring> wx = {  L"f�oo", L"bar", L"baz"   };
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
    - g�r f�rst en snygg c++ version. 
    - g�r v2: composability: g�r att intercalate tar en iterator som argument. Skicka in en reverse_iterator
    - g�r c++-wrapper f�r list-datatypen 
    - *TODO* g�r  range-wrapper f�r list-datatype
    - *H�R* g�r tester  med gtest 
       f�r l�nkningsfel 
       SVCRTD.lib(initializers.obj) : warning LNK4098: defaultlib 'libcmtd.lib' conflicts with use of other libs; use /NODEFAULTLIB:library
       och mer om jag har kod i tests.cpp
       Aha jag m�ste �ndra mina tester till att anv�nd /MTd de defaultade till /MDd.
       Ev kan jag �ndra gtest och gtest_main till /MDd ist�llet..
    - g�r ev tester med RapidCheck (QuickCheck-klon)
    - kompilera med gcc
    - prestanda-testa?
    - l�gg till cmake koll av till�tna kompilatorer   VC++ >= 14.1 and gcc >= 5.3 , ev clang

    Status:
    - har en "vanlig" c++17 version
    - har en "ranges" version som wrapp:ar ranges.

    Observationer:

    - (c++20) Ranges / Range adaptors / view adaptors i c++ verkar motsvara traversals
    - (c++20) Concepts  �r C++-termen f�r typeclass-constraints, verkar det som. 
    -  Traits �r lite som typeclasses, fast p� n�t annat s�tt..
    */
}

