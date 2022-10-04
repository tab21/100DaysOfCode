class Solution:
    def findOriginalArray(self, changed: list[int]) -> list[int]:

        s = {}
        original = []

        if len(changed) % 2:
            return []

        changed.sort()
        for el in changed:
            if el % 2 == 0 and el//2 in s and s[el//2]:
                original.append(el//2)
                s[el//2] -= 1
            elif el in s:
                s[el] += 1
            else:
                s[el] = 1

        if len(changed)//2 != len(original):
            return []
        return original


def main():
    changed = input().split()
    changed = [int(x) for x in changed]

    ans = Solution()
    print(ans.findOriginalArray(changed))


if __name__ == "__main__":
    main()
