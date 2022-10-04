from collections import defaultdict
from unittest import result


class Solution:
    def findDuplicate(self, paths: list[str]) -> list[list[str]]:
        m = defaultdict(list)
        for p in paths:
            path = p.split()
            directoryPath, rest = path[0], path[1:]
            for f in rest:
                fileName, fileContent = f.split('(')[0], f.split('(')[1][:-1]
                m[fileContent].append("{}/{}".format(directoryPath, fileName))
        return [m[k] for k in m.keys() if len(m[k]) > 1]


def main():
    paths = input().split(",")

    ans = Solution()
    result = ans.findDuplicate(paths)
    for path in result:
        print(path)


if __name__ == "__main__":
    main()
