#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> myMap;

        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];
            if(myMap.find(needed) != myMap.end()) {
                return {myMap.at(needed), i};
            }else{
                myMap[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};

int main(){
    std::cout << "LeetCode Problem 1 - Two Sum" << std::endl;
    Solution s;

    std::vector<int> nums = {2,7,11,15};
    int target = 9;

    auto answer = s.twoSum(nums, target);

    std::cout << "Two sum int pair: [" << answer[0] << ", " << answer[1] << "] " << std::endl; 

}