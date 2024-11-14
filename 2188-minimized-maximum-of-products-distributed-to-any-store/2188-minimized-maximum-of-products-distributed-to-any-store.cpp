class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1; 
        int right = *std::max_element(quantities.begin(), quantities.end());  
        
        
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int requiredStores = 0;

           
            for (int i=0;i<quantities.size();i++) {
                requiredStores += (quantities[i] + mid - 1) / mid; 
            }

           
            if (requiredStores <= n) {
                result = mid; 
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }

        return result;
    }
};