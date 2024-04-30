//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
   // Function to reverse a linked list.
    Node* reverseList(Node *head){
        if(!head || !head->next) return head; // If list is empty or has only one node, return head.
        
        Node* prev = nullptr; 
        Node* curr = head;
        while(curr){
            Node *next = curr->next; // Store the next node.
            curr->next = prev; // Reverse the link.
            prev = curr; // Move pointers forward.
            curr = next;
        }
        
        return prev; // Return the new head.
    }
    
    // Function to add two numbers represented by linked lists.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        Node *ans = new Node(-1); // Initialize a dummy node for the result.
        Node* ptr3 = ans; // Pointer to traverse the result list.
        int carry = 0; // Initialize carry to 0.
        
        // Reverse both input lists.
        num1 = reverseList(num1); 
        num2 = reverseList(num2);
        
        Node *ptr1 = num1, *ptr2 = num2; // Pointers to traverse the input lists.
        
        // Iterate through both lists until one of them reaches the end.
        while(ptr1 and ptr2){
            int temp = ptr1->data + ptr2->data + carry; // Calculate sum of current digits and carry.
            carry = temp / 10; // Update carry for the next iteration.
            ptr3->next = new Node(temp % 10); // Add the least significant digit to the result list.
            ptr1 = ptr1->next; // Move pointers forward.
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        
        // Handle remaining digits of num1.
        while(ptr1){
            int temp = ptr1->data + carry;
            carry = temp / 10;
            ptr3->next = new Node(temp % 10);
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        
        // Handle remaining digits of num2.
        while(ptr2){
            int temp = ptr2->data + carry;
            carry = temp / 10;
            ptr3->next = new Node(temp % 10);
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        
        // If there's a carry after the last addition, add it as a new node to the result list.
        if(carry){
            ptr3->next = new Node(carry);
        }
        
        // Reverse the result list to get the final result in the correct order.
        ans = reverseList(ans->next);
        
        // Remove any leading zeros from the result list.
        while(ans and ans->data == 0){
            ans = ans->next;
        }
        
        // Return the final result list.
        return ans == nullptr ? new Node(0) : ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends