# include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	int max_ele = arr[0];
	for(int i = 0;i<n;i++)
	{
		if(max_ele<arr[i])
			max_ele = arr[i];
	}
	int temp[max_ele+1] = {0};
	for(int i = 0;i<n;i++)
	{
		temp[arr[i]]++;
	}
	for(int i = 0;i<max_ele+1;i++)
	{
		while(temp[i]--)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}