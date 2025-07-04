class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mpp;
        for(int i=0;i<order.length();i++){
            mpp[order[i]]=i;
        }
        int i=0;
        while(i<words.size()-1){
            string firstword=words[i];
            string secondword=words[i+1];
            int j=0;
            while(j<firstword.size()&& j<secondword.size()){
                if(mpp[firstword[j]]<mpp[secondword[j]]){
                    break;
                }
                else if(mpp[firstword[j]]>mpp[secondword[j]]){
                    return false;
                }
                j++;
            }
            i++;
            if(j==secondword.size() &&firstword.size()>secondword.size()){
                return false;
            }
        }
        return true;

    }
};