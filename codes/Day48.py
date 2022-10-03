def uniqueMorseRepresentations(words) -> int:
    morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
             "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]

    res = set()

    for word in words:
        ans = []
        for el in word:
            ans.append(morse[ord(el)-ord('a')])

        res.add(''.join(ans))

    return len(res)


def main():
    words = input().split()
    print(uniqueMorseRepresentations(words))


if __name__ == "__main__":
    main()
