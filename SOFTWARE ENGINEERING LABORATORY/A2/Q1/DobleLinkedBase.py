'''
    * Author: Bratin Mondal
    * Roll No: 21CS10016
    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
'''

class _DoubleLinkedBase:
	""" A base class providing a doubly linked list representation."""

	class _Node:
		""" Lightweight, nonpublic class for storing a doubly linked node"""
		__slots__ = '_element', '_prev', '_next' # streamline memory

		def __init__(self, element, prev, next): # initialize node's fields
			self._element = element
			self._prev = prev
			self._next = next

	def __init__(self):
		"""Create an empty list"""
		self._header = self._Node(None, None, None)
		self._trailer = self._Node(None, None, None)
		self._header._next = self._trailer
		self._trailer._prev = self._header
		self._size = 0 # number of elements

	def __len__(self):
		"""Return the number of elements in the list"""
		# ===== Start writing your code here =====
		return self._size
		# ===== End writing your code here =====

	def is_empty(self):
		"""Return true if list is empty"""
		# ===== Start writing your code here =====
		if self._size==0:
			return True
		else:
			return False
		# ===== End writing your code here =====

	def _insert_between(self, e, predecessor, successor):
		"""Add element e between two existing nodes and return new node"""
		newest = self._Node(e, predecessor, successor)
		# ===== Start writing your code here =====
		predecessor._next=newest
		successor._prev=newest
		self._size=self._size+1
		return newest
		# ===== End writing your code here =====

	def _delete_node(self, node):
		"""Delete nonsentinel node from the list and return its elements"""
		# ===== Start writing your code here =====
		if(node!=self._header and node!=self._trailer):
			node._prev._next=node._next
			node._next._prev=node._prev
			self._size=self._size-1
			return node._element
		# ===== End writing your code here =====


	

