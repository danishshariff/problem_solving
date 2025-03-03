class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextsmall(n, n);  
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                nextsmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nextsmall;
    }

    vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevsmall(n, -1);  
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                prevsmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return prevsmall;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> nexts = nse(arr);
        vector<int> prevs = pse(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevs[i];
            long long right = nexts[i] - i;
            total = (total + ((left * right) % mod * arr[i]) % mod) % mod;
        }

        return total;
    }
};
    // int sumSubarrayMins(vector<int>& arr) {
    //     int sum=0;
    //     int n=arr.size();
    //     int mod=1e9+7;
    //     // for(int i=0;i<n;i++){
    //     //     int mini=arr[i];
    //     //     for(int j=i;j<n;j++){
    //     //         mini=min(arr[j],mini);
    //     //         sum+=mini%mod;
    //     //     }
    //     // }
    //     // return sum;
        