void nStarTriangle(int n) {
    int row, col;
    for(row=1;row<=n;row++)
    {
        for(col=1;col<=row;col++)
        {
            cout << "*";
        }

        cout << endl;
    }

    for(row=n-1;row>=1;row--)
    {
        for(col=1;col<=row;col++)
        {
            cout << "*";
        }

        cout << endl;
    }
}