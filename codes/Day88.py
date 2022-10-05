class Solution:
    def equationsPossible(self, equations: list[str]) -> bool:
        al = [i for i in range(26)]
        a = ord('a')

        def find(x):
            return x if al[x] == x else find(al[x])

        for e in equations:
            if e[1] == '=':
                al[find(ord(e[0]) - a)] = find(ord(e[3]) - a)

        for e in equations:
            if (e[1] == '!' and find(ord(e[0]) - a) == find(ord(e[3]) - a)):
                return False

        return True


def main():
    equations = input().split()
    ans = Solution()
    print(ans.equationsPossible(equations))


if __name__ == "__main__":
    main()
