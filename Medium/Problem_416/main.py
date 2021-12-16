from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        return True

if __name__ == "__main__":
    s = Solution()

    nums = [1,2,3,4]
    ans = s.canPartition(nums)
    print("Answer: ", ans)