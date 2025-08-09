class Solution {
public:
 int maxi(vector<int>& arr){
    int n=arr.size();
    int maxim=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxim){
            maxim=arr[i];
        }
    }
    return maxim;
 }
 int sum(vector<int>& arr){
    int sumi=0;
    for(int i=0;i<arr.size();i++){
        sumi+=arr[i];
    }
    return sumi;
 }

 int func(vector<int>& weights,int cap){
    int day=1;
    int load=0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>cap){
            day=day+1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return day;
 }
    // int shipWithinDays(vector<int>& weights, int days) {
    //     for(int cap=maxi(weights);cap<=sum(weights);cap++){
    //         int daysreq=func(weights,cap);
    //         if(daysreq<=days){
    //             return cap;
    //         }
    //     }
    //     return -1;
    // }


    int shipWithinDays(vector<int>& weights, int days) {
       int low=maxi(weights);
       int high=sum(weights);
       while(low<=high){
         int mid = low + (high - low) / 2; 
        int nooddays=func(weights,mid);
        if(nooddays<=days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
        return low;
    }
};