//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    public:
    void dfs(unordered_map<int, int> &vis, vector<int> adj[], int v){
        vis[v] = 1;
        // cout<<v<<endl;
        for(auto i: adj[v]){
            if(!vis[i]){
                dfs(vis, adj, i);
            }
        }
    }
    int isCircle(vector<string> A)
    {
        // code here
        vector<int> adj[26];
        unordered_map<int, int> vis, pvis;
        int indeg[26] = {0}, outdeg[26] = {0};
        for(int i = 0; i < A.size(); i++){
            int n = A[i].length();
            int u = A[i][0]-'a';
            int v = A[i][n-1]-'a';
            adj[u].push_back(v);
            vis[u]=0;
            vis[v]=0;
            pvis[u]=1;
            pvis[v]=1;
            indeg[v]++;
            outdeg[u]++;
        }
        for(int i= 0; i < 26; i++){
            if(indeg[i]!=outdeg[i]) return 0;
        }
        int s = A[0][0]-'a';
        
        dfs(vis, adj, s);
        for(auto it: vis){
            if(it.second==0 ){
                return 0;
            }
        }
            
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends