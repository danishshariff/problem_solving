class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&ans,
    vector<vector<int>>&image,int newColor, int inicolor){
        ans[row][col]=newColor;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=image.size();
        int m=image[0].size();
             int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newColor)
                   {
                    ans[nrow][ncol]=newColor;
                    q.push({nrow,ncol});
                   }
            
        }
        }
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, 
    int sc, int newColor) {
        int inicolor=image[sr][sc];
        vector<vector<int>>ans= image;
        dfs(sr,sc,ans,image,newColor,inicolor);
        return ans;
    }
};