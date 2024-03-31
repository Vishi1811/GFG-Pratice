//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int sum=0,front_sum=0;
        if(n==1)
        {
            return n;
        }
        // else if(n==2)
        // {
        //     return -1;
        // }
        else
        {
           for(int i=0;i<n;i++)
           {
               sum=sum+a[i];
           }
        //   sum=sum-a[0];
           for(int i=0;i<n;i++)
           {
               sum=sum-a[i];
               if(sum==front_sum)
               {
                   return i+1;
               }
               front_sum=front_sum+a[i];
               
           }
           return -1;
    
        }
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends