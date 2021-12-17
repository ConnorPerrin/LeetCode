#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> myMap;
        
        for(const int& val : nums) {
            if(myMap[val]) {
                myMap.erase(val);
            }else{
                myMap[val] = 1;
            }
        }

        return myMap.begin()->first;

    }

    int singleNumberMaths(std::vector<int>& nums) {
        int ans = 0;

        for(const int& val : nums) {
            ans ^= val;
        }

        return ans;
    }
};

int main(){
    std::cout << "LeetCode Problem 136 - Single Number" << std::endl;
    Solution s;

    std::vector<int> nums = {4,4,3,2,2};
    int answer = s.singleNumber(nums);
    // int answer = s.singleNumberMaths(nums);

    std::cout << "Answer: " << answer << std::endl;
}