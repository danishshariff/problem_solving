
class Solution {
public:
    bool is_prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for (int i = left; i <= right; ++i) {
            if (is_prime(i)) {
                primes.push_back(i);
            }
        }
        

        if (primes.size() < 2) {
            return {-1, -1};
        }

       
        int minDiff = INT_MAX;
        vector<int> result(2);
        
        for (size_t i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};
