#include <vector>
class Solution {
public:
    int totalNumbers(vector<int>& digits){
        std::vector<int> result;
        std::vector<int> mp(10, 0);
        
        // Count frequency of each digit in input
        for (int digit : digits) {
            mp[digit]++;
        }
        
        // 100s place (1 to 9)
        for (int i = 1; i <= 9; i++) {
            if (mp[i] == 0) continue;
            mp[i]--; // Use digit i
            
            // 10s place (0 to 9)
            for (int j = 0; j <= 9; j++) {
                if (mp[j] == 0) continue;
                mp[j]--; // Use digit j
                
                // 1s place (even numbers: 0, 2, 4, 6, 8)
                for (int k = 0; k <= 8; k += 2) {
                    if (mp[k] == 0) continue;
                    mp[k]--; // Use digit k
                    
                    // Form the 3-digit even number
                    int num = (i * 100) + (j * 10) + k;
                    result.push_back(num);
                    
                    mp[k]++; // Backtrack digit k
                }
                mp[j]++; // Backtrack digit j
            }
            mp[i]++; // Backtrack digit i
        }
        
        return result.size();
    }
};