class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // sort(nums.begin(),nums.end());
        // int sum=0;
        // int count=0;
        // int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         sum=0;
    //         for(int j=i+1;j<n;j++){
    //             sum=nums[i]+nums[j];
    //             if(lower<=sum && sum<=upper){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }

    //  int left = 0;
    //     int right = 1;
        
    //     
    //     while (left < n - 1) {
    //         
    //         right = left + 1;
    //         while (right < n) {
    //             int sum = nums[left] + nums[right];
    //             if (lower <= sum && sum <= upper) {
    //                 count++;
    //             } 
    //             right++;
    //         }
    //         left++;
    //     }
        
    //     return count;
    // }

    // std::map<int, int> freqMap;
    //     long long count = 0;

        
    //     for (int i = 0; i < nums.size(); i++) {
    //         int current = nums[i];

            
    //         int minVal = lower - current;
    //         int maxVal = upper - current;

            
    //         auto itLow = freqMap.lower_bound(minVal);
    //         auto itHigh = freqMap.upper_bound(maxVal);

    //         for (auto it = itLow; it != itHigh; ++it) {
    //             count += it->second; 
    //         }

          
    //         freqMap[current]++;
    //     }

    //     return count;
    // }

    std::sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        // Iterate through each element as the first element in the pair
        for (int i = 0; i < n - 1; i++) {
            int left = i + 1; // Start checking pairs from the next element
            int min_j = lower - nums[i];
            int max_j = upper - nums[i];

            // Find the smallest index where nums[left] >= min_j
            int start = std::lower_bound(nums.begin() + left, nums.end(), min_j) - nums.begin();

            // Find the largest index where nums[right] <= max_j
            int end = std::upper_bound(nums.begin() + left, nums.end(), max_j) - nums.begin() - 1;

            // Add the count of elements in range [start, end]
            if (start <= end) {
                count += (end - start + 1);
            }
        }

        return count;
    }
};