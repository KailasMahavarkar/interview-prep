class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    partition(head, x) {
        const leftDummy = new ListNode();
        const rightDummy = new ListNode();

        let left = leftDummy;
        let right = rightDummy;

        while (head !== null) {
            if (head.val < x) {
                left.next = head;
                left = left.next;
            } else {
                right.next = head;
                right = right.next;
            }
            head = head.next;
        }

        right.next = null;
        left.next = rightDummy.next;
        return leftDummy.next;
    }
}

function vectorToListNode(arr) {
    if (arr.length === 0) return null;
    const head = new ListNode(arr[0]);
    let temp = head;
    for (let i = 1; i < arr.length; i++) {
        temp.next = new ListNode(arr[i]);
        temp = temp.next;
    }
    return head;
}

function listNodeToVector(head) {
    const arr = [];
    let temp = head;
    while (temp !== null) {
        arr.push(temp.val);
        temp = temp.next;
    }
    return arr;
}

function printLinkedList(head) {
    let temp = head;
    while (temp !== null) {
        console.log(`${temp.val} -> `);
        temp = temp.next;
    }
    console.log("NULL");
}

const nums = [1, 4, 3, 2, 5, 2];
const k = 2;
const ll = vectorToListNode(nums);

const sol = new Solution();
const ans = sol.partition(ll, k);

printLinkedList(ans);
