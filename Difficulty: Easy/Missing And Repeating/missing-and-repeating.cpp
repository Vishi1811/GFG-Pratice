class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long sa=0,sn=0;
        for(auto it :arr)
        {
            sa+=(long long)it;
        }
        sn= n*(n+1)/2;
        long long s2a=0,s2n=0;
        for(auto it:arr)
        {
            s2a+=(long long)it * (long long)it;
        }
        s2n= n*(n+1)*(2*n+1)/6;
        long long val1=sn-sa;
        long long val2=s2n-s2a;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=val2-x;
        return{(int)y,(int)x};
        
    }
};