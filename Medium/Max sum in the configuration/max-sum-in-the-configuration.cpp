//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    int maxsum=0;
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    int cursum=0;
    for(int i=0;i<N;i++){
        cursum+=A[i]*i;
    }
    maxsum=cursum;
    for(int i=N-1;i>0;i--){
        cursum+=sum-A[i]*N;
        maxsum=max(maxsum,cursum);
    }
    return maxsum;
//Your code here
}