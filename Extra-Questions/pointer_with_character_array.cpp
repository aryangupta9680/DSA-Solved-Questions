#include <iostream>
using namespace std;

int main(){
    char arr[5] = "1234";
    char *ptr = arr;
    // cout << arr << endl; // Output-> 1234
    // cout << ptr << endl; // Output-> 1234
    // cout << *ptr << endl; // Output-> 1
    
    cout << (void*)arr << endl; // Print address
    cout << (void*)ptr << endl; // Print address
    cout << static_cast<void*>(arr) << endl; // Print address
    cout << static_cast<void*>(ptr) << endl; // Print address

    char name = 'a';
    // cout << &name << endl; // print random values
    // cout << (void*)&name << endl; // print address
    // char *ptr1 = &name;
    // cout << (void*)ptr1 << endl;

    return 0;
}