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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high)
        {
            int p=partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int p=arr[low];
       int i=low,j=high;
       while (i < j)
       {
        // Find an element greater than or equal to the pivot from the left
            while (arr[i] <= p && i <= high)
            {
                i++;
            }
            // Find an element less than or equal to the pivot from the right
            while (arr[j] > p && j >= low)
            {
                j--;
            }
            // Swap elements if indices haven't crossed
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
        }

    // Place the pivot in the correct position
        swap(arr[low], arr[j]);
        return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends