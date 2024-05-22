//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(double dis, int k, vector<int>&stat){
        for(int i=1;i<stat.size();i++){
            k-=floor((stat[i]-stat[i-1])/dis);
            if(k<0) return false;
        }
        return true;
    }
    double findSmallestMaxDist(vector<int> &stat, int k) {
        // Code here
        
        // int cnt=0,n=stat.size();
        double l=0,h=1e9,ans;
        while((h-l)>=1e-6){
            double mid=(l+h)/2.0;
            // cout<<mid<<endl;
            if(check(mid,k,stat)){
                ans=mid;
                h=mid;
            }
            else{
                l=mid;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends