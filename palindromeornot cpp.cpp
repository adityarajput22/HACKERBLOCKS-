#include <iostream>
using namespace std;
int lengthofstring(char arr[100]){
    int l=0;
    int i=0;
    while(arr[i]!='\0'){
        l=l+1;
        i=i+1;
    }
    return l;
}
bool ispalindrome(char arr[100]){
    int i=0;
    int j=lengthofstring(arr)-1;
    while(i<j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main() {
    char arr[100];
    cin.getline(arr,100);
    if(ispalindrome(arr)==true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
}
