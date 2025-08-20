#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // data hai wo sorted form mein rahega
    // key ab unique nahi ho to chalega
    // duplicate values and duplicate keys are allowed
    // isme subscript wala use nahi ker sakte m[100] wala
    // it uses red black tree or AVL tree for implementation
    // Insertion, deletion and searching have O(log n) time complexity

    // multimap create
    // multimap<key_type, value_type> map_name;
    multimap<int, int> m;
    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 310));
    m.insert(make_pair(40, 230));
    m.insert(make_pair(20, 230)); 
    m.insert(make_pair(50, 30));

    // second method to insert
    // m[100] = 60; -> isme ye allowed nahi hoga kyuki pata nahi chalega konsi key mein change karna hai kyuki duplicate keys present ho sakti hai
    // m[20] = 7; // not allowed in multimap

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     // cout << (*it).first << " " << (*it).second << endl;
    //     cout << it->first << " " << it->second << endl;
    // }

    // delete
    m.erase(20);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        // cout << (*it).first << " " << (*it).second << endl;
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
