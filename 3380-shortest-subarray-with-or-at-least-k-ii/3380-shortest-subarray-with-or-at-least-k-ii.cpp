// class Solution {
// public:
//     int minimumSubarrayLength(vector<int>& nums, int k) {
//         int length=INT_MAX;

//         for(int i=0;i<nums.size();i++){
//             int currentor=0;
//             for(int j=i;j<nums.size();j++){
//                currentor|=nums[j];
//                if(currentor>=k){
//                 length=min(length,j-i+1);
//                 break;
//                }
//             }
//         }
//         return length==INT_MAX? -1:length;
//     }
// };


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minimum_length = INT_MAX;
        int bitwise_or = 0;
        vector<int> bits(32, 0);
        for (int left = 0, right = 0; right < nums.size(); right++) {
            bitwise_or = transform(bits, nums[right], 1);
            while (bitwise_or >= k && left <= right) {
                minimum_length = min(minimum_length, right - left + 1);
                bitwise_or = transform(bits, nums[left], -1);
                left++;
            }
        }
        return minimum_length == INT_MAX ? -1 : minimum_length;
    }

private:
    int transform(vector<int>& bits, int num, int delta) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                bits[i] += delta;
            }
            if (bits[i] > 0) {
                result += (1 << i);
            }
        }
        return result;
    }
};



 
