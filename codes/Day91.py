import heapq


class Solution:
    def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
        hp = []

        for el in arr:

            if len(hp) < k:
                heapq.heappush(hp, (-abs(x-el), el))
            else:
                b, e = hp[0]
                if (abs(x-el) == -b):
                    if (el < e):
                        heapq.heappushpop(hp, (-abs(x-el), el))
                elif (abs(x-el) < -b):

                    heapq.heappushpop(hp, (-abs(x-el), el))

        res = [x for y, x in hp]
        res.sort()

        return res


def main():
    array = input().split()
    array = [int(x) for x in array]

    k = int(input())
    x = int(input())

    ans = Solution()
    print(ans.findClosestElements(array, k, x))


if __name__ == "__main__":
    main()
