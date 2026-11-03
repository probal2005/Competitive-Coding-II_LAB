class MyQueue:
    def __init__(self):
        self.input_stack = []
        self.output_stack = []

    def push(self, x):
        self.input_stack.append(x)

    def pop(self):
        if not self.output_stack:
            while self.input_stack:
                self.output_stack.append(self.input_stack.pop())

        return self.output_stack.pop()

    def peek(self):
        if not self.output_stack:
            while self.input_stack:
                self.output_stack.append(self.input_stack.pop())

        return self.output_stack[-1]

    def empty(self):
        return not self.input_stack and not self.output_stack


def main():
    queue = MyQueue()

    queue.push(1)
    queue.push(2)
    queue.push(3)

    print("Front Element:", queue.peek())
    print("Popped Element:", queue.pop())
    print("Front Element After Pop:", queue.peek())
    print("Popped Element:", queue.pop())
    print("Queue Empty:", str(queue.empty()).lower())


if __name__ == "__main__":
    main()
