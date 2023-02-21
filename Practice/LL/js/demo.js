class LinkedNode {
	constructor(data, next = null) {
		this.data = data;
		this.next = next;
	}

	toString() {
		return this.data;
	}
}

/**
 *
 * @param {LinkedNode} head
 */
const printLL = (head) => {
	let temp = head;
	while (temp.next != null) {
		console.log(temp?.data + " ");
		temp = temp.next;
	}
};

class LinkedList {
	constructor() {
		this.head = null;
	}

	prepend(data) {
		const newNode = new LinkedNode(data);
		newNode.next = this.head;
		this.head = newNode;
		return this.head;
	}
}

const ll = new LinkedList();

ll.prepend(20);
ll.prepend(30);
ll.prepend(40);

// const node4 = new LinkedNode(40);

// node1.next = node2;
// node1.next = node3;
// node1.next = node3;
// node1.next = node4;

// printLL(ll);
// console.log(node1);

debugger;
debugger;
debugger;
