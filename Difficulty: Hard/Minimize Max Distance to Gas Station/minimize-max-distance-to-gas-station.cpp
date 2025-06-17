class Solution {
  public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        // Min-heap with max gap after split = total gap / (number of parts)
        priority_queue<pair<long double, int>> pq;
        vector<int> howMany(n - 1, 0);

        for (int i = 0; i < n - 1; i++) {
            long double dist = arr[i + 1] - arr[i];
            pq.push({dist, i});
        }

        for (int i = 0; i < k; i++) {
            auto top = pq.top(); pq.pop();
            int idx = top.second;
            howMany[idx]++;
            long double newDist = (arr[idx + 1] - arr[idx]) / (long double)(howMany[idx] + 1);
            pq.push({newDist, idx});
        }

       long double ans = pq.top().first;

        // Round to 2 decimal places before returning
        return round(ans * 100.0) / 100.0;
    
    }
};