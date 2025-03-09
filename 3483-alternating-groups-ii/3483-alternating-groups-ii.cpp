class Solution {
public:
    // int numberOfAlternatingGroups(vector<int>& colors, int k) {
    //     int n = colors.size();
    //     int count = 0;
        
        
    //     for (int i = 0; i < n; i++) {
    //         bool isValid = true;
            
            
    //         for (int j = 1; j < k; j++) {
    //             if (colors[(i + j) % n] == colors[(i + j - 1) % n]) {
    //                 isValid = false;
    //                 break;
    //             }
    //         }
            
    //         if (isValid) count++;
    //     }
        
    //     return count;
    // int n = colors.size();
    //     int count = 0;

    //     for (int i = 0; i < n; i++) { 
    //         int j = 1; 

           
    //         while (j < k && colors[(i + j) % n] != colors[(i + j - 1) % n]) {
    //             j++;
    //         }

           
    //         if (j == k) count++;
    //     }

    //     return count;
    
    // }



 int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();
    
    // Build diff array: 1 if adjacent tiles are different, 0 otherwise.
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = (colors[i] != colors[(i + 1) % n]) ? 1 : 0;
    }
    
    // Extend the diff array to handle the wrap-around.
    vector<int> ext(n + k - 1);
    for (int i = 0; i < n; i++) {
        ext[i] = diff[i];
    }
    for (int i = n; i < n + k - 1; i++) {
        ext[i] = diff[i - n];
    }
    
    // Build prefix sum for the extended diff array.
    vector<int> prefix(ext.size() + 1, 0);
    for (int i = 0; i < ext.size(); i++) {
        prefix[i + 1] = prefix[i] + ext[i];
    }
    
    // Count the number of groups with alternating colors.
    int ans = 0;
    // Each group starting at index i spans indices [i, i+k-1) in ext.
    for (int i = 0; i < n; i++) {
        // The group is alternating if the sum of diff values is exactly k-1.
        if (prefix[i + k - 1] - prefix[i] == k - 1)
            ans++;
    }
    
    return ans;
}

};