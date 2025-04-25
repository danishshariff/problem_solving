class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int sum=0,j=0;
        for(int i=1;i<=n;i++){
            sum=0,j=i;
            while(j){
                sum+=j%10;
                j/=10;
            }
            mp[sum]++;
        }
        int ans=0,maxi=0;
        for(auto &it:mp){
            if(it.second>maxi){
                ans=1;
                maxi=it.second;
            }
            else if(it.second==maxi) ans++;
        }
        return ans;
    }
};