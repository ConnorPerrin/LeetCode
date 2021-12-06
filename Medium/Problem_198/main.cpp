#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int rob_1 = 0;
        int rob_2 = 0;

        for(int& val : nums) {
            int temp = std::max(val + rob_1, rob_2);
            
            rob_1 = rob_2;
            rob_2 = temp;
        }
        return rob_2;
    }
};

int main(){
    std::cout << "LeetCode Problem 198 - House Robber" << std::endl;
    Solution s;

    std::vector<int> nums = {1,2,3,4};
    int ans = s.rob(nums);

    std::cout << "Answer: " << ans << std::endl;

    return 0;
}