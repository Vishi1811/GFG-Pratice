
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        int ans=0;
        map<int,int>mp;
        for(auto it :arr)
        {
            mp[it]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]]==1)return arr[i]; 
        }
        return 0;
    }
};
