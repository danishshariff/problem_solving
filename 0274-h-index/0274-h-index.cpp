class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count=0;
        int n=citations.size();
        int greaterno=INT_MIN;
        for(int i=0;i<n;i++){
            if(citations[i]>greaterno){
                greaterno=citations[i];
            }
        }
        
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i=0;i<n;i++){
            if(citations[i]>=i+1){
                count++;
            }
        }
        return count;
    }
};