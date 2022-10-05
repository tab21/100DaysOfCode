class Solution:
    def sumEvenAfterQueries(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        res = 0
        for el in nums:
            if el % 2 == 0:
                res += el

        ans = []
        for el, i in queries:
            if nums[i] % 2 == 0:
                res -= nums[i]

            nums[i] += el
            if nums[i] % 2 == 0:
                res += nums[i]

            ans.append(res)

        return ans


def main():
    num = input().split()
    num = [int(x) for x in num]

    n = int(input())
    queries = []
    for i in range(n):
        query = input().split()
        query = [int(x) for x in query]
        queries.append(query)

    ans = Solution()
    print(ans.sumEvenAfterQueries(num, queries))


if __name__ == "__main__":
    main()
