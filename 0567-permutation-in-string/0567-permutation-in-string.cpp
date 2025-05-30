class Solution {

public:
    bool checkeq(int a[26],int b[26]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;

    }
    bool checkInclusion(string s1, string s2) {
        // if (s1.size() > s2.size()) return false;
        // vector<int> freq1(26, 0), freq2(26, 0);
        // for (char c : s1) freq1[c - 'a']++;
        // for (int i = 0; i < s2.size(); i++) {
        //     freq2[s2[i] - 'a']++;
        //     if (i >= s1.size()) freq2[s2[i - s1.size()] - 'a']--;
        //     if (freq1 == freq2) return true;
        // }
        // return false;
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count1[index]++;

        }

        int i=0;
        int windsz=s1.length();
        int count2[26]={0};
        while(i<windsz && i<s2.length()){
            int index=s2[i]-'a';
            count2[index]++;
            i++;

        }
        if(checkeq(count1,count2)){
            return 1;
        }

        while(i<s2.length()){
            char newchar=s2[i];
            int index=newchar-'a';
             count2[index]++;
            char oldchar=s2[i-windsz];
            index=oldchar-'a';
            count2[index]--;
            i++;

            if(checkeq(count1,count2)){
                return 1;
            }
        }
        return 0;
    }
};
