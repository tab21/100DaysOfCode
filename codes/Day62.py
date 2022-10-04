def pacificAtlantic(heights: list[list[int]]) -> list[list[int]]:
    n, m = len(heights), len(heights[0])
    pac, atl = set(), set()

    def dfs(r, c, h, visit):
        if (r < 0 or c < 0 or r >= n or c >= m):
            return
        if ((r, c) in visit or heights[r][c] < h):
            return

        h = heights[r][c]
        visit.add((r, c))

        dfs(r+1, c, h, visit)
        dfs(r-1, c, h, visit)
        dfs(r, c+1, h, visit)
        dfs(r, c-1, h, visit)

    for c in range(m):
        dfs(0, c, 0, pac)
        dfs(n-1, c, 0, atl)

    for r in range(n):
        dfs(r, 0, 0, pac)
        dfs(r, m-1, 0, atl)

    res = []
    for i in range(n):
        for j in range(m):
            if ((i, j) in pac and (i, j) in atl):
                res.append([i, j])

    return res


def main():
    n = int(input())
    heights = []

    for i in range(n):
        height = input().split()
        height = [int(x) for x in height]
        heights.append(height)

    ans = pacificAtlantic(heights)
    for row in ans:
        print(row)


if __name__ == "__main__":
    main()
