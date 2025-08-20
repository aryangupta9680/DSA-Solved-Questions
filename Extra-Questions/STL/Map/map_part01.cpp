#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // it stores data in key-value pair
    // key should be unique
    // it uses red black tree or AVL tree for implementation
    // Insertion, deletion and searching have O(log n) time complexity

    // map create
    // map<key_type, value_type> map_name;
    map<int, int> m;
    m.insert(make_pair(20, 30));
    m.insert(make_pair(30, 310));
    m.insert(make_pair(40, 230));
    m.insert(make_pair(20, 230)); // key is unique so it does not print on output
    m.insert(make_pair(50, 30));

    // second method to insert
    // insert to ker sakte aur hum value ko update bhi kr sakte hai
    m[100] = 60;
    m[20] = 7; // yaha pr value ko update kr diya hai

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     // cout << (*it).first << " " << (*it).second << endl;
    //     cout << it->first << " " << it->second << endl;
    // }

    // cout << endl;
    // cout << m[100] << endl; //o/p-> 60

    // cout << m[200] << endl; // o/p-> 0 -> isme confusion ho sakta hai ki ye value hai ya phir usme present nahi hai usko denote kiya hai
    // solution
    // if(m.count(200))
    // {
    //     cout << m[200] << endl;
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
