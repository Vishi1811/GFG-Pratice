//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
         Node *vowels = NULL, *consonants = NULL, *cstart = NULL;
        Node* res = NULL;
        
        while (head){
            Node* newNode = new Node(head->data); 
            if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u'){
                if (vowels == NULL){
                    vowels = newNode;
                    res = vowels;
                }
                else{
                    vowels->next = newNode;
                    vowels = vowels->next;
                }
            }
            else{
                if (consonants == NULL){
                    consonants = newNode;
                    cstart = consonants;
                }
                else{
                    consonants->next = newNode;
                    consonants = consonants->next;
                }
            }
            head = head->next;
        }
        
        if (vowels && consonants)
            vowels->next = cstart;
        
        else if (consonants)
            return cstart;
        
        return res;
    }

};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends