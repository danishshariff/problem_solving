class Solution {
public:
    // Make compare static so it can be used inside the lambda
    static bool compare(int a, int b, unordered_map<int, int>& freq) {
        if (freq[a] != freq[b])
            return freq[a] < freq[b];  // lower frequency first
        return a > b;                  // if same frequency, larger value later
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return compare(a, b, freq);
        });

        return nums;
    }
};