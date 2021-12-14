from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        myDict = {}

        for index, val in enumerate(nums):
            need = target - val

            if need in myDict:
                return [myDict[need], index]
            
            myDict[val] = index

        return [-1, -1]

if __name__ == "__main__":
    s = Solution()

    nums = [1,2,3,4]
    target = 7
    ans = s.twoSum(nums, target)

    print("Answer: ", ans)