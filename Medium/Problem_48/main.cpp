#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < (n + 1) / 2; i ++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n-1-j][i];
                
                matrix[n-1-j][i] = matrix[n-1-i][n-j-1];
                matrix[n-1-i][n-j-1] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};

int main(){
    std::cout << "LeetCode 48 - Rotate Image" << std::endl;
    Solution s;

    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    s.rotate(matrix);
    

    std::cout << "[\n";
    for(std::vector<int>& row : matrix) {
        std::cout << "\t[ ";
        for(int& val : row) {
            std::cout << val << ", ";
        }
        std::cout << "\b\b ]\n";
    }
    std::cout << "]\n";

    return 0;
}