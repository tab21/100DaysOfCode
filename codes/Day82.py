class Solution:
    def findLength(self, nums1: list[int], nums2: list[int]) -> int:
        n, m = len(nums1), len(nums2)

        dp = [[0]*(m+1) for _ in range(n+1)]
        res = 0

        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                if nums1[i] == nums2[j]:
                    dp[i][j] = dp[i+1][j+1]+1
                if (dp[i][j] > res):
                    res = dp[i][j]

        return res


def main():
    nums1 = input().split()
    nums2 = input().split()

    nums1 = [int(x) for x in nums1]
    nums2 = [int(x) for x in nums2]

    ans = Solution()
    print(ans.findLength(nums1, nums2))


if __name__ == "__main__":
    main()
