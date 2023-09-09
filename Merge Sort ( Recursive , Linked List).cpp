#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*next;
	node(int d){
		next=NULL;
		data=d;

	}

};
void printll(node*&head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
void insertattail(node*&head,node*&tail,int data){
	// if ll is empty
	if(head==NULL and tail==NULL){
		node*n=new node(data);
		head=n;
		tail=n;
	}
	else{
		node*n=new node(data);
		tail->next=n;
		tail=n;


	}
}
node* midpointofll(node*head){//5

	node*slow=head;
	node*fast=head->next; //even ka first
	// node*fast=head;//even ka 2nd

	while(fast!=NULL and fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

node*mergetwosortedll(node*head1,node*head2){
	// if l1 is empty
	if(head1==NULL){
		return head2;
	}
	// / if l1 is empty
	if(head2==NULL){
		return head1;
	}
	node*newhead=NULL;
	if(head1->data<head2->data){
		newhead=head1;
		newhead->next=mergetwosortedll(head1->next,head2);
		// return newhead;
	}
	else{
		newhead=head2;
		newhead->next=mergetwosortedll(head1,head2->next);
		// return newhead;

	}
	return newhead;
}
node* mergesort(node*head){//5
	// base case
	
	if(head==NULL||head->next==NULL){
		return head;
	}




	// rec case
	// step 1 find mid;
	
	node*mid=midpointofll(head);//5 ka address
	node*temp=mid->next;//NULL
	mid->next=NULL;
	node*n=mergesort(head); //5
	node*m=mergesort(temp);//NULL     0 2 7
	return mergetwosortedll(n,m);//0 1 2 3 5 6 7

}


int main(){
	// 3-->5-->1--> null

	node*head=NULL;//-->adrees of the ist node of the ll
	node*tail=NULL;//-->adrees of the last node of the ll
	
	int n;
	cin>>n;//7
	for (int i = 0; i <n; ++i)
	{
		int data;
		cin>>data;//  
		insertattail(head,tail,data);
	}
	node*newhead=mergesort(head);

	// node*newllhead=mergetwosortedll(head1,head2);
	 printll(newhead);


	



	return 0;
}