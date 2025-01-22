//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
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

class Solution {
  public:
     Node* rev(Node* num) {
        if (!num || !num->next) {
            return num;
        }
        Node* reverse = rev(num->next);
        num->next->next = num;
        num->next = NULL;
        return reverse;
    }
    
    
    Node* trimzeros(Node* num){
    while(num!=nullptr && num->data==0)
    {    
            num=num->next;
        
        
        }
        return num;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // Reverse both input lists
        Node* temp1 = rev(num1);
        Node* temp2 = rev(num2);
        
        Node *res = nullptr, *curr = nullptr;
        int carry = 0;
        trimzeros(num1);
        trimzeros(num2);
        // Loop until both lists are exhausted and there is no carry
        while (temp1 != nullptr || temp2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (temp1 != nullptr) {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if (temp2 != nullptr) {
                sum += temp2->data;
                temp2 = temp2->next;
            }
            
            // Create a new node with the digit value
            Node* sumed = new Node(sum % 10);
            carry = sum / 10;
            
            if (res == nullptr) {
                // Initialize the result list
                res = sumed;
                curr = sumed;
            } else {
                // Append the new node to the result list
                curr->next = sumed;
                curr = curr->next;
            }
        }
        Node* final=rev(res);
        return   trimzeros(final);
        // Reverse the resultant list to get the final sum
       
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends