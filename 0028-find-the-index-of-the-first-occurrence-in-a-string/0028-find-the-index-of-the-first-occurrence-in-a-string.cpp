class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pso=haystack.find(needle);
        if(pso!=string::npos){
            return pso;

        }
        return -1;
    }
};