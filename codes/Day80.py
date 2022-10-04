class Solution:
    def trap(self, height: list[int]) -> int:
        n = len(height)
        if (n < 3):
            return 0
        l, r = 0, n-1
        ml, mr = height[0], height[-1]
        res = 0

        while (l <= r):
            if (ml < mr):
                if (height[l] < ml):
                    res += ml-height[l]
                else:
                    ml = height[l]
                l += 1
            else:
                if (height[r] < mr):
                    res += mr-height[r]
                else:
                    mr = height[r]
                r -= 1
        return res


def main():
    heights = input().split()
    heights = [int(x) for x in heights]

    ans = Solution()
    print(ans.trap(heights))


if __name__ == "__main__":
    main()
