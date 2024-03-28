//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
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
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends