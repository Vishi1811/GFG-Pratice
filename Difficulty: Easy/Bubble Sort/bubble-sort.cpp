//{ Driver Code Starts
// Initial Template for C++

// C program for implementation of Bubble sort
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// swapping the elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Your code here
        if (n == 1) return;

        int didSwap = 0;
        for (int j = 0; j <= n - 2; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
    
        // if no swapping happens.
        if (didSwap == 0) return;
    
        //Range reduced after recursion:
        bubbleSort(arr, n - 1);
   }
};


//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[1000], n, T, i;

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;

        ob.bubbleSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends