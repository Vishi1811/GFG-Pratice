//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n = intervals.size();
        if (n <= 1) return 0;
    
        // Sort intervals by start time, and by end time if start times are the same
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
    
        int cnt = 0;  // Count of intervals to remove
        int prevEnd = intervals[0][1];
    
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlap: Remove the interval with the larger end time
                cnt++;
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                // No overlap
                prevEnd = intervals[i][1];
            }
        }
    
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends