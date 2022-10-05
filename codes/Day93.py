class Solution:
    def numDecodings(self, s: str) -> int:
        if (s[0] == '0'):
            return 0

        n = len(s)
        v = [0]*101
        v[0] = 1
        v[1] = 1

        o = ord('0')

        for i in range(1, n):
            a = False
            b = False

            d = ord(s[i]) - o

            if (d != 0):
                v[i+1] += v[i]
                a = True

            p = ord(s[i-1]) - o
            ds = p*10 + d
            if (ds <= 26):
                if (s[i-1] != '0'):
                    v[i+1] += v[i-1]
                    b = True

            if (not a and not b):
                return 0

        return v[n]


def main():
    s = input()
    ans = Solution()
    print(ans.numDecodings(s))


if __name__ == "__main__":
    main()
