//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int third=-(arr[i]+arr[j]);
                if(mpp.find(third)!=mpp.end()){
                    for(auto it: mpp[third]){
                        if(it>j){
                            ans.push_back({i,j,it});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends