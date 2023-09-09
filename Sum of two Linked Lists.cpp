# include <iostream>
# include <stack>
using namespace std;

class node{
public:
    int data;
    node* next;

    // constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertattail(node* &head,node* &tail,int data)
{
    node* n = new node(data);
    if(head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
    }
}

// to add two new numbers
node* addTwoNumList(node* l1, node* l2) {
	stack<int> s1,s2;
	while(l1!=NULL){
		s1.push(l1->data);
		l1=l1->next;
	}
	while(l2!=NULL){
		s2.push(l2->data);
		l2=l2->next;
	}
	int carry=0;
	node* result=NULL;
	while(s1.empty()==false || s2.empty()==false){
		int a=0,b=0;
		if(s1.empty()==false){
			a=s1.top();s1.pop();
		}
		if(s2.empty()==false){
			b=s2.top();s2.pop();
		}
    
    int total = a + b + carry;
    node* temp = new node(total % 10);
    carry = total / 10;
    
    temp->next = result;
    result = temp;
  }
  
  if (carry != 0) {
    node* temp = new node(carry);
    temp->next = result;
    result = temp;
  }
  
  return result;
}


void printll(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    node* head1 = NULL;
    node* tail1 = NULL;
    node* head2 = NULL;
    node* tail2 = NULL;

    int n,m;
    cin>>n>>m;

    for(int i = 0;i<n;i++)
    {
        int data;
        cin>>data;
        insertattail(head1,tail1,data);
    }

    for(int i = 0;i<m;i++)
    {
        int data;
        cin>>data;
        insertattail(head2,tail2,data);
    }

    node* result = addTwoNumList(head1, head2);
    printll(result);

    return 0;
}