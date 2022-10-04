class Solution:
    def maxProfit(self, k: int, prices: list[int]) -> int:
        n = len(prices)

        dp = [[[0 for col in range(k+1)] for col in range(2)]
              for row in range(n+1)]

        for i in range(n-1, -1, -1):
            for buy in range(2):
                for cap in range(1, k+1):
                    if buy == 0:
                        dp[i][buy][cap] = max(
                            0+dp[i+1][0][cap], -prices[i] + dp[i+1][1][cap])
                    else:
                        dp[i][buy][cap] = max(
                            0+dp[i+1][1][cap], prices[i] + dp[i+1][0][cap-1])

        return dp[0][0][k]


def main():
    k = int(input())
    prices = input().split()
    prices = [int(x) for x in prices]
    ans = Solution()

    print(ans.maxProfit(k, prices))


if __name__ == "__main__":
    main()
