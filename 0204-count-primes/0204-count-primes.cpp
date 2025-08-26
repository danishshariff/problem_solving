class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n);
        int cnt=0;
        for(int i=2;i<n;i++){
            prime[i]=1;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(prime[i]==1){
                for(int j=2*i;j<n;j+=i){
                    prime[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(prime[i]==1){
                cnt++;
            }
        }
        return cnt;
    }
};