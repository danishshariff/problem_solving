class Solution {
public:
    // void findcomb(int ind, int target, vector<int>& arr, set<vector<int>>& ans, vector<int>& ds) {
    //     int n = arr.size();

    //     if (target == 0) {
    //         ans.insert(ds);
    //         return;
    //     }

    //     if (ind == n || target < 0) return; 
    //     ds.push_back(arr[ind]);
    //     findcomb(ind + 1, target - arr[ind], arr, ans, ds);
    //     ds.pop_back(); 

        
    //     findcomb(ind + 1, target, arr, ans, ds);
    // }

    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     set<vector<int>> ans; 
    //     vector<int> ds;
    //      sort(candidates.begin(), candidates.end());
        
    //     findcomb(0, target, candidates, ans, ds);

    //     // Convert set<vector<int>> to vector<vector<int>>
    //     return vector<vector<int>>(ans.begin(), ans.end());
    // }

    void findcomb(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        int n=arr.size();
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }
            if(arr[i]>target) break;

            ds.push_back(arr[i]);
            findcomb(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
       vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findcomb(0,target,candidates,ans,ds);
        return ans;

       }
};