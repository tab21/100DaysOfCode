import heapq


class Solution:
    def maxPerformance(self, n: int, speed: list[int], efficiency: list[int], k: int) -> int:
        engg = []

        for eff, spd in zip(efficiency, speed):
            engg.append((eff, spd))

        engg.sort(reverse=True)

        res, spd = 0, 0
        hp = []

        for e, s in engg:
            if len(hp) >= k:
                spd -= heapq.heappop(hp)

            spd += s
            heapq.heappush(hp, s)
            res = max(res, e*spd)

        return res % (10**9+7)


def main():
    n = int(input())
    spd = input().split()
    spd = [int(x) for x in spd]
    eff = input().split()
    eff = [int(x) for x in eff]
    k = int(input(k))
    ans = Solution()

    print(ans.maxPerformance(n, spd, eff, k))


if __name__ == "__main__":
    main()
