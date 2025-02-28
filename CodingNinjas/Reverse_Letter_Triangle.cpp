void nLetterTriangle(int n)
{
    int row, col;
    for (row = n; row >= 1; row--)
    {
        for (col = 1; col <= row; col++)
        {
            char name = 'A' + col - 1;
            cout << name << " ";
        }

        cout << endl;
    }
}