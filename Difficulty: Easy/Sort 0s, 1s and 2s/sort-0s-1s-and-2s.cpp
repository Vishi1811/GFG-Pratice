//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int start=-1,mid=0,end=arr.size()-1;
        while(mid<=end)
        {
            if(arr[mid]==2)
            {
                swap(arr[mid],arr[end]);
                end--;
            }
            else if(arr[mid]==0){
                start++;
                swap(arr[mid],arr[start]);
                mid++;
                
            }
            else
            {
                mid++;
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends