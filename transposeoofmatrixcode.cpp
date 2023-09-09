#include<iostream>
using namespace std;

int main () 
{	
	// for transpose both row and column are same
	int n;
	cin>>n;
	int arr[100][100];
	int transpose[100][100];

	// taking input
	for(int i = 0;i<=n-1;i++)
		for(int j = 0;j<=n-1;j++)
			cin>>arr[i][j];
	
	// storing in transpose matrix
	for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
		{
            transpose[j][i] = arr[i][j];
      	}
	for(int i = 0;i<=n-1;i++)
	{
		for(int j = 0;j<=n-1;j++)
			cout<<transpose[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}