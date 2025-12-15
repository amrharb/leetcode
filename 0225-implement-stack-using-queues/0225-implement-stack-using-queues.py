class MyStack:

    def __init__(self):
        self.queue1 = deque()
        self.queue2 = deque()

    def push(self, x: int) -> None:
        self.queue1.append(x)

    def pop(self) -> int:
        if not len(self.queue1):
            while self.queue2:
                self.queue1.append(self.queue2.popleft())
        while len(self.queue1) >= 2:
            self.queue2.append(self.queue1.popleft())
        return self.queue1.popleft()

    def top(self) -> int:
        if not len(self.queue1):
            while self.queue2:
                self.queue1.append(self.queue2.popleft())
        while len(self.queue1) >= 2:
            self.queue2.append(self.queue1.popleft())
        return self.queue1[0]

    def empty(self) -> bool:
        return len(self.queue1) + len(self.queue2) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
