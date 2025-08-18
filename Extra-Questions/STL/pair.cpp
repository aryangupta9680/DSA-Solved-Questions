#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pair<string, int> p;
    // two methods of insert
    // first method
    // p = make_pair("aryan", 20);

    // second method
    //  p.first = "aryan";
    //  p.second = 20;

    // cout << p << " "; // this give error
    // cout << p.first << " " << p.second << endl;

    // name, age, weight
    // pair<string, pair<int, int>> p;
    // first method
    // p = make_pair("aryan", make_pair(20, 70));

    // second method
    // p.first = "aryan";
    // p.second.first = 20;
    // p.second.second = 70;
    // cout << p.first << " " << p.second.first << " " << p.second.second << endl;

    // name, age, weight
    pair<pair<string, int>, int> p1;
    // p1.first.first = "aryan";
    // p1.first.second = 19;
    // p1.second = 65;

    // second method
    p1 = make_pair(make_pair("aryan", 20), 72);

    cout << p1.first.first << " " << p1.first.second << " " << p1.second << endl;

    return 0;
}