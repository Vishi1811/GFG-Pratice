//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
        vector<double> res;
        
        for (auto it: arr) {
            maxHeap.push(it);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            if (minHeap.size() < maxHeap.size()) {
                res.push_back(maxHeap.top());
            } else {
                double sum = (double)(maxHeap.top() + minHeap.top()) / 2.0;
                res.push_back(sum);
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends