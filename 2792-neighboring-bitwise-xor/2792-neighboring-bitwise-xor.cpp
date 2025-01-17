class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
          int xoor = 0;
        for (auto val : derived) {
            xoor ^= val;
        }
        return xoor == 0;
    }
    
};