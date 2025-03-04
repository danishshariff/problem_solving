// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int sum=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int largest=nums[i];
//             int smallest=nums[i];
//             for(int j=i+1;j<n;j++){
//                 largest=max(largest,nums[j]);
//                 smallest=min(smallest,nums[j]);
//                 sum+=(largest-smallest);
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr) {
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

    vector<int> prevSmaller(vector<int>& arr) {
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

    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextgreater(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                nextgreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nextgreater;
    }

    vector<int> prevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevgreater(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                prevgreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return prevgreater;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nexts = nextSmaller(nums);
        vector<int> prevs = prevSmaller(nums);
        vector<int> nextg = nextGreater(nums);
        vector<int> prevg = prevGreater(nums);

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - prevs[i];
            long long rightMin = nexts[i] - i;
            minSum += (leftMin * rightMin * nums[i]);

            long long leftMax = i - prevg[i];
            long long rightMax = nextg[i] - i;
            maxSum += (leftMax * rightMax * nums[i]);
        }

        return maxSum - minSum;
    }
};
