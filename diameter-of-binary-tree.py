# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
  def maxDepth(self, root):
    """
    :type root: TreeNode
    :rtype: int
    """
    if not root:
      return 0
    return 1+max(self.maxDepth(root.left), self.maxDepth(root.right))

  def diameterOfBinaryTree2(self, root):
    if not root:
      return 0
    return max(self.diameterOfBinaryTree2(root.left), self.diameterOfBinaryTree2(root.right), 1+self.maxDepth(root.left)+self.maxDepth(root.right))
  
  def diameterOfBinaryTree(self, root):
    if not root:
      return 0
    return self.diameterOfBinaryTree2(root)-1
