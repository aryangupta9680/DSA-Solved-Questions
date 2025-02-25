void nStarDiamond(int n) {
    int row, col;
    for(row=1;row<=n;row++)
    {
        // space print
        for(col=1;col<=n-row;col++)
        {
            cout << " ";
        }

        // star print
        for(col=1;col<=2*row-1;col++)
        {
            cout << "*";
        }

        cout << endl;
    }

    for(row=n;row>=1;row--)
    {
        // space print
        for(col=1;col<=n-row;col++)
        {
            cout << " ";
        }

        // star print
        for(col=1;col<=2*row-1;col++)
        {
            cout << "*";
        }

        cout << endl;
    }
}