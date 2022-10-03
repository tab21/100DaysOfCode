# input as :
#  no of intervals (int)
#  n lines with start and end
#  eg :
#  3
#  2 4
#  3 7
#  10 15


def merge(intervals):
    intervals = sorted(intervals, key=lambda x: x[0])
    curr = intervals[0]
    res = []
    for els in intervals:
        if (curr[1] >= els[0]):
            if (curr[1] < els[1]):
                curr[1] = els[1]
        else:
            res.append(curr)
            curr = els

    res.append(curr)
    return res


def main():
    n = int(input())
    intervals = []

    for i in range(n):
        st, en = input().split()
        intervals.append([int(st), int(en)])

    res = merge(intervals)
    for el in res:
        print(el)


if __name__ == "__main__":
    main()
