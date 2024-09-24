//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int> freq(26);
        int n = s.length();
        for(auto &c:p) freq[c-'a']++;
        vector<int> tempCnt(26,0);
        int i=0,j=0;
        int ans = INT_MAX;
        int st = -1;
        auto check = [&]()->bool{
            for(int i=0;i<26;i++){
                if(freq[i]>tempCnt[i]) return false;
            }
            return true;
        };
        while(j<n){
            tempCnt[s[j]-'a']++;
            if(!check()) j++;
            else{
                while(check()){
                    if(j-i+1 < ans) {ans = j-i+1; st=i;}
                    tempCnt[s[i]-'a']--;
                    i++;
                }
                j++;
            }
        }
        return ans == INT_MAX ? "-1" : s.substr(st,ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends