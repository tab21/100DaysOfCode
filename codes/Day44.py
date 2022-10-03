def countPoints(points, queries) -> list[int]:
    res = []

    for i in queries:
        x1 = i[0]
        y1 = i[1]
        r = i[2]
        res.append(0)

        for j in points:
            x2 = j[0]
            y2 = j[1]

            d = ((x1-x2)**2 + (y1-y2)**2)**(1/2)

            if (d <= r):
                res[-1] += 1

    return res


def main():
    n = int(input())

    points = []
    for i in range(n):
        point = input().split()
        point = [int(x) for x in point]

        points.append(point)

    n = int(input())
    queries = []
    for i in range(n):
        query = input().split()
        query = [int(x) for x in query]

        queries.append(query)

    result = countPoints(points, queries)

    print(result)


if __name__ == "__main__":
    main()
