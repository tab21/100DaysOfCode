class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n > 0 and (3**19) % n == 0:
            return True
        return False


def main():
    ans = Solution()
    n = int(input())
    print(ans.isPowerOfThree(n))


if __name__ == "__main__":
    main()
