//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        
        sort(arr.begin(), arr.end());
        
        if(arr.size() == 1) return {};
        
        int closestSum = INT_MAX;
        int maxAbsDiff = INT_MIN;
        vector<int> result;
        
        while(start < end){
            int sum = arr[start] + arr[end];
            int diff = abs(sum - target);
            
            if(diff < closestSum || (diff == closestSum && abs(arr[end] - arr[start]) > maxAbsDiff)){
                closestSum = diff;
                maxAbsDiff = abs(arr[end] - arr[start]);
                result = {arr[start], arr[end]};
            }
            
            if(sum < target){
                start++;
            }
            else if(sum > target){
                end--;
            }
            else{
                return result;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends