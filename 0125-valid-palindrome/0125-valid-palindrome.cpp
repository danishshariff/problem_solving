class Solution {
private:
bool valid(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return 1;
    }
    return 0;
}
char tolowercase(char ch){
    if((ch>='a' && ch<= 'z') || (ch>='0' && ch<='9'))
        return ch;
    return ch-'A'+'a';
}
bool checkpalindrome(string str){  
    int s = 0;
    int e = str.length() - 1;
    while (s <=e) {
        if ((str[s])!=(str[e])) {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
public:
    bool isPalindrome(string s) {
        //faltu ke character hatao
        int i=0;
        string temp="";
        for(int j=0;j<s.length();j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        //lower case me kardo
        for(int j=0;j<temp.length();j++){
            temp[j]=tolowercase(temp[j]);
        }
        return checkpalindrome(temp);
    }
};