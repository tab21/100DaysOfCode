class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        a = [0]*26

        for i in magazine:
            a[ord(i)-ord('a')] += 1

        for i in ransomNote:
            a[ord(i)-ord('a')] -= 1

        for i in a:
            if i < 0:
                return False

        return True


def main():
    ransom = input()
    magazine = input()
    ans = Solution()
    print(ans.canConstruct(ransom, magazine))


if __name__ == "__main__":
    main()
