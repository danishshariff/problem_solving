#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result; // All elements replaced by 0
        }

        int start, end, step;
        if (k > 0) {
            start = 1;
            end = k;
            step = 1;
        } else {
            start = -1;
            end = k;
            step = -1;
        }

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = start; j != end + step; j += step) {
                sum += code[(i + j + n) % n]; // Use modulo for circular indexing
            }
            result[i] = sum;
        }

        return result;
    }
};
