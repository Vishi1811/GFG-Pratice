//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
         vector<int> divisors;

    // Loop to find all divisors less than sqrt(n)
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cout << i << " ";  // Print the first divisor
                if (i != n / i) {
                    divisors.push_back(n / i);  // Store the second divisor
                }
            }
        }
    
        // Print the second divisors in ascending order
        reverse(divisors.begin(), divisors.end());
        for (int div : divisors) {
            cout << div << " ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends