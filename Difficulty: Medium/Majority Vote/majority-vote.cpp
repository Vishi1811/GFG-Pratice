//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int cnt1=0,cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=el2)
            {
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1)
            {
                cnt2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1)cnt1++;
            else if(nums[i]==el2)cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
            
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el1)cnt1++;
            if(nums[i]==el2)cnt2++;
        }
        if(cnt1>=(n/3)+1)ans.push_back(el1);
        if(cnt2>=(n/3)+1)ans.push_back(el2);
        if(cnt1<(n/3)+1 && cnt2<(n/3)+1)ans.push_back(-1);
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
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends