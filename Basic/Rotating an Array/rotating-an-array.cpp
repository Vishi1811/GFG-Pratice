//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        // code here
        d=d%n;
        int s=0,e=d-1;
        while(s<=e)
        {
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
        s=d;e=n-1;
        while(s<=e)
        {
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
        s=0,e=n-1;
        while(s<=e)
        {
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends