#include <queue>
#include <vector>

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-heap to always pick the character with the most remaining occurrences
        priority_queue<pair<int, char>> pq;
        
        // Add all the characters and their counts to the heap if they are greater than zero
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        // Keep building the string
        while (!pq.empty()) {
            // Pick the character with the most occurrences
            auto first = pq.top(); pq.pop();
            char first_char = first.second;
            int first_count = first.first;
            
            // If the last two characters in the result are the same as the one we're trying to add, we need to pick another character
            if (result.size() >= 2 && result[result.size() - 1] == first_char && result[result.size() - 2] == first_char) {
                if (pq.empty()) {
                    break; // If no other character is available, we're done
                }
                
                // Pick the second most frequent character
                auto second = pq.top(); pq.pop();
                char second_char = second.second;
                int second_count = second.first;
                
                // Add the second character and decrease its count
                result += second_char;
                second_count--;
                
                // If the second character still has occurrences, put it back in the heap
                if (second_count > 0) {
                    pq.push({second_count, second_char});
                }
                
                // Put the first character back in the heap
                pq.push({first_count, first_char});
            } else {
                // Add the most frequent character and decrease its count
                result += first_char;
                first_count--;
                
                // If the character still has occurrences, put it back in the heap
                if (first_count > 0) {
                    pq.push({first_count, first_char});
                }
            }
        }
        
        return result;
    }
};
