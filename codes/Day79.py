

def palindromePairs(words: list[str]) -> list[list[int]]:
    backward, res = {}, []
    for i, word in enumerate(words):
        backward[word[::-1]] = i

    for i, word in enumerate(words):

        if word in backward and backward[word] != i:
            res.append([i, backward[word]])

        if word != "" and "" in backward and word == word[::-1]:
            res.append([i, backward[""]])
            res.append([backward[""], i])

        for j in range(len(word)):
            if word[j:] in backward and word[:j] == word[j-1::-1]:
                res.append([backward[word[j:]], i])
            if word[:j] in backward and word[j:] == word[:j-1:-1]:
                res.append([i, backward[word[:j]]])

    return res


def main():
    words = input().split()
    result = palindromePairs(words)

    for row in result:
        print(row)


if __name__ == "__main__":
    main()