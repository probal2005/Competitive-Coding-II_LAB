class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;

        while (even != null && even.next != null) {
            // Connect odd-positioned nodes
            odd.next = even.next;
            odd = odd.next;

            // Connect even-positioned nodes
            even.next = odd.next;
            even = even.next;
        }

        // Connect odd list with even list
        odd.next = evenHead;

        return head;
    }
}

class Main {
    static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);

            if (head.next != null) {
                System.out.print(" -> ");
            }

            head = head.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {
        // Example: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.print("Original Linked List: ");
        printList(head);

        Solution solution = new Solution();
        head = solution.oddEvenList(head);

        System.out.print("Odd Even Linked List: ");
        printList(head);
    }
}
