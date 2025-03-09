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
    
    // Create an array that marks where adjacent tiles differ.
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = (colors[i] != colors[(i + 1) % n]) ? 1 : 0;
    }
    
    int windowSize = k - 1;  // Number of adjacent pairs in a group of k tiles.
    int sum = 0;
    
    // Calculate the sum for the initial window (starting at index 0).
    for (int j = 0; j < windowSize; j++) {
        sum += diff[j];
    }
    
    int count = 0;
    if (sum == windowSize)
        count++;
    
    // Slide the window for starting indices 1 through n-1.
    for (int i = 1; i < n; i++) {
        // Remove the element leaving the window and add the new element entering the window.
        // The leaving element is diff[i - 1].
        // The new element is diff[(i + windowSize - 1) % n] because we wrap around using mod.
        sum = sum - diff[i - 1] + diff[(i + windowSize - 1) % n];
        if (sum == windowSize)
            count++;
    }
    
    return count;
}


};