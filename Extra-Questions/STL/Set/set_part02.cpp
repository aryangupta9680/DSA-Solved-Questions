#include <iostream>
// #include <utility> // for pair
// #include <map>     // for map
// #include <set>     // for set
// #include <list>    // for list
#include <bits/stdc++.h>
using namespace std;

// kya class ko mein set mein daal sakta hu? -> haan daal sakte hai
class Person
{
public:
    int age;
    string name;

    // ye abhi error dega kyuki isse pata nahi ki isko sort kese kare?
    // isko solve aise karenge
    bool operator<(const Person &other) const
    {
        // age ke basis pr sort karna hai
        // return age < other.age;
        // for reverse order
        return age > other.age;
    }
    // ab ye koi error nahi dega
};

int main()
{
    set<Person> s;
    Person p1, p2, p3;
    p1.age = 20, p1.name = "aryan";
    p2.age = 10, p2.name = "bharat";
    p3.age = 30, p3.name = "nikunj";

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    for (auto it = s.begin(); it != s.end(); it++)
    {
        // cout << (*it).age << " " << (*it).name << endl;
        // isko aise bhi likh sakte hai
        cout << it->age << " " << it->name << endl;
    }

    return 0;
}