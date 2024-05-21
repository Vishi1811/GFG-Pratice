//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution { 
  public: 
    int findCrossOver(vector<int>& arr, int low, int high, int x) { 
        // Base cases 
        if (arr[high] <= x) return high; 
        if (arr[low] > x) return low; 
 
        int mid = (low + high) / 2; 
 
        // Check if mid is the crossover point 
        if (arr[mid] <= x && arr[mid + 1] > x) return mid; 
        else if (arr[mid] < x) return findCrossOver(arr, mid + 1, high, x); 
        return findCrossOver(arr, low, mid - 1, x); 
    } 
 
    // Function to print K closest elements 
    vector<int> printKClosest(vector<int>& arr, int n, int k, int x) { 
        // Find the crossover point 
        int crossoverIndex = findCrossOver(arr, 0, n - 1, x); 
        int leftIndex = crossoverIndex; 
        int rightIndex = crossoverIndex + 1; 
 
        // If the element is present, move left index back 
        if (leftIndex >= 0 && arr[leftIndex] == x) leftIndex--; 
 
        vector<int> closestElements; 
        for (int i = 0; i < k; i++) { 
            // Both indices are valid 
            if (leftIndex >= 0 && rightIndex < n) { 
                int leftDiff = x - arr[leftIndex]; 
                int rightDiff = arr[rightIndex] - x; 
                // Choose the closer element 
                if (leftDiff < rightDiff) { 
                    closestElements.push_back(arr[leftIndex]); 
                    leftIndex--; 
                } else { 
                    closestElements.push_back(arr[rightIndex]); 
                    rightIndex++; 
                } 
            } else if (leftIndex >= 0) { // Only left index is valid 
                closestElements.push_back(arr[leftIndex]); 
                leftIndex--; 
            } else { // Only right index is valid 
                closestElements.push_back(arr[rightIndex]); 
                rightIndex++; 
            } 
        }  
        return closestElements; 
    } 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends