import heapq
from math import inf


class Solution:
    def getSkyline(self, buildings: list[list[int]]) -> list[list[int]]:
        change = sorted(
            [(start, -height, end) for start, end, height in buildings]
            + [(end, 0, None) for _, end, _ in buildings]
        )

        print(change)

        heap, res = [(0, inf)], [(0, 0)]

        for start, height, end in change:
            while start >= heap[0][1]:
                heapq.heappop(heap)
            if height:
                heapq.heappush(heap, (height, end))

            maxHeight = -heap[0][0]

            if maxHeight != res[-1][1]:
                res.append([start, maxHeight])

        return res[1:]


def main():
    n = int(input())
    buildings = []
    for i in range(n):
        building = input().split()
        building = [int(x) for x in building]
        buildings.append(building)

    ans = Solution()
    result = ans.getSkyline(buildings)
    for row in result:
        print(row)


if __name__ == "__main__":
    main()
