class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        if (len(nums) == 3):
            return sum(nums)

        nums.sort()
        n = len(nums)
        res = 100000
        ans = None
        for i in range(n-2):
            l = i+1
            r = n-1
            while (l < r):
                curr = nums[i]+nums[l]+nums[r]
                if (curr == target):
                    return curr

                if (res > abs(curr-target)):
                    res = abs(curr-target)
                    ans = curr

                if (curr > target):
                    r -= 1
                else:
                    l += 1

        return ans


def main():
    nums = input().split()
    nums = [int(x) for x in nums]
    target = int(input())

    ans = Solution()
    print(ans.threeSumClosest(nums, target))


if __name__ == "__main__":
    main()
