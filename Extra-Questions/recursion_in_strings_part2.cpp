#include <iostream>
using namespace std;

int countvowels(string str, int index)
{
    // base condition
    if (index == -1)
    {
        return 0;
    }

    // vowel hoga
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')
    {
        return 1 + countvowels(str, index - 1);
    }

    // vowel nahi hoga
    else
    {
        return countvowels(str, index - 1);
    }
}

int main()
{
    // count vowels
    // given: lowercase letters only
    string str = "rohan";
    cout << countvowels(str, 4);

    return 0;
}