#ifndef TASK1_H
#define TASK1_H

#include <cstddef>
#include "pg_list.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>



/***********************************************************************************************
* Task1:
* intercalate with L'.' the reversal of a Legacy data structure; a list of std::wstring .
*/
std::wstring list_reverse_concat_v1(List &l);


/***********************************************************************************************
*  Constructors and util methods for the Lecacy "Plain old C data" structure 'pg_list'.
*/

const Ident * const mkIdent(const wchar_t* name);
const List list_cons(const Node &n, List *l);
void list_traverse(List &l);


/*************************************************
 * v1 : c++17
 * intercalate with L'.' a reversed generic list-like structure.
 * implemented using a handy method std::ostream_iterator and "stream append" '<<'
 */
template <class T>
T  task1_v1(std::vector<T> x, T delim)
{
    // credits: implementation generalized from 
    // https://www.programming-idioms.org/idiom/53/join-a-list-of-strings/1552/cpp @2018-03

    T y;
    switch (x.size())
    {
    case 0: y = {};   break;
    case 1: y = x[0]; break;
    default:
        // TODO investigate: is ostringstream lean enough?
        std::basic_ostringstream<T::value_type> os;
        std::copy(x.rbegin(), x.rend() - 1,                             // append all but the FIRST item, in REVERSE order!
            std::ostream_iterator<T,T::value_type>(os, delim.c_str())); // intersperse the delimitor
        os << *x.begin();                                               // finally append the FIRST elemen
        y = os.str();
    }
    return y;
}




#ifdef HAS_CPP_RANGES
#include <range/v3/all.hpp>

/*************************************************
* v2 : c++20
* intercalate with L'.' a reversed generic list-like structure.
* implemented using ranges.
*
*    task1 :: Traversable lst, Monoid str => lst str -> str -> str
*    task1 =  intercalate "." . reverse
*/
template <class T>
T  task1_v2(std::vector<T> vec, T delim)
{
    using namespace ranges::v3;

    auto rng = vec | view::reverse | view::intersperse(delim);

    // TODO verify: that accumulation is efficient. (possibly use ostringstream?)
    T acc;
    for (const auto &item : rng) acc += item;
    return acc;
}

#endif


#endif