#include<iostream>
#include<cmath>
using namespace std;
int lef[1000000];
int rig[1000000];
int arr[1000000];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for (int i = 0; i <n; ++i)
		{
			cin>>arr[i];
		}
		lef[0]=arr[0];
		for(int i=1;i<n;i++){
			lef[i]=max(lef[i-1],arr[i]);

		}
		rig[n-1]=arr[n-1];
		for(int i=n-2;i>=0;i--){
			rig[i]=max(rig[i+1],arr[i]);

		}

		int tw=0;
		for(int i=0;i<n;i++){
			tw=tw+min(lef[i],rig[i])-arr[i];

		}
		cout<<tw<<endl;		
	}
	return 0;
}