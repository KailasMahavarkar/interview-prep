class MaxHeap:
    def __init__(self, capacity=4):
        self.capacity = capacity
        self.size = 0
        self.items = [None] * self.capacity  # Corrected initialization

    def get_left_child_index(self, idx):
        return 2 * idx + 1

    def get_right_child_index(self, idx):
        return 2 * idx + 2

    def get_parent_index(self, idx):
        return (idx - 1) // 2

    def has_left_child(self, idx):
        return self.get_left_child_index(idx) < self.size

    def has_right_child(self, idx):
        return self.get_right_child_index(idx) < self.size

    def has_parent(self, idx):
        return self.get_parent_index(idx) >= 0

    def left_child(self, idx):
        return self.items[self.get_left_child_index(idx)]

    def right_child(self, idx):
        return self.items[self.get_right_child_index(idx)]

    def parent(self, idx):
        return self.items[self.get_parent_index(idx)]

    def ensure_extra_capacity(self):
        if self.capacity == self.size:
            self.capacity *= 2
            self.items.extend([None] * self.capacity)

    def push(self, element):
        self.ensure_extra_capacity()
        if isinstance(element, tuple):
            self.items[self.size] = element
        else:
            # Wrap element in tuple if not already
            self.items[self.size] = (element,)
        self.size += 1
        self.heapify_up()

    def top(self):
        if self.size == 0:
            return None
        return self.items[0]

    def pop(self):
        if self.size == 0:
            return None
        pop_top = self.items[0]
        self.items[0] = self.items[self.size - 1]
        self.size -= 1
        self.heapify_down()
        return pop_top

    def compare(self, a, b):
        """
        Compare two elements. This method ensures that elements of different types
        are compared in a meaningful way.
        """
        # If both elements are of the same type, compare them directly
        if isinstance(a, type(b)):
            return a > b
        # Add custom type comparison logic if needed
        elif isinstance(a, (int, float)) and isinstance(b, (int, float)):
            return a > b
        elif isinstance(a, str) and isinstance(b, str):
            return a > b
        # Default to False if we can't compare (this can be customized)
        return False

    def heapify_up(self):
        current_idx = self.size - 1
        while self.has_parent(current_idx) and self.compare(self.items[current_idx][0], self.parent(current_idx)[0]):
            self.items[current_idx], self.items[self.get_parent_index(current_idx)] = \
                self.items[self.get_parent_index(
                    current_idx)], self.items[current_idx]
            current_idx = self.get_parent_index(current_idx)

    def heapify_down(self):
        current_idx = 0
        while self.has_left_child(current_idx):
            larger_child_idx = self.get_left_child_index(current_idx)
            if self.has_right_child(current_idx) and self.compare(self.right_child(current_idx)[0], self.left_child(current_idx)[0]):
                larger_child_idx = self.get_right_child_index(current_idx)
            if self.compare(self.items[current_idx][0], self.items[larger_child_idx][0]):
                break
            self.items[current_idx], self.items[larger_child_idx] = self.items[larger_child_idx], self.items[current_idx]
            current_idx = larger_child_idx

class MinHeap:
    def __init__(self, capacity=4):
        self.capacity = capacity
        self.size = 0
        self.items = [None] * self.capacity  # Corrected initialization

    def get_left_child_index(self, idx):
        return 2 * idx + 1

    def get_right_child_index(self, idx):
        return 2 * idx + 2

    def get_parent_index(self, idx):
        return (idx - 1) // 2

    def has_left_child(self, idx):
        return self.get_left_child_index(idx) < self.size

    def has_right_child(self, idx):
        return self.get_right_child_index(idx) < self.size

    def has_parent(self, idx):
        return self.get_parent_index(idx) >= 0

    def left_child(self, idx):
        return self.items[self.get_left_child_index(idx)]

    def right_child(self, idx):
        return self.items[self.get_right_child_index(idx)]

    def parent(self, idx):
        return self.items[self.get_parent_index(idx)]

    def ensure_extra_capacity(self):
        if self.capacity == self.size:
            self.capacity *= 2
            self.items.extend([None] * self.capacity)

    def push(self, element):
        self.ensure_extra_capacity()
        if isinstance(element, tuple):
            self.items[self.size] = element
        else:
            # Wrap element in tuple if not already
            self.items[self.size] = (element,)
        self.size += 1
        self.heapify_up()

    def top(self):
        if self.size == 0:
            return None
        return self.items[0]

    def pop(self):
        if self.size == 0:
            return None
        pop_top = self.items[0]
        self.items[0] = self.items[self.size - 1]
        self.size -= 1
        self.heapify_down()
        return pop_top

    def compare(self, a, b):
        """
        Compare two elements. This method ensures that elements of different types
        are compared in a meaningful way.
        """
        # If both elements are of the same type, compare them directly
        if isinstance(a, type(b)):
            return a < b
        # Add custom type comparison logic if needed
        elif isinstance(a, (int, float)) and isinstance(b, (int, float)):
            return a < b
        elif isinstance(a, str) and isinstance(b, str):
            return a < b
        # Default to False if we can't compare (this can be customized)
        return False

    def heapify_up(self):
        current_idx = self.size - 1
        while self.has_parent(current_idx) and self.compare(self.items[current_idx][0], self.parent(current_idx)[0]):
            self.items[current_idx], self.items[self.get_parent_index(current_idx)] = \
                self.items[self.get_parent_index(
                    current_idx)], self.items[current_idx]
            current_idx = self.get_parent_index(current_idx)

    def heapify_down(self):
        current_idx = 0
        while self.has_left_child(current_idx):
            larger_child_idx = self.get_left_child_index(current_idx)
            if self.has_right_child(current_idx) and self.compare(self.right_child(current_idx)[0], self.left_child(current_idx)[0]):
                larger_child_idx = self.get_right_child_index(current_idx)
            if self.compare(self.items[current_idx][0], self.items[larger_child_idx][0]):
                break
            self.items[current_idx], self.items[larger_child_idx] = self.items[larger_child_idx], self.items[current_idx]
            current_idx = larger_child_idx