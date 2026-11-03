class ListNode:
    def __init__(self, val=0, next_node=None):
        self.val = val
        self.next = next_node


class Solution:
    def isPalindrome(self, head):
        if head is None or head.next is None:
            return True

        # Step 1: Find the middle
        slow = head
        fast = head

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse the second half
        prev = None
        curr = slow

        while curr is not None:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        # Step 3: Compare both halves
        left = head
        right = prev

        while right is not None:
            if left.val != right.val:
                return False

            left = left.next
            right = right.next

        return True


def main():
    # Example: 1 -> 2 -> 2 -> 1
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(1)

    solution = Solution()

    result = solution.isPalindrome(head)

    print("Palindrome Linked List:", str(result).lower())


if __name__ == "__main__":
    main()
