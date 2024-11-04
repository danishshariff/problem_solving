class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int i=0;
        int n=word.size();
        while(i<n){
           char c=word[i];
           int cnt =0;
           while(i<n && cnt<9 && word[i]==c){
            i++;
            cnt++;
           }
           comp+=to_string(cnt)+c;
        }
        return comp;
    }
};