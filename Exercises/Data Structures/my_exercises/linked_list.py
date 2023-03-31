from typing import Any, Optional


class Node:
      def __init__(self: "Node", value: Any, next: Optional["Node"] = None):
            self.value = value
            self.next = next


class LinkedList:
      def __init__(self: "LinkedList", head: Optional["Node"] = None):
            self.head = head
            self.length = 1 if head is not None else 0
        
      def __len__(self: "LinkedList") -> int:
            return self.length
      
      def __iter__(self: "LinkedList") -> "LinkedList":
            self.current = self.head
            return self
      
      def __next__(self: "LinkedList") -> Any:
            if self.current is None: 
                  raise StopIteration
            
            value = self.current.value
            self.current = self.current.next
            return value
      
      def __add__(self: "LinkedList", other: "LinkedList") -> "LinkedList":
            new = LinkedList()       
            for value in reversed(list(self)):
                  new.append(value)
            for value in reversed(list(other)):
                  new.append(value)
            return new
      
      def __str__(self: "LinkedList") -> str:
            return " -> ".join(map(str, self.list()))
      
      def __getitem__(self: "LinkedList", index: int) -> Any:
            if index < 0: 
                  index = self.length + index
            if index >= self.length:
                  raise IndexError("index out of range")
            return list(self)[index]
      
      def __setitem__(self: "LinkedList", index: int, value: Any) -> None:
            if index < 0: 
                  index = self.length + index
            if index >= self.length:
                  raise IndexError("index out of range")
            current_node = self.head
            for _ in range(index):
                  if current_node is None:
                        raise IndexError("index out of range")
                  current_node = current_node.next
            if current_node is None:
                  raise IndexError("index out of range")
            current_node.value = value
     
      def __eq__(self: "LinkedList", other: "LinkedList") -> bool:
            return all(a == b for a, b in zip(self, other))

      def __ne__(self: "LinkedList", other: "LinkedList") -> bool:
            return not self == other            
      
      def list(self: "LinkedList") -> list[Any]:
            return [value for value in self]
      
      def append(self: "LinkedList", value: Any) -> None:
            if self.head is None:
                  self.head = Node(value)
                  self.length += 1
                  return
            self.head = Node(value, self.head)
            self.length += 1
            return
      
      def pop(self: "LinkedList", *, index: Optional[int] = None) -> Any:
            if self.head is None: 
                  raise IndexError("pop from empty list")
            
            if index is not None and index < 0: 
                  index = self.length + index
                  
            if index is None or index == 0: 
                  self.head = self.head.next
                  return
                  
                  
            current_node = self.head
            for _ in range(index - 1):
                  if current_node.next is None: 
                        raise IndexError("index out of range")
                  current_node  = current_node.next
            
            if current_node.next is None:
                  raise IndexError("index out of range")
            
            value = current_node.next.value
            current_node.next = current_node.next.next 
            self.length -= 1
            return value
      
      def remove(self: "LinkedList", value: Any) -> None:
            if self.head is None:
                  raise IndexError("remove from empty list")
            
            if self.head.value == value:
                  self.head = self.head.next
                  self.length -= 1
                  return
            
            current = self.head
            while current.next is not None:
                  if current.next.value != value:
                        current = current.next
                        continue                  
                  
                  current.next = current.next.next
                  self.length -= 1
                  return
            
            raise ValueError("value not found")
      
      def clear(self: "LinkedList") -> None:
            self.head = None
            self.length = 0
            return
      

if __name__ == '__main__':
      ll1 = LinkedList()
      ll1.append(1)
      ll1.append(2)
      ll1.append(3)
      ll1.append(4)
      
      ll2 = LinkedList()
      ll2.append(6)
      ll2.append(7)
      ll2.append(8)
      
      ll3 = LinkedList()
      ll3.append(6)
      ll3.append(7)
      ll3.append(8)
      
      print(ll1 != ll2)
      print(ll2 != ll3)
      print(ll1 != ll3)