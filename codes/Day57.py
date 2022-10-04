from collections import Counter


class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        count = Counter(str(n))

        return any(count == Counter(str(1 << x)) for x in range(31))


def main():
    n = int(input())
    ans = Solution()
    print(ans.reorderedPowerOf2(n))


if __name__ == "__main__":
    main()
