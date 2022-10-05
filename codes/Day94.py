class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [[0 for _ in range(1001)] for _ in range(31)]
        dp[0][0] = 1

        mod = (10**9)+7

        for i in range(1, n+1):
            for j in range(1, target+1):
                for l in range(1, k+1):
                    if (j >= l):
                        dp[i][j] += (dp[i-1][j-l] % mod)

        return dp[n][target] % mod


def main():
    n, k, target = input().split()
    n, k, target = int(n), int(k), int(target)

    ans = Solution()
    print(ans.numRollsToTarget(n, k, target))


if __name__ == "__main__":
    main()
