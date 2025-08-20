#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Only unique value is stored
    // store value in sorted order (ascending order)
    // Insertion, deletion and search have O(log(n)) time complexity
    // Generally implemented using red black tree or AVL tree
    // We can sort it in descending order using greater<type>

    // set<int> s;

    // to write in descending order
    set<int, greater<int>> s;

    // insert
    s.insert(10);
    s.insert(110);
    s.insert(20);
    s.insert(200);
    s.insert(10);
    s.insert(20);
    s.insert(110);
    s.insert(210);

    // delete
    s.erase(110);

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << " ";
    // }

    // search the element
    // find -> return the iterator of that number
    // if (s.find(200) != s.end()) // if 200 is found then this give iterator

    // if (s.find(280) != s.end())
    // {
    //     cout << "Present" << endl;
    // }
    // else
    // {
    //     cout << "Not present" << endl;
    // }

    // set hai to count = 1 hi ho sakta hai aur usse jyaada nahi ho sakta hai
    // count -> count of that number
    // if (s.count(240))
    // {
    //     cout << "Present" << endl;
    // }
    // else
    // {
    //     cout << "Absent" << endl;
    // }

    // cout << s.count(110) << endl;

    return 0;
}