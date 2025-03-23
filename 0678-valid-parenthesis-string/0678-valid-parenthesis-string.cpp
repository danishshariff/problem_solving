class Solution {
public:

 // 3 ways 1-stack - runs
 //        2-recursion - TLE
 //        3-max min greedy
    // 2) bool validparen(string s, int ind, int cnt){
    //     if(cnt<0) return false;
    //     if(ind==s.length()) return (cnt==0);
    //     if(s[ind]=='('){
    //         return validparen(s,ind+1,cnt+1);
    //     }
    //     else if(s[ind]==')'){
    //         return validparen(s,ind+1,cnt-1);

    //     }
    //     else if(s[ind]=='*'){
    //         return validparen(s,ind+1,cnt+1) || 
    //                 validparen(s,ind+1,cnt-1) ||
    //                 validparen(s,ind+1,cnt);
    //     }
    //     return false;
       
    // }
    bool checkValidString(string s) {
        //1) stack<int> brack,star;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='('){
        //         brack.push(i);
        //     }
        //     else if(s[i]=='*'){
        //         star.push(i);
        //     }
        //     else{
        //         if(!brack.empty()){
        //             brack.pop();
        //         }
        //         else if(!star.empty()){
        //             star.pop();
        //         }
        //         else{
        //             return false;
        //         }
        //     }
        // }
        // while(!brack.empty() && !star.empty()){
        //     if (brack.top() < star.top()) {
        //         brack.pop();
        //         star.pop();
        //     } else {
        //         return false;
        //     }
        // }
        
        // return brack.empty();


    //   2)  int ind=0;
    //     int cnt=0;
    //    return validparen(s,ind,cnt);

    //3
    int mini=0;
    int maxi=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            mini++;
            maxi++;

        }
        else if(s[i]==')'){
            mini--;
            maxi--;
        }
        else{
            mini--;
            maxi++;
        }
        if(mini<0) mini=0;
        if(maxi<0) return false;
    }
    return (mini==0);
    }
    
};