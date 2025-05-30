
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        for(int i=0;i<s.length();i++){
            string words="";
            if (s[i] == ' ') continue;
        while(i<s.length() && s[i]!=' '){
            words+=s[i];
            i++;
        }
        reverse(words.begin(),words.end());
        if(words.length()>0){
            if (!ans.empty()) ans += ' ';
                ans += words;
        }
        }
        return ans;
    }
};