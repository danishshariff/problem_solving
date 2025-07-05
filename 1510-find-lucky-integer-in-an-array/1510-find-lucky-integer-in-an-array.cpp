class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]]++;
        }

        int result = -1;
        for (auto& it : mpp) {
            if (it.first == it.second) {
                result = max(result, it.first);
            }
        }

        return result;
    }
};
