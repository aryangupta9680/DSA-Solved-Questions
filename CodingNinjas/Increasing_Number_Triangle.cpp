void nNumberTriangle(int n) {
    int row, col;
    int num = 1;
    for(row=1;row<=n;row++)
    {
        for(col=1;col<=row;col++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}