#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;

        int flipped = 0;
        while(x > flipped) {
            flipped = (flipped * 10) + (x % 10);
            x /= 10;
        }

        return (x == flipped) || (x == (flipped/10));
    }
};

int main(){
    std::cout << "LeetCode Problem 9 - Palindrome Number" << std::endl;
    Solution s;

    int x = 123121;
    auto answer = s.isPalindrome(x);

    std::cout << "Answer: " << answer << std::endl;
}