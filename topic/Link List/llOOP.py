from typing import Any


class Node:
    def __init__(self,data,prev=None,next=None):
        self.data=data
        self.prev=prev  
        self.next=next
        
    def __str__(self):
        return str(self.data)
    
    
    
class Dll:
    def __init__(self):
        self.__head=None
        self.__tail=None
        self.__size=0
        self.trav=None
    
    def size(self):
        return self.__size
    
    def __increasesize__(self):
        self.__size+=1
        
    
    # def __itr__():
    #     self.trav
    
    
    def __appendHead__(self,node):
        self.__head=node
        self.__tail=self.__head
        self.__size+=1
   

    def append(self,node):
        newNode=Node(node)
        if self.__size==0:
            self.__appendHead__(newNode)
        else:
            self.__tail.next=newNode
            newNode.prev=self.__tail
            self.__tail=newNode
            self.__size+=1
        
    def __str__(self):
        l=[]
        trav=self.__head
        while trav is not None:
            l.append(str(trav.data))
            trav=trav.next
        return str(l)
    
    
    def addFirst(self,node):
        newNode=Node(node)
        if self.__size==0:
            self.__appendHead__(newNode)
        else:
            newNode.next=self.__head
            self.__head.prev=newNode
            self.__head=newNode
            self.__increasesize__()
            
    
    
    def insert(self,node,pos):
        if pos>=self.__size or pos<0:
            return IndexError("Wrong Index")
        newNode=Node(node)
        if pos==0:
            self.__appendHead__(newNode)
        elif pos==self.__size-1:
            self.append(node)
        else:
            trav=self.__head
            for i in range(pos-1):
                trav=trav.next
            newNode.next=trav.next
            newNode.prev=trav
            trav.next=newNode
            newNode.next.prev=newNode
            self.__increasesize__()
            
    def __delHead__(self):
        if self.__size==1:
            self.__head=None
            self.__size-=1
        else:
            itr=self.__head
            itr=itr.next
            self.__head=None
            self.__head=itr
            self.__size-=1
    def __delTail__(self):
        itr=self.__tail.prev
        self.__tail=None
        self.__tail=itr
        self.__size-=1
          
# isme thodi dikkat hai
    def remove(self,pos):
        if self.__size==0:
            return IndexError("Size is already zero")
        if pos==0:
            self.__delHead__()
        elif pos==self.__size-1:
            self.__delTail__()
        else:
            trav=self.__head
            for i in range(pos-1):
                trav=trav.next
            temp=trav.next
            trav.next=trav.next.next
            trav.next.prev=trav
            temp=None
            self.__size-=1
            
            
            
            
            
    
    
# N=Node(10)
# # print(N)                 ## it goes to __str__
# # print(N.data)

l=Dll()
l.append(30)


for i in range(5):
    l.append(10*i)
print(l)
l.insert(55,2)
print(l)
l.remove(7)
print(l)


