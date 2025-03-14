class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end()), mid;
        long long totalCandies = accumulate(candies.begin(), candies.end(), 0LL);
        
        if (totalCandies < k) {
            return 0; 
        }
        while (left < right) {
            mid = (left + right + 1) / 2;
            long long totalPiles = 0;
            
            for (int candy : candies) {
                totalPiles += candy / mid;
            }
            
            if (totalPiles >= k) {
                left = mid; 
            } else {
                right = mid - 1;  
            }
        }
        
        return left;
    }
};
