class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        int vowels=0;
        int consonents=0;
        string vow="aeiouAEIOU";
        for(char c:word){
            if (!isalnum(c)) return false;
            if(isalpha(c)){
                if(vow.find(c)!=vow.npos){
                    vowels++;
                }
                else{
                    consonents++;
                }
            }
        }
        if(vowels>=1 && consonents>=1){
            return true;
        }
        return false;
    }
};