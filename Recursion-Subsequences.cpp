#include<iostream>
using namespace std;

void subsequence(char str[], int i, char out[],int j,int &count)
{
	// base case 
	if(str[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<" ";
		return;
	}
	count++;
	// rec case
	// without a 
	subsequence(str,i+1,out,j,count);

	// with a 
	out[j] = str[i];
	subsequence(str,i+1,out,j+1,count);
	// count++;
}

int main() 
{
	char str[100];
	cin>>str;
	char out[100];
	int cnt = 0;
	subsequence(str,0,out,0,cnt);
	cout<<endl;
	cout<<cnt+1<<endl;
	return 0;
}