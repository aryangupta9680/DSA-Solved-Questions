void alphaTriangle(int n) {
    int row, col;
    for(row=1;row<=n;row++)
    {
        for(col=1;col<=row;col++)
        {
            char name = 'A' + n - col;
            cout << name << " ";
        }

        cout << endl;
    }
}