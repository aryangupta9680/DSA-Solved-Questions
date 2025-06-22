// File Handling

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // file ko open karna
    ofstream fout;
    fout.open("zoom.txt"); // create kar dega agar present nahi hai aur open kar dega

    // write kar sakta hu
    fout << "Hello India!!";
    fout.close(); // resources release kar sakta hu

    return 0;
}