#include <iostream>
using namespace std;

class a
{
public:
    double e;
    int b;
    char c;
    char d;
};

class b
{
    // empty class
};

int main(){
    a obj1;
    cout << sizeof(obj1) << endl;

    // b obj2;
    // cout << sizeof(obj2) << endl;


    return 0;
}