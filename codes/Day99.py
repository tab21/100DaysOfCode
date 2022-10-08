from sortedcontainers import SortedDict


class MyCalendarThree:

    def __init__(self):
        self.diff = SortedDict()

    def book(self, start: int, end: int) -> int:
        self.diff[start] = self.diff.get(start, 0) + 1
        self.diff[end] = self.diff.get(end, 0) - 1
        cur = res = 0
        for delta in self.diff.values():
            cur += delta
            res = max(cur, res)
        return res


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)


def main():
    inputs = input().split()
    inval = input().split()
    i = 0
    obj = None
    res = []
    for param in inputs:
        if param == "MyCalendarThree":
            obj = MyCalendarThree()
            res.append("null")
        elif param == "book":
            res.append(obj.book(int(inval[i]), int(inval[i+1])))
            i += 2
        else:
            res.append("wrong parameter")

    print(res)


if __name__ == "__main__":
    main()
