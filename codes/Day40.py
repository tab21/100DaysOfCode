def numFactoredBinaryTrees(arr) -> int:
    n = len(arr)
    arr.sort()
    dp = [1] * n
    index = {x: i for i, x in enumerate(arr)}
    for i, x in enumerate(arr):
        for j in range(i):
            if x % arr[j] == 0 and x/arr[j] in index:
                dp[i] = (dp[i] + (dp[j] * dp[index[x/arr[j]]])) % (10 ** 9 + 7)

    return sum(dp) % (10 ** 9 + 7)


def main():
    arr = list(input().split())
    arr = [int(x) for x in arr]

    print(numFactoredBinaryTrees(arr))


if __name__ == "__main__":
    main()
