class StockSpanner {
public:
    //     vector<int> arr;
    // StockSpanner() {
    // }
    
    // int next(int price) {
    //     arr.push_back(price);
    //     int cnt=1;
    //     for(int i=arr.size()-2;i>=0;i--){
    //         if(arr[i]<=price){
    //             cnt++;
                
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     return cnt;
    // }

   stack<pair<int,int>> st;
   int ind=-1;
    void stclear(std::stack<std::pair<int, int>>& s) {
        s = std::stack<std::pair<int, int>>();
    }
    StockSpanner() {
        ind=-1;
        stclear(st);
    }

        int next(int price) {
            ind=ind+1;
            while(!st.empty()&& st.top().first<=price){
                st.pop();
            }
            int ans = st.empty() ? ind + 1 : ind - st.top().second;
            st.push({price,ind});
            return ans;
        }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */