class Solution {
public:
    void sortColors(vector<int>& arr) {
        // sort(nums.begin(),nums.end());
        
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    int n=arr.size();
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == 0) cnt0++;
//         else if (arr[i] == 1) cnt1++;
//         else cnt2++;
//     }

//     //Replace the places in the original array:
//     for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

//     for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

//     for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's

// }

//dutch natiinal flag algo

int low=0;
int high=n-1;
int mid=0;
while(mid<=high){
    if(arr[mid]==0){
        swap(arr[mid],arr[low]);
        mid++;
        low++;
        
    }
    else if(arr[mid]==1){
        mid++;
    }
    else{
        swap(arr[mid],arr[high]);
        high--;
        
    }
    
}
    }
};