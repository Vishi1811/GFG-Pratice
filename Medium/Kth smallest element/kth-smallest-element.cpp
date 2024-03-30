//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
 void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int l1=m-l+1,l2=r-m;
         int a[l1],b[l2];
         int k=l;
         for(int i=0;i<l1;i++)
         {
             a[i]=arr[k++];
             
         }
         int j=m+1;
         for(int i=0;i<l2;i++)
         {
             b[i]=arr[j++];
             
         }
         int index1=0,index2=0,maini=l;
         while(index1<l1 && index2<l2)
         {
             if(a[index1]<b[index2])
             {
                 arr[maini]=a[index1];
                 index1++;
                 maini++;
             }
             else
             {
                 arr[maini]=b[index2];
                 index2++;
                 maini++;
             }
             
         }
         while(index1<l1)
         {
             arr[maini]=a[index1];
                 index1++;
                 maini++;
         }
         while(index2<l2)
         {
             arr[maini]=b[index2];
                 index2++;
                 maini++;
         }
    }
    void sort(int arr[],int l,int r)
    {
         if(r>l)
         {
             int mid=l+(r-l)/2;
             sort(arr,l,mid);
             sort(arr,mid+1,r);
             merge(arr,l,mid,r);
         }
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        sort(arr,l,r);
        return arr[k-1];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends