void nBinaryTriangle(int n) {
    int row, col;
    for(row=1;row<=n;row++)
    {
        for(col=row;col>=1;col--)
        {
            cout << col%2 << " ";
        }

        cout << endl;
    }
}