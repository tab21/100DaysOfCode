from hashlib import new


class TimeMap:
    def __init__(self):
        self.key_time_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if not key in self.key_time_map:
            self.key_time_map[key] = {}
        self.key_time_map[key][timestamp] = value

    def get(self, key: str, timestamp: int) -> str:
        if not key in self.key_time_map:
            return ""
        for curr_time in reversed(range(1, timestamp + 1)):
            if curr_time in self.key_time_map[key]:
                return self.key_time_map[key][curr_time]
        return ""

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)


def main():
    obj = None

    inputs = input().split()
    inval = input().split()
    i = 0
    res = []
    for param in inputs:
        if param == "TimeMap":
            obj = TimeMap()
            res.append("null")
        elif param == "set":
            key = inval[i]
            value = inval[i+1]
            time = int(inval[i+2])
            i = +3
            obj.set(key, value, time)
            res.append("null")
        elif param == "get":
            key = inval[i]
            time = int(inval[i+1])
            i += 2
            res.append(obj.get(key, time))
        else:
            res.append("wrong argument")

    print(res)


if __name__ == "__main__":
    main()
