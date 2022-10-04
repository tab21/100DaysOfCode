class Solution:
    def validUtf8(self, data: list[int]) -> bool:
        byte = 0
        for n in data:
            bini = format(n, '#010b')[-8:]
            if byte == 0:
                for bit in bini:
                    if bit == '0':
                        break
                    byte += 1

                if byte == 0:
                    continue

                if byte == 1 or byte > 4:
                    return False

            elif (not (bini[0] == '1' and bini[1] == '0')):
                return False

            byte -= 1

        if byte == 0:
            return True

        return False


def main():
    data = input().split()
    data = [int(x) for x in data]
    ans = Solution()
    print(ans.validUtf8(data))


if __name__ == "__main__":
    main()
