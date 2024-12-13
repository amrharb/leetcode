class MyHashSet {
    class ListNode {
        int key;
        ListNode next;

        ListNode() {}
        ListNode(int key) {
            this.key = key;
        }
        ListNode(int key, ListNode next) {
            this.key = key;
            this.next = next;
        }
    }

    ListNode head;

    public MyHashSet() {
        head = null;
    }

    public void add(int key) {
        // Check if the key already exists
        if (contains(key)) {
            return; // Do nothing if the key is already in the set
        }
        // Add the key at the head of the list
        head = new ListNode(key, head);
    }

    public void remove(int key) {
        if (head == null) return; // Empty list, nothing to remove
        if (head.key == key) {
            head = head.next; // Remove the head node
            return;
        }
        ListNode temp = head;
        while (temp.next != null) {
            if (temp.next.key == key) {
                temp.next = temp.next.next; 
                return;
            }
            temp = temp.next;
        }
    }

    public boolean contains(int key) {
        ListNode temp = head;
        while (temp != null) {
            if (temp.key == key) {
                return true; // Key found
            }
            temp = temp.next;
        }
        return false; // Key not found
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
