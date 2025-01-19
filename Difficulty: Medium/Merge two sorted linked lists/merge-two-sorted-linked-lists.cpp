//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
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
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node *dumy= new Node(-1);
        Node* curr=dumy,*l1=head1,*l2=head2;
        while(l1 && l2)
        {
            if(l1->data<l2->data)
            {
                curr->next=l1;
                while(l1->next!=NULL && l1->data==l1->next->data)
                {
                    l1=l1->next;
                }
                curr=l1;
                l1=l1->next;
                
                
                
            }
            else if(l1->data>l2->data)
            {
                curr->next=l2;
                while(l2->next!=NULL && l2->data==l2->next->data)
                {
                    l2=l2->next;
                }
                curr=l2;
                l2=l2->next;
                
            }
            else
            {
                curr->next=l1;
                curr=l1;
                l1=l1->next;
                curr->next=l2;
                curr=l2;
                l2=l2->next;
                
            }
        }
        if(l1)curr->next=l1;
        if(l2)curr->next=l2;
        return dumy->next;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends