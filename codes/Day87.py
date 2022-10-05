from collections import deque


class MyCircularQueue:
    def __init__(self, k: int):
        self.que = deque()
        self.l = k

    def enQueue(self, value: int) -> bool:
        if len(self.que) < self.l:
            self.que.append(value)
            return True
        return False

    def deQueue(self) -> bool:
        if len(self.que) > 0:
            self.que.popleft()
            return True
        return False

    def Front(self) -> int:
        if len(self.que) > 0:
            return self.que[0]
        return -1

    def Rear(self) -> int:
        if len(self.que) > 0:
            return self.que[-1]
        return -1

    def isEmpty(self) -> bool:
        if len(self.que) == 0:
            return True
        return False

    def isFull(self) -> bool:
        if len(self.que) == self.l:
            return True
        return False


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()

def main():
    inputs = input().split(",")
    invalues = input().split(",")
    i = 0

    obj = None
    res = []
    for inpt in inputs:
        print(inpt)
        match inpt:
            case "MyCircularQueue":
                obj = MyCircularQueue(int(invalues[i]))
                res.append("null")
            case "enQueue":
                res.append(obj.enQueue(int(invalues[i])))
            case "deQueue":
                res.append(obj.deQueue())
            case "Front":
                res.append(obj.Front())
            case "Rear":
                res.append(obj.Rear())
            case "isEmpty":
                res.append(obj.isEmpty())
            case "isFull":
                res.append(obj.isFull())
            case default:
                res.append("wrong argument")
        i += 1

    print(res)


if __name__ == "__main__":
    main()
