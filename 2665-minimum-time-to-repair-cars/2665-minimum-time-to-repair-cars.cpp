#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
       
        long long start = LLONG_MAX;
        long long end = LLONG_MIN; 
        
        
        for (int rank : ranks) {
            end = max(end, (long long)rank);
            start = min(start, (long long)rank);
        }
        end = end * cars * cars; 
        long long ans = 0;

       
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (isCarsRepaired(mid, ranks, cars)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    bool isCarsRepaired(long long time, vector<int>& ranks, int carsToBeRepaired) {
        long long carsRepaired = 0;
        for (int rank : ranks) {
            carsRepaired += (long long)sqrt((1.0 * time) / rank);
            if (carsRepaired >= carsToBeRepaired) return true;
        }
        return false;
    }
};
