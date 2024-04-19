//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
long long merge(long long arr[], long long l, long long mid, long long r) {
    long long inv = 0;
    long long n1 = mid - l + 1;
    long long n2 = r - mid;
    long long a[n1], b[n2];

    for (long long i = 0; i < n1; i++)
        a[i] = arr[l + i];

    for (long long i = 0; i < n2; i++)
        b[i] = arr[mid + i + 1];

    long long i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            inv += (n1 - i);
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }

    return inv;
}

long long mergeSort(long long arr[], long long l, long long r) {
    long long inv = 0;
    if (l < r) {
        long long mid = l+(r-l) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}

long long inversionCount(long long arr[], long long N) {
    return mergeSort(arr, 0, N - 1);
}

   

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends