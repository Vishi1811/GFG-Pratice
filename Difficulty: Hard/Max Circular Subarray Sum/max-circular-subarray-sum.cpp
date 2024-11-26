//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int kadaneMax(const vector<int> &arr) {
        int max_sum = INT_MIN, current_sum = 0;
        for (int num : arr) {
            current_sum = max(num, current_sum + num);
            max_sum = max(max_sum, current_sum);
        }
       return max_sum;
    }
    int kadaneMin(const vector<int> &arr) {
        int min_sum = INT_MAX, current_sum = 0;
        for (int num : arr) {
            current_sum = min(num, current_sum + num);
            min_sum = min(min_sum, current_sum);
        }
        return min_sum;
    }
  
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n = arr.size();
        // Find the maximum subarray sum (Kadane's Algorithm)
        int max_normal = kadaneMax(arr);
        //  Find the total sum of the array
        int total_sum = 0;
        for (int num : arr) total_sum += num;
    
        // Find the minimum subarray sum (Kadane's Algorithm on -arr)
        int min_sum = kadaneMin(arr);
    
        // Calculate circular subarray sum
        int max_circular = total_sum - min_sum;
        // Handle the case when all elements are negative
        if (max_circular == 0) return max_normal;
        return max(max_normal, max_circular);
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
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends