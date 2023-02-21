class DSF:
    def __init__(self, nodes):
        self.queue = nodes

    def deq(self):
        return self.queue.pop(0)

    def enq(self, item):
        return self.queue.append(item)

    def search(self):

        for x in self.queue.copy():
            node = self.enq()
            print(node)



DSF(nodes=[
    "a", "b", "c", "d", "e", "f", "g"
]).search()
