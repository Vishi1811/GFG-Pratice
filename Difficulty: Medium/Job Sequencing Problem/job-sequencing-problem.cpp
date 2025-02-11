//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
     struct Array {
        int id;
        int dl;
        int prf;
    };
    public:

    static bool comp(Array a1, Array a2) {
        return (a1.prf > a2.prf);
    }
    
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
        int n = id.size();
        
        vector<Array> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].id = id[i];
            arr[i].dl = deadline[i];
            arr[i].prf = profit[i];
        }
    
        sort(arr.begin(), arr.end(), comp);
    
        int maxdl = -1;
        for (int i = 0; i < n; i++) {
            maxdl = max(maxdl, deadline[i]);
        }
    
        vector<int> hash(maxdl + 1, -1);
        int totalProfit = 0, cnt = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dl - 1; j >= 0; j--) {  // Fix indexing
                if (hash[j] == -1) {
                    hash[j] = arr[i].id;
                    totalProfit += arr[i].prf;
                    cnt++;
                    break;  // Break after placing a job
                }
            }
        }
    
        return {cnt, totalProfit};
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends