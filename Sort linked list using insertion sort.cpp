#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node *next;

	node(int d)
	{
		next = NULL;
		data = d;
	}
};

void insertAtTail(node *&head,int data)
{
	if(head == NULL)
	{
		head = new node(data);
		return;
	}
	node *t = head;
	while(t->next!=NULL)
	{
		t = t->next;
	}
	t->next = new node(data);
	return;
}

void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}

void sorting(node *&head)
{
	node *current_ptr=head;
	node *insert_ptr=head;
	current_ptr=head->next;
	while(current_ptr!=NULL)
	{
		insert_ptr=head;
		while(insert_ptr!=current_ptr)
		{
		if(insert_ptr->data >= current_ptr->data)
		{
			int temp=current_ptr->data;
			current_ptr->data=insert_ptr->data;
			insert_ptr->data=temp;
		}
		else
		{
			insert_ptr=insert_ptr->next;
		}
		}
		current_ptr=current_ptr->next;
	}
}

int main()
{
	int n;
	cin>>n;
	int data;
	node *head = NULL;
	for(int i = 0;i<n;i++)
	{
		cin>>data;
		insertAtTail(head,data);
	}
	sorting(head);
	print(head);
	return 0;
}