class Solution {
public:
    vector<string> stringSequence(string target) {
        string temp="";
        vector<string> res;
        for(int i=0;i<target.length();i++){
    
            temp=temp+'a';
            res.push_back(temp);
     
            while(temp[i]!=target[i]){
                temp[i]=temp[i]+1;
                res.push_back(temp);
            }
        
        }
        return res;
    }
};