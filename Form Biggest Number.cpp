#include<iostream>
# include <cmath>
using namespace std;
int digitsin(int n)
{
	int c=0;
	while(n>0){
		n=n/10;
	c++;
	}
	return c;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int m;
		cin>>m;
		int arr[1000];
		for (int i = 0; i <m; ++i)
		{
			cin>>arr[i];
		}
	for(int i=0;i<=m-2;i++){ 

	for(int j=0;j<=m-2-i;j++)
	{
		long long int no1=arr[j]*pow(10,digitsin(arr[j+1]))+arr[j+1];
		long long int no2=arr[j+1]*pow(10,digitsin(arr[j]))+arr[j];
		if(no1>no2){
			swap(arr[j],arr[j+1]);
		}
	}
}

for(int l=m-1;l>=0;l--)
{
	cout<<arr[l];

}
cout<<endl;
	}
	return 0;
}