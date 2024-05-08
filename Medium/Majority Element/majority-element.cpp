//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
         int count=0,m=a[0];
         for(int i=0;i<size;i++)
         {
             if(a[i]==m)
             {
                 count++;
             }
             else
             {
                 count--;
             }
             if(count==0)
             {
                 m=a[i];
                 count=1;
             }
         }
         count=0;
         for(int i=0;i<size;i++)
         {
             if(a[i]==m)
             {
                 count++;
             }
         }
         return (count>size/2)?m:-1;
    }

};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends