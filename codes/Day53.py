def isPowerOfFour(n: int) -> bool:
    if (n > 0 and n & n-1 == 0 and 0xAAAAAAAA & n == 0):
        return True
    return False


def main():
    n = int(input())
    print(isPowerOfFour(n))


if __name__ == "__main__":
    main()
