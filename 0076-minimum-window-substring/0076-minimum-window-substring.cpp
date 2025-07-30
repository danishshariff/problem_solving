class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int n=s.size();
        int hash[256]={0};
        int mini=1e9;
        int cnt=0;
        int startidx=-1;
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        while(r<n){
            hash[s[r]]--;
            if(hash[s[r]]>=0){
                cnt++;
            }
            while(cnt==t.size()){
                if(r-l+1<mini){
                    mini=r-l+1;
                    startidx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;

        }
        return startidx==-1? "":s.substr(startidx,mini);
    }
};