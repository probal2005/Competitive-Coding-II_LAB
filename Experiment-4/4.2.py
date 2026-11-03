class ListNode:
    def __init__(self, val=0, next_node=None):
        self.val = val
        self.next = next_node


class Solution:
    def oddEvenList(self, head):
        if head is None or head.next is None:
            return head

        odd = head
        even = head.next
        even_head = even

        while even is not None and even.next is not None:
            # Connect odd-positioned nodes
            odd.next = even.next
            odd = odd.next

            # Connect even-positioned nodes
            even.next = odd.next
            even = even.next

        # Connect odd list with even list
        odd.next = even_head

        return head


def print_list(head):
    values = []

    while head is not None:
        values.append(str(head.val))
        head = head.next

    print(" -> ".join(values))


def main():
    # Example: 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print("Original Linked List: ", end="")
    print_list(head)

    solution = Solution()
    head = solution.oddEvenList(head)

    print("Odd Even Linked List: ", end="")
    print_list(head)


if __name__ == "__main__":
    main()
