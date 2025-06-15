class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int count = 0;
        vector<int> lastseen(3, -1);
        while (right < n) {
            
            lastseen[s[right] - 'a']=right;

           
            if (lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1) {
               
                count+=(1+min({lastseen[0],lastseen[1],lastseen[2]}));
            }

            
            right++;
        }

        return count;
    }
};
