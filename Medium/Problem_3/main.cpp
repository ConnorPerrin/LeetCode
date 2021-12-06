#include <iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int ans = 0;
        std::unordered_map<char, int> char_pos_map;

        int start = 0;
        for (int current = 0; current < s.size(); current++) {
            if(char_pos_map.find(s[current]) != char_pos_map.end()) {
                start = std::max(char_pos_map.at(s[current]), start);
            }

            ans = std::max(ans, current - start + 1);
            char_pos_map[s[current]] = current + 1;
        }

        return ans;
    }
};

int main(){
    std::cout << "LeetCode Problem 3 - Longest Substring Without Repeating Characters" << std::endl;
    Solution s;

    std::string str = "abcabcaa";
    int ans = s.lengthOfLongestSubstring(str);

    std::cout << "Answer: " << ans << std::endl;

    return 0;
}