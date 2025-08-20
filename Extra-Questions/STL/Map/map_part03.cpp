// unordered map

#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Order does not matter (elements are not stored in sorted order)
    // unique keys are present and duplicate keys are not allowed
    // not necessary it should be in sorted form
    // implementation -> hashing
    // insert, search or delete -> time complexity (Average Case) -> O(1) 
    // insert, search or delete -> time complexity (Worst Case) -> O(n) 

    unordered_map<int, int> m;
    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 310));
    m.insert(make_pair(40, 230));
    m.insert(make_pair(20, 230));
    m.insert(make_pair(50, 30));

    m[20] = 70; // it is allowed

    for (auto it = m.begin(); it != m.end(); it++)
    {
        // cout << (*it).first << " " << (*it).second << endl;
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
