class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //  map<int,int> mpp;
     int n=nums.size();
    //  for(int i=0;i<n;i++){
    //     mpp[nums[i]]++;
    //  }
    //  for(auto it: mpp){
    //     if(it.second>n/2){
    //         return it.first;
    //     }
    //  }
    //     return -1;
    //  }

    //moores voting algo

    int cnt=0;
    int ele;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
        ele=nums[i];
        }
        else if(nums[i]==ele){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele){
            cnt1++;
        }
    }
    if(cnt1>n/2){
        return ele;
    }
    return -1;
    }
};