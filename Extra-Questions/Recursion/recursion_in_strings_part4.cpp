#include <iostream>
using namespace std;

void lower_to_upper(string &str, int index)
{
    // Base condition
    if (index == -1)
    {
        return;
    }

    str[index] = 'A' + str[index] - 'a';

    lower_to_upper(str, index - 1);
}

int main()
{
    // lowercase to uppercase
    string str = "aryan";
    lower_to_upper(str, 4);
    cout << str << endl;

    return 0;
}