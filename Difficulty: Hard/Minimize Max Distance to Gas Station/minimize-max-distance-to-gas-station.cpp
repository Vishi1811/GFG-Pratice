class Solution {
    private:
    int noOfGasRequired(vector<int>&arr,long double dist,int n)
    {
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            int gasInBetween=(arr[i+1]-arr[i])/dist;
            if(((arr[i+1]-arr[i])/dist)==gasInBetween*dist)gasInBetween--;
            cnt+=gasInBetween;
        }
        return cnt;
    }
    long double maxDiff(vector<int>&arr,int n)
    {
        long double ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, (long double)(arr[i + 1] - arr[i]));
        }
        return ans;
    }
  public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        long double low=0,high=maxDiff(arr,n);
        long double diff=1e-6;
        while(high-low > diff )
        {
            long double mid =(low+high)/2.0;
            int cnt=noOfGasRequired(arr,mid,n);
            if(cnt>k)low=mid;
            else high=mid;
        }
        return round(high * 100.0) / 100.0;
      
    
    }
};