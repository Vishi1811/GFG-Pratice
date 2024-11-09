//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        string firstNum, secondNum;
        sort(arr.begin(), arr.end());
        for (int index = 0; index < arr.size(); index++) 
        {
            if (index % 2 == 0) 
                firstNum += to_string(arr[index]);
            else 
                secondNum += to_string(arr[index]);
        }
        reverse(firstNum.begin(), firstNum.end());
        reverse(secondNum.begin(), secondNum.end());
        
        string result;
        int idx1 = 0, idx2 = 0, carryOver = 0;
        
        while (idx1 < firstNum.size() || idx2 < secondNum.size()) 
        {
            int currentSum = carryOver;
            if (idx1 < firstNum.size()) currentSum += firstNum[idx1++] - '0';
            if (idx2 < secondNum.size()) currentSum += secondNum[idx2++] - '0';
        
            carryOver = currentSum / 10;
            currentSum %= 10;
            result += to_string(currentSum);
        }
        result += to_string(carryOver);
        
        while (result.back() == '0') 
            result.pop_back();
            
        reverse(result.begin(), result.end());
        return result;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends