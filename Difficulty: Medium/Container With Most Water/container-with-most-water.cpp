//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n==1 || n==0){
            return 0;
        }
        int maxWater = INT_MIN;
        int left = 0, right=n-1;
        while(left<right){
            int length = min(arr[left],arr[right]);
            int breadth = right-left;
            int currentArea = length * breadth;
            maxWater = max(currentArea, maxWater);
            if(arr[left]>arr[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxWater;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends