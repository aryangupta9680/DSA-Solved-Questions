void nTriangle(int n)
{
	int row, col;
	for (row = 1; row <= n; row++)
	{
		for (col = 1; col <= row; col++)
		{
			cout << col << " ";
		}
		cout << endl;
	}
}