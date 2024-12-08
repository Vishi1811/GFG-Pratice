//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<int>>ans;
        int start=arr[0][0];
        int end=arr[0][1];
        for(int i=1;i<n;i++)
        {
            
                if(arr[i][0]<=end)
                {
                    end=max(end,arr[i][1]);
                }
                else
                {
                    ans.push_back({start,end});
                    start=arr[i][0];
                    end=arr[i][1];
                }
            
        }
        ans.push_back({start,end});
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends