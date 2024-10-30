class Solution {
public:
    int maxind(vector<vector<int>>& matrix,int n,int m,int x){
        // int n=matrix.size();
        // int m=matrix[0].size();
        int maxval=INT_MIN;
        int index=-1;
        for(int i=0;i<n;i++){
          if(matrix[i][x]>maxval){
            maxval=matrix[i][x];
            index=i;
          }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxcolind=maxind(mat,n,m,mid);
            int left= mid-1>=0? mat[maxcolind][mid-1]:-1;
            int right =mid+1<m? mat[maxcolind][mid+1]:-1;
            if(mat[maxcolind][mid]>right && mat[maxcolind][mid]>left){
                return {maxcolind,mid};
            }
            else if(mat[maxcolind][mid]>right){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};