//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
      void leftBoundary(Node* node,vector<int> &ans){
        if(node==NULL)  return;
        ans.push_back(node->data);
        if(node->left == NULL)  return;
        node=node->left;
        while(true){
            if(node->left == NULL && node->right == NULL){
                return;
            }
            ans.push_back(node->data);
            if(node->left)  node=node->left;
            else    node=node->right;
        }
    }
    
    void addLeaves(Node* root,vector<int> &ans){
        if(root == NULL)    return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        if(root->left)  addLeaves(root->left,ans);
        if(root->right) addLeaves(root->right,ans);
    }
    
    void rightBoundary(Node* node,vector<int> &ans){
        if(node==NULL || node->right==NULL)  return;
        node=node->right;
        stack<int> s;
        while(true){
            if(node->left==NULL && node->right==NULL)
                break;
            s.push(node->data);
            if(node->right) node=node->right;
            else    node=node->left;
            
        }
        while(!s.empty()){
            int top=s.top();
            s.pop();
            ans.push_back(top);
        }
    }
   vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        leftBoundary(root,ans);
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
        rightBoundary(root,ans);
        
        return ans;
        
        
    }
    

};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends