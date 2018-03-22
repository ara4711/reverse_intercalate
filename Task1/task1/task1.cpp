#include <cstddef>
#include "task1.hpp"
#include "pg_list.h"
#include <string>


/***********************************************************************************************
*  Constructors and util methods for the Lecacy "Plain old C data" structure 'pg_list'.
*  Note   List* is used instead of List since NULL is a valid "pg_list", by its design.
*/


const Ident * const mkIdent(const wchar_t* name) 
{ 
    Ident *ip = new Ident();
    ip->name = name;
    return ip;
}

const List list_cons(const Node &n, List *l) 
{
    ListCell *cp = new ListCell();
    cp->data.ptr_value = (void *)&n;
     
    List l2;
    l2.head = cp;
    cp->next = l2.tail = list_head(l);
    l2.length = list_length(l)+1;

    return l2;
}

void list_traverse(List &l)
{
    for (auto c = l.head ; c; c = c->next)
    {
        const auto name = static_cast<Ident*>(c->data.ptr_value)->name;
        std::wcout << name << std::endl;
    }
}


/***********************************************************************************************
* Task1:
* intercalate with L'.' the reversal of a Legacy data structure; a list of std::wstring .
*/

std::wstring list_reverse_concat_v1(List &l)
{
    //TODO pre-allocate l.length;
    std::vector<std::wstring> vl;

    for (auto c = l.head; c; c = c->next)
    {
        const auto name = static_cast<Ident*>(c->data.ptr_value)->name;
        vl.push_back(name);
    }
    std::wstring delim(L".");
    return task1_v1(vl, delim);

}
