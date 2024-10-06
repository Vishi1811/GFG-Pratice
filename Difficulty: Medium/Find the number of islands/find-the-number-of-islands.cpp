//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        bool isSafe(vector<vector<char>>& M, int row, int col, vector<vector<bool>>& visited, int n, int m) {
        return (row >= 0) && (row < n) && (col >= 0) && (col < m) && 
               (M[row][col] == '1' && !visited[row][col]);
    }

    void DFS(vector<vector<char>>& M, int row, int col, vector<vector<bool>>& visited, int n, int m) {
        static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
        visited[row][col] = true;
    
        for (int k = 0; k < 8; ++k) {
            if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited, n, m)) {
                DFS(M, row + rowNbr[k], col + colNbr[k], visited, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    DFS(grid, i, j, visited, n, m);
                    ++count;
                }
            }
        }
    
        return count;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends