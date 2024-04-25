//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
         int ans = -1;
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(n-i < 3 || m-j < 3)
                    continue;
                int sum = 0;
                sum += mat[i][j] + mat[i][j+1] + mat[i][j+2];
                sum += mat[i+1][j+1];
                sum += mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2];
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends