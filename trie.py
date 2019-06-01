import collections

class Node:

	def __init__(self):
		self.children = collections.defaultdict(Node)
		self.is_word = False


class Trie:

	def __init__(self):
		"""
		Initialize your data structure here.
		"""
		self.root = Node()

	def insert(self, word: str) -> None:
		"""
		Inserts a word into the trie.
		"""
		curr = self.root
		for c in word:
			curr = curr.children[c]
		curr.is_word = True
		

	def search(self, word: str) -> bool:
		"""
		Returns if the word is in the trie.
		"""
		curr = self.root
		for c in word:
			if curr.children.get(c) == None:
				return False
			curr = curr.children[c]
		return curr.is_word
		

	def startsWith(self, prefix: str) -> bool:
		"""
		Returns if there is any word in the trie that starts with the given prefix.
		"""
		curr = self.root
		for c in prefix:
			if curr.children.get(c) == None:
				return False
			curr = curr.children[c]
		return True
		


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

if __name__ == "__main__":
	trie = Trie()
	trie.insert("word")
	print(trie.search("aladin"))
	print(trie.search("word"))
	print(trie.startsWith("wor"))