#include <iostream>

class Solution {
public:
    // x^n
    // -100.0 < x < 100.0
    // -2^31 <= n <= 2^31-1
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;
        double current_product = x;
        
        for (long long i = N; i ; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        
        return ans;
    }
};

int main(){
    std::cout << "LeetCode 50 - Pow(x,n)" << std::endl;
    Solution s;

    double x = 2;
    int n = 3;

    double answer = s.myPow(x,n);
    

    std::cout << "Answer: " << answer << std::endl;;
    return 0;
}