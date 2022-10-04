class Solution:
    def bagOfTokensScore(self, tokens: list[int], power: int) -> int:
        tokens.sort()
        l, r = 0, len(tokens)-1
        p, ans = 0, 0

        while l <= r and (power >= tokens[l] or p > 0):
            while l <= r and power >= tokens[l]:
                power -= tokens[l]
                l += 1
                p += 1
            ans = max(ans, p)

            if (l <= r and p > 0):
                power += tokens[r]
                r -= 1
                p -= 1

        return ans


def main():
    tokens = input().split()
    tokens = [int(x) for x in tokens]
    power = int(input())

    ans = Solution()
    print(ans.bagOfTokensScore(tokens, power))


if __name__ == "__main__":
    main()
