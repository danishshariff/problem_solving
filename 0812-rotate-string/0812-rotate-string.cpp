class Solution {
public:
    bool rotateString(string s, string goal) {
     int n=s.length();
     if(s==goal) return true;
    if(n!=goal.length()) return false;
    for(int k=1;k<n;k++){
     string st=s;
     reverse(st.begin(),st.begin()+k);
     reverse(st.begin()+k,st.end());
     reverse(st.begin(),st.end());
     if(st==goal) return true;
    }
     return false;
    }
};