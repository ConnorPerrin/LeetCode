#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int best = nums[0];
        int currMin = nums[0];
        int currMax = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            int tempMax = std::max(val, std::max(val*currMax, val*currMin));
            
            currMin = std::min(val, std::min(val*currMax, val*currMin));
            currMax = tempMax;

            best = std::max(best, currMax);
        }

        return best;
    }
};

int main(){
    std::cout << "LeetCode 152 - Maximum Product Subarray" << std::endl;
    Solution s;

    std::vector<int> nums = {2,3,-2,4};
    int ans = s.maxProduct(nums);

    std::cout << "Answer: " << ans << std::endl;

    return 0;
}