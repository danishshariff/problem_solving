class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // set<vector<int>> st;
        sort(nums.begin(), nums.end());

        // for (int i = 0; i < n - 2; i++) {
        //     for (int j = i + 1; j < n - 1; j++) {
        //         for (int k = j + 1; k < n; k++) {
        //             int sum = nums[i] + nums[j] + nums[k];
        //             if (sum == 0) {
        //                 vector<int> triplet = {nums[i], nums[j], nums[k]};
        //                 sort(triplet.begin(), triplet.end());
        //                 st.insert(triplet);
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     set<int> hashset;
        //     for(int j=i+1;j<n;j++){
        //         int third=-(nums[i]+nums[j]);
        //         if(hashset.find(third)!=hashset.end()){
        //             vector<int> temp={nums[i],nums[j],third};
        //             st.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }

        vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
 
        if (i != 0 && nums[i] == nums[i - 1]) continue;

    
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;

       
    }
};
