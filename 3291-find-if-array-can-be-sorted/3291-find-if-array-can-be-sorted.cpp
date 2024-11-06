class Solution {
public:
   
    int cntsetbits(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
               
if (cntsetbits(nums[j]) == cntsetbits(nums[j + 1]) && nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
          
            if (!swapped) break;
        }


        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }


};