#include<iostream>
using namespace std;

int main() 
{
	int m,n;
	cin>>m>>n;
	int arr[100][100];
	for(int i = 0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
			cin>>arr[i][j];
	}

	int ele;
	cin>>ele;

	int i = 0;
	int j = n-1;//column-1

    int found = -1;
	while(i>=0 and j>=0)
	{
		if(arr[i][j] == ele)
        {
            found = 1;
            break;
        }
		else if(arr[i][j]>ele)
			j--;
		else
			i++;
	}
	
    if(found == 1)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
	return 0;
}