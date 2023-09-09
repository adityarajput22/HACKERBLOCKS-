#include<iostream>
#include<cmath>
using namespace std;
void multiply(int arr[1000],int &noofplacestoiterate,int nojissemulkarnahai){
	int carry=0;
	int j;
	for(j=0;j<=noofplacestoiterate-1;j++){
		int prod=arr[j]*nojissemulkarnahai+carry;
		arr[j]=prod%10;
		carry=prod/10;
	}

	while(carry>0){
		arr[j]=carry%10;
		noofplacestoiterate++;
		j++;
		carry=carry/10;

	}
}
void factorial(int n){
	int arr[1000];
	arr[0]=1;
	int noofplacestoiterate=1;
	for(int i=1;i<=n;i++){
		multiply(arr,noofplacestoiterate,i);

	}

	for(int j=noofplacestoiterate-1;j>=0;j--){
		cout<<arr[j];

	}
	cout<<endl;

}
int main(){
	int n;
	cin>>n;
	factorial(n);

	return 0;
}