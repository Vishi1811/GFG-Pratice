//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int left=0,right=n-1;
        int lmax=0,rmax=0,ans=0;
        while(left<right)
        {
            if(arr[left]<arr[right])
            {
                if(lmax>arr[left])ans+=lmax-arr[left];
                else lmax=arr[left];
                left+=1;
                
            }
            else
            {
                if(rmax>arr[right])ans+=rmax-arr[right];
                else rmax=arr[right];
                right-=1;
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