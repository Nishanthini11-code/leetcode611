#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
       
        std::sort(potions.begin(), potions.end());

        std::vector<int> result;
        for (int spell : spells) {
            
            auto it = std::lower_bound(potions.begin(), potions.end(), success, 
                                        [&](long long p, long long target_success) {
                                            
                                            return (long long)spell * p < target_success;
                                        });

            
            result.push_back(std::distance(it, potions.end()));
        }
        return result;
    }
};