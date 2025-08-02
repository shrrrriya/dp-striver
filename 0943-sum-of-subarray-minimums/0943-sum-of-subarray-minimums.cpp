class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();

        // Next Smaller Element (NSE)
        vector<int> nse(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        // Previous Smaller or equal Element (PSE)
        vector<int> pse(n, -1);
        stack<int> st2;
        for(int i = 0; i < n; i++) {
            while(!st2.empty() && arr[st2.top()] >= arr[i]) {
                st2.pop();
            }
            if(!st2.empty()) pse[i] = st2.top();
            st2.push(i);
        }

        // Calculate result
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = ((arr[i] * left) % MOD * right) % MOD;
            sum = (sum + contrib) % MOD;
        }

        return (int)sum;
    }
};
