//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node *t1=head1,*t2=head2;
    Node *head=NULL;
    Node *curr=head;
    while(t1!=NULL && t2!=NULL)
    {
        int x;
        if(t1->data<t2->data)
        {
            x=t1->data;
            t1=t1->next;
        }
        else if(t1->data>t2->data)
        {
            x=t2->data;
            t2=t2->next;
        }
        else
        {
            x=t1->data;
            t1=t1->next;
        }
        Node *n=new Node(x);
        if(head==NULL)
        {
            head=n;
            curr=n;
        }
        else
        {
            curr->next=n;
            curr=n;
        }
    }
    while(t1!=NULL)
    {
        int x=t1->data;
        t1=t1->next;
        Node *n=new Node(x);
        if(head==NULL)
        {
            head=n;
            curr=n;
        }
        else
        {
            curr->next=n;
            curr=n;
        }
    }
    while(t2!=NULL)
    {
        int x=t2->data;
        t2=t2->next;
        Node *n=new Node(x);
        if(head==NULL)
        {
            head=n;
            curr=n;
        }
        else
        {
            curr->next=n;
            curr=n;
        }
        
    }
    return head;
    
}  