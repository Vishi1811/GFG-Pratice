//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int max_product=INT_MIN;
        int prefix_product=1;
        int suffix_product=1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(prefix_product==0)prefix_product=1;
            if(suffix_product==0)suffix_product=1;
            prefix_product=prefix_product*arr[i];
            suffix_product=suffix_product*arr[n-i-1];
            max_product=max(max_product,max(prefix_product,suffix_product));
        }
        return max_product;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends