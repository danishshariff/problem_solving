class Solution {
public:
        bool bloom_possible(vector<int>& arr,int day, int m,int k){
          int cnt=0;
          int nofbouq=0;
          int n=arr.size();
           for(int i=0;i<=n-1;i++){
            if(arr[i]<=day){
                cnt++;
            }
            else{
                nofbouq+=(cnt/k);
                cnt=0;
            }
           }
           nofbouq+=(cnt/k);
           if(nofbouq>=m){
            return true;
           }
           else 
           return false;
        }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int n=bloomDay.size();
        if(static_cast<long long>(m)*k>n){
            return -1;
        }
        while(low<=high){
        int mid=(low+high)/2;
       if(bloom_possible(bloomDay,mid,m,k)==true){
        int ans=mid;
        high=mid-1;
       }
       else{
        low=mid+1;
       }
        }
       return low;

        
    }
};