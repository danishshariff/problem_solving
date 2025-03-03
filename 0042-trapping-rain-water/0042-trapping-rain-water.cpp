class Solution {
public:
    // vector<int> prefix(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> prefix(n);
    //     prefix[0] = height[0]; 
        
    //     for (int i = 1; i < n; i++) {
    //         prefix[i] = max(prefix[i - 1], height[i]);
    //     }
    //     return prefix;
    // }

    // vector<int> suffix(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> suffix(n);
    //     suffix[n - 1] = height[n - 1];  
        
    //     for (int i = n - 2; i >= 0; i--) {
    //         suffix[i] = max(suffix[i + 1], height[i]);
    //     }
    //     return suffix;
    // }

    int trap(vector<int>& height) {
    //     if (height.empty()) return 0;  
    //     int n = height.size();
    //     vector<int> leftMax = prefix(height);
    //     vector<int> rightMax = suffix(height);
    //     int total = 0;

    //     for (int i = 0; i < n; i++) {
    //         total += min(leftMax[i], rightMax[i]) - height[i];
    //     }
    //     return total;
        int total=0;
        int n=height.size();
        int lmax=0;
        int rmax=0;
        int l=0;
        int r=n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]){
                    total+=(lmax-height[l]);
                }
                else{
                    lmax=height[l];
                }
                l=l+1;
            }
            else{
                if(rmax>height[r]){
                    total+=(rmax-height[r]);
                }
                else{
                    rmax=height[r];
                }
                r=r-1;
            }
        }
        return total;
          
    }
};