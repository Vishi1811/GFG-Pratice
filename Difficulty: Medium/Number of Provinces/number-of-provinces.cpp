//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
    private:
        void dfs(int node,vector<vector<int>>&adjL,vector<int>&visit)
        {
            visit[node]=1;
            for(auto it:adjL[node])
            {
                if(!visit[it])
                {
                    dfs(it,adjL,visit);
                }
            }
        }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>adjL(V+1);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    adjL[i+1].push_back(j+1);
                    
                }
            }
        }
        int province=0;
        vector<int>visit(V+1);
        for(int i=1;i<=V;i++)
        {
            if(!visit[i])
            {
                province++;
                dfs(i,adjL,visit);
            }
        }
        return province;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends