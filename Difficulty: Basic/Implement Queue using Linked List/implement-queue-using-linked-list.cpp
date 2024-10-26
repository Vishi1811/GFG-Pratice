//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    }

// } Driver Code Ends


/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        QueueNode *n=new QueueNode(x);
         if (rear == NULL) front = rear = n;
         else 
        {
            rear->next = n;
            rear = n;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code
        if (front == NULL) // If queue is empty, return -1
        return -1;

        int x = front->data; // Get the front data
        QueueNode *temp = front; // Temporarily store the front node
        front = front->next; // Move front to the next node
    
        // If front becomes NULL, set rear to NULL as well (queue is empty)
        if (front == NULL) 
            rear = NULL;
    
        delete temp; // Delete the previous front node
        return x;
}
