class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int maxlen=0;
        // for(int i=0;i<fruits.size();i++){
        // set<int> st;
        //     for(int j=i;j<fruits.size();j++){
        //         st.insert(fruits[j]);
        //         if(st.size()<=2){
        //             maxlen=max(maxlen,j-i+1);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;
        int l=0;
        int r=0;
        map<int,int> mpp;
        int maxlen=0;
        int n=fruits.size();
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                    l++;
            }
            if(mpp.size()<=2){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};