//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          int n = val.size();
        vector<pair<double, int>> ratio(n);
    
        // Calculate value-to-weight ratio for each item
        for (int i = 0; i < n; i++) {
            ratio[i] = make_pair((double)val[i] / wt[i], i);
        }
    
        // Sort items based on value-to-weight ratio in descending order
        sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());
    
        double totalValue = 0.0;
        int remainingCapacity = capacity;
    
        // Fill the knapsack
        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;
            if (wt[idx] <= remainingCapacity) {
                // Take the whole item
                totalValue += val[idx];
                remainingCapacity -= wt[idx];
            } else {
                // Take a fraction of the item
                totalValue += ratio[i].first * remainingCapacity;
                break;
            }
        }
    
        // Round the result to 6 decimal places
        return round(totalValue * 1e6) / 1e6;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends