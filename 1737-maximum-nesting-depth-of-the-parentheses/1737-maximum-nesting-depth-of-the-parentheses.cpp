class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int count=0;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count+=1;
            }
            else if(s[i]==')'){
                count-=1;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};