class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxarea=0;
        while(left<right){
            int hei=min(height[left],height[right]);
            int width=right-left;
            int curarea=hei*width;
            maxarea=max(curarea,maxarea);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};