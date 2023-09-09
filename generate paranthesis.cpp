// generate paranthesis wala question 
#include <iostream>
using namespace std;
//generate balanced brackets using N pairs of Round brackets
void generate_brackets(char *out,int n,int idx,int open,int close)
{//base case
 if(idx==2*n)
 {
                
                cout<<out<<endl;
               // out[idx]='\0';
                return;
 }
 //recursion case
 //2 operation (i) open brackets
 if(open<n)   //yani jb mene brackket banane start kiye tb obvisouly open chota hoga 
 {
                out[idx]='(';  // index pa ( daldiya
                generate_brackets(out,n,idx+1,open+1,close);  // index ko agge badhaya and open ko bhi 
 }
 if(close<open)  // yeh question ko dekh ke comdition lgayi mene 
 {
               out[idx]=')';   // index pe ) daldiya 
               generate_brackets(out,n,idx+1,open,close+1);  // index age badha and yhape close age badhega 
 }
 return;
}
int main() {
               int n;
               cin>>n;  // taking input 
               char out[1000];
               int idx=0; // index at 0 postion 
               generate_brackets(out,n,0,0,0);  // function will call
	// your code goes here
	return 0;
}