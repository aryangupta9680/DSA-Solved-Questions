void seeding(int n) {
	int row, col;
	for(row=1;row<=n;row++)
	{
		for(col=1;col<=n-(row-1);col++)
		{
			cout << "* ";
		}

		cout << endl;
	}
}