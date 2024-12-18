//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int findMax(vector<int>& arr)
   {
       int maxi=INT_MIN;
       for(int i=0;i<arr.size();i++)
       {
           maxi=max(maxi,arr[i]);
       }
       return maxi;
   }
   int findArraySum(vector<int>&arr)
   {
       int sum=0;
       for(int i=0;i<arr.size();i++)
       {
           sum+=arr[i];
       }
       return sum;
   }
   int studenAllocated(vector<int>&arr,int maxpages)
   {
       int st=1;
       int pages=0;
       for(int i=0;i<arr.size();i++)
       {
           if(pages+arr[i]<=maxpages)pages+=arr[i];
           else
           {
               st++;
               pages = arr[i];
           }
       }
       return st;
   }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n)return -1;
        int low=findMax(arr);
        int high=findArraySum(arr);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(studenAllocated(arr,mid)>k)
                low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends