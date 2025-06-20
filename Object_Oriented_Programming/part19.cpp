// Function Overloading

#include <iostream>
using namespace std;

class Area
{
public:
    int calculateArea(int r) // area of circle
    {
        return 3.14 * r * r;
    }

    int calculateArea(int length, int breadth) // area of rectangle
    {
        return length * breadth;
    }
};

int main()
{
    Area A1, A2;
    cout << A1.calculateArea(4) << endl;
    cout << A2.calculateArea(3, 4) << endl;
    return 0;
}