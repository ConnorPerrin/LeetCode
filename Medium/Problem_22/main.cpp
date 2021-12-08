#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> ans;
    int numParenthesis = 0;

    std::vector<std::string> generateParenthesis(int n) {
        std::string temp = "";
        numParenthesis = n;

        backtracking(0, 0, temp);

        return ans;
    }

    void backtracking(int left, int right, std::string temp) {
        if((left == numParenthesis) && (right == numParenthesis)){
            ans.push_back(temp);
            return;
        }

        if(left <= numParenthesis) {
            temp.push_back('(');
            backtracking(left+1, right, temp);
            temp.pop_back();
        }

        if(right < left) {
            temp.push_back(')');
            backtracking(left, right+1, temp);
            temp.pop_back();
        }
    }


};


int main(){
    std::cout << "LeetCode 22 - Generate Parentheses" << std::endl;
    Solution s;

    int n = 3;
    std::vector<std::string> answer = s.generateParenthesis(n);

    std::cout << "Answer: ";

    for(const auto& val : answer) {
        std::cout << val << ", ";
    }

    std::cout << "\n";

    return 0;
}