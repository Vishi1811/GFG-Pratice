//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
    Node* findTail(Node *h)
    {
        while(h->next)
        {
            h=h->next;
        }
        return h;
    }
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>>ans;
        Node *l=head;
        Node *r=findTail(head);
        while(l->data <r->data)
        {
            if(l->data+r->data==target){
                ans.push_back({l->data,r->data});
                l=l->next;
                r=r->prev;
            }
            else if (l->data+r->data>target) r=r->prev;
            else l=l->next;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends