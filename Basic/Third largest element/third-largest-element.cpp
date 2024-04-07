//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int thirdLargest(int a[], int n)
    {
  
        int Fmax=0;
        int smax=INT_MIN,tmax=INT_MIN;

        if(n<3)
           {
               return -1;
           }
        for(int i=0;i<n;i++)
        {
            if(a[i]>Fmax)
            {
                tmax=smax;
                smax=Fmax;
                Fmax=a[i];
            }
            else if(a[i]>smax)
            {
                tmax=smax;
                smax=a[i];
            }
            else if(a[i]>tmax)
            {
                tmax=a[i];
            }
        }
        return tmax;
    }


};

//{ Driver Code Starts.
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution obj;
	    cout<<obj.thirdLargest(a,n)<<endl;
    }
}   
// } Driver Code Ends