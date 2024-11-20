//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        vector<int>ans;
        // Your code goes here.
        int n=arr.size();
        if(n==1)return {arr[0]};
        int majority1=-1;
        int majority2=-1;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && arr[i]!=majority2)
            {
                cnt1=1;
                majority1=arr[i];
            }
            if(cnt2==0 && arr[i]!=majority1)
            {
                cnt1=1;
                majority2=arr[i];
            }
            if(arr[i]==majority1)cnt1++;
            else if(arr[i]==majority2)cnt2++;
            else 
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==majority1)cnt1++;
            if(arr[i]==majority2)cnt2++;
        }
        if(cnt1>=(n/3)+1)ans.push_back(majority1);
        if(cnt2>=(n/3)+1)ans.push_back(majority2);
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends