//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node * reverseList(Node *head)
    {
        if(head==NULL)return head;
        Node *prev=NULL,*curr=head,*t=NULL;
        while(curr)
        {
            t=curr;
            curr=curr->next;
            t->next=prev;
            prev=t;
        }
        return prev;
        
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(head==NULL)return head;
        head=reverseList(head);
        Node *t=head;
        int  carry=1;
        while(t)
        {
            if(t->data+carry>9)
            {
                t->data=0;
                carry=1;
            }
            else {
                t->data+=carry;
                carry=0;
                break;
            }
            t=t->next;
        }
        if(carry==1)
        {
            head=reverseList(head);
            Node *n=new Node (1);
            n->next=head;
            head=n;
        }
        else head=reverseList(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends