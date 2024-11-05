class Solution {
public:
    int minChanges(string s) {
        int n=s.length();
       int odd_l= n%2==1;
       int cnt=0;
    //    if(s==odd_l) return -1;
       for(int i=1;i<n;i++){
        if(s[i-1]=='1' && s[i]=='1') {
            i++;
        }
        else if(s[i-1]=='0' && s[i]=='0'){
            i++;
        }
        else if(s[i-1]=='1' && s[i]=='0'){
            s[i]='1';
            i++;
            cnt++;
        }
        else if(s[i-1]=='0' && s[i]=='1'){
            s[i]='0';
            i++;
            cnt++;
        }
       }
       return cnt;
    }
};