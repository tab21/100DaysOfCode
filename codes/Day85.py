class Solution:
    def concatenatedBinary(self, n: int) -> int:
        res = []
        for i in range(1, n+1):
            res.append((str(bin(i)))[2:])
        res = "".join(res)
        res = int(res, 2)

        return res % (10**9+7)


def main():
    n = int(input())
    ans = Solution()
    print(ans.concatenatedBinary(n))


if __name__ == "__main__":
    main()
