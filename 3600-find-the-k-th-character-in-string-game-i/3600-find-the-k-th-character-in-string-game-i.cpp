class Solution {
public:
    char kthCharacter(int k) {
        string newst="a";
        while(newst.length()<k){
            string finals="";
            for(char i:newst){
                finals+=(i+1);
            }
            newst.append(finals);
        }
        return newst[k-1];

    }
};