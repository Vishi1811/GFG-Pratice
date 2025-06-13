// User function Template for C++

class Solution {
    private:
   
    bool isPossible(vector<int>&arr,int d,int k)
    {
        int cowCnt=1,lastCow=arr[0];
        for(int i=0;i<arr.size();i++){
            if(arr[i]-lastCow>=d)
            {
                cowCnt++;
                lastCow=arr[i];
            }
            if(cowCnt>=k)return true;
        }
        return false;
        
    }
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        //sort the stalls[]:
        int n=stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(stalls,mid,k))low=mid+1;
            else high=mid-1;
            
        }
        return high;
        
    }
};