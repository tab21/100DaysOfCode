def maxIncreaseKeepingSkyline(grid: list[list[int]]) -> int:
    r, c = len(grid), len(grid[0])
    rows = [0]*r
    cols = [0]*c

    for i in range(r):
        for j in range(c):
            if rows[i] < grid[i][j]:
                rows[i] = grid[i][j]

            if cols[j] < grid[i][j]:
                cols[j] = grid[i][j]
    res = 0

    for i in range(r):
        for j in range(c):
            res += min(rows[i], cols[j]) - grid[i][j]

    return res


def main():
    n = int(input())
    grid = []

    for i in range(n):
        row = input().split()
        row = [int(x) for x in row]
        grid.append(row)

    print(maxIncreaseKeepingSkyline(grid))


if __name__ == "__main__":
    main()
