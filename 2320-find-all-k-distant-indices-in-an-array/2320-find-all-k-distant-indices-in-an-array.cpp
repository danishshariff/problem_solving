class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        //brute
    //    int n=nums.size();
    //    vector<int> idx;
    //    vector<int> ans;

    //    for(int i=0;i<n;i++){
    //     if(nums[i]==key){
    //         idx.push_back(i);
    //     }
    //    }
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<idx.size();j++){
    //         if(abs(i-idx[j])<=k){
    //             ans.push_back(i);
    //             break;
    //         }
    //     }
    //    }
    //    return ans;


    //optimal
     int n = nums.size();
        vector<bool> marked(n, false);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; j++) {
                    marked[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (marked[i]) ans.push_back(i);
        }

        return ans;
    
    }
};