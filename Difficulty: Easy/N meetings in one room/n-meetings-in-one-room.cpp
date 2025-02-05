//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
     struct data{
        int start;
        int end;
    };
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comp(const data& a, const data& b) {
        return a.end < b.end;
    }
   
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code h
        int n=start.size();
        data arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i].start=start[i];
            arr[i].end=end[i];
        }
        sort(arr,arr+n,comp);
        int cnt=1;
        int freetime=arr[0].end;
        for(int i=1;i<n;i++)
        {
            if(arr[i].start>freetime)
            {
                cnt++;
                freetime=arr[i].end;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends