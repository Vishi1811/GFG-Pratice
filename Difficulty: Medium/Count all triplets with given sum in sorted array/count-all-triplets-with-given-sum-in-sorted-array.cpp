//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
       int n=arr.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            int low=i+1,high=n-1;
            while(low<high)
            {
                if(arr[i]+arr[low]+arr[high]==target)
                {
                    int ele1=arr[low],ele2=arr[high];
                    int cnt1=0,cnt2=0;
                    
                    //handling duplicates of current value low
                    while(low<=high && arr[low]==ele1)
                    {
                        low++;
                        cnt1++;
                    }
                    
                    //hacndling duplicates of current value high
                    while(low<=high && arr[high]==ele2)
                    {
                        high--;
                        cnt2++;
                    }
                    
                    if(ele1==ele2)
                         ans+=(cnt1*(cnt1-1))/2;
                    else ans+=(cnt1*cnt2);
                }
                else if(arr[i]+arr[low]+arr[high]<target)
                    low++;
                else high--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends