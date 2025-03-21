class Solution {
public:
    bool checkValidString(string s) {
        stack<int> brack,star;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                brack.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(!brack.empty()){
                    brack.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!brack.empty() && !star.empty()){
            if (brack.top() < star.top()) {
                brack.pop();
                star.pop();
            } else {
                return false;
            }
        }
        
        return brack.empty();

        
    }
};