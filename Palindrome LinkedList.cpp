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

void printll(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" "<<endl;
        head = head->next;
    }
    cout<<endl;
}

bool isPalin(node* head)
{


	node* slow = head;


	stack<int> s;


	while (slow != NULL) {
		s.push(slow->data);


		slow = slow->next;
	}


	while (head != NULL) {


		int i = s.top();


		s.pop();

		if (head->data != i) {
			return false;
		}

		head = head->next;
	}

	return true;
}

int main()
{
    node* head = NULL;
    node* tail = NULL;

    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int data;
        cin>>data;
        insertattail(head,tail,data);
    }

    int result = isPalin(head);

	if (result == 1)
		cout << "true\n";
	else
		cout << "false\n";

    return 0;
}