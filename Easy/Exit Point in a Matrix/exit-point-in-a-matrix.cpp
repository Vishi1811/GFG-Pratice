//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
         int i = 0, j = 0;
        int d = 0;
        
        while(i < n && j < m && i >= 0 && j >= 0) {
            if(matrix[i][j] == 1) {
                matrix[i][j] = 0;
                d++;
            }
            d %= 4;
            
            switch (d) {
                case 0: j++; break;
                case 1: i++; break;
                case 2: j--; break;
                case 3: i--; break;
            }
        }
        
        switch(d) {
            case 0: return {i, j-1};
            case 1: return {i-1, j};
            case 2: return {i, j+1};
        }
        return {i+1, j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends