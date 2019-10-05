class Node:
    def __init__(self,val):
        self.value = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def traverse(self):
        curr = self.head
        if curr is None:
            return curr
        while curr.next is not None:
            curr = curr.next
        
        return curr

    def push_node(self, val):
        curr = self.traverse()
        if curr is None:
            self.head = Node(val)
        else:
            curr.next = Node(val)

    def print_list(self):
        curr = self.head
        while curr is not None:
            print(curr.value, end='->')
            curr = curr.next
        print()
    
ll = LinkedList()
ll.push_node(10)
ll.push_node(12)
ll.push_node(19)
ll.print_list()   