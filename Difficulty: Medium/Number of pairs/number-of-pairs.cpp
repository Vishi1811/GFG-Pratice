//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
      sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        long long count = 0;
        
        int i = 0;
        int j = 0;
        int b1 = 0;
        int b2 = 0;
        int b4 = 0;
        
        // count brr special cases (1, 2 & 4)
        for(j=0; j<brr.size() && brr[j] < 5; j++)
        {
            if(brr[j] == 1)
            {
                b1++;
            }
            else if(brr[j] == 2)
            {
                b2++;
            }
            else if(brr[j] == 4)
            {
                b4++;
            }
        }
        
        // handle arr special cases (1, 2, 3)
        for(i=0; i<arr.size() && arr[i] < 4; i++)
        {
            if(arr[i] == 2)
            {
                count += (long long)(brr.size() - j + b1);
            }
            if(arr[i] == 3)
            {
                count += (long long)(brr.size() - j + b1 + b2 + b4);
            }
        }
        
        while(i<arr.size() && j<brr.size())
        {
            if(arr[i] < brr[j])
            {
                count += (long long)(brr.size() - j + b1);
                i++;
            }
            else
            {
                j++;
            }
        }
        
        count += (long long)(arr.size() - i) * (long long) b1;
        
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends