#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#include "06Trees.h"

/*****************************************************
 * Que 1. Implementation of Binary Tree Queue
 * and Stack.
 *****************************************************/

/**************************************
 * Binary Tree Queue Implementation
 *************************************/
bool BinaryTreeQueue::IsEmpty()
{
  return front == NULL || rear == NULL;
}
void BinaryTreeQueue::EnQueue(BinaryTreeNode * _data)
{
  if(front == NULL && rear == NULL)
  {
    rear = front = new BinaryTreeQueueNode(_data);
  }
  else
  {
    rear->next = new BinaryTreeQueueNode(_data) ;
    rear = rear->next;
  }
}
BinaryTreeNode* BinaryTreeQueue::DeQueue()
{
  BinaryTreeNode * data = NULL;
  if(!IsEmpty())
  {
    if(front == rear)
    {
	BinaryTreeQueueNode * tNode = front;
	data = front->data;
	front = rear = NULL;
	delete tNode;
    }
    else
    {
	BinaryTreeQueueNode * tNode = front;
	data = front->data;
	front = front->next;
	delete tNode;
    }
  }
  return data;
}
void BinaryTreeQueue::DeleteQueue()
{
  BinaryTreeQueueNode * tNode = NULL;
  while(front)
  {
    tNode = front->next;
    delete front;
    front = tNode;
  }
}
/*****************************************
 * Binary Tree Stack Implementation
 ****************************************/
void BinaryTreeStack::Push(BinaryTreeNode* _data)
{
  BinaryTreeStackNode * tNode = new BinaryTreeStackNode(_data);
  if(!IsEmpty())
  {
      tNode->next = top;
      top = tNode;
  }
  else
     top = tNode;
}
BinaryTreeNode* BinaryTreeStack::Pop()
{
  if(IsEmpty())
    return NULL;
  else
  {
    BinaryTreeNode * _data = top->data;
    BinaryTreeStackNode * tNode = top->next;
    delete top;
    top = tNode;
    return _data;
  }
}
void BinaryTreeStack::DeleteStack()
{
    BinaryTreeStackNode * tNode = NULL;
    while(top)
    {
      tNode = top->next;
      delete top;
      top = tNode;
    }
}
/*****************************************
 * Normal Binary Tree Implementation
 ****************************************/
void BinaryTree::InsertNode(int data)
{
  if(root == NULL)
    root = new BinaryTreeNode(data);
  else
  {
      BinaryTreeNode * nNode = new BinaryTreeNode(data);
      BinaryTreeNode * tNode;
      BinaryTreeQueue queue;
      queue.EnQueue(root);
      while(!queue.IsEmpty())
      {
	tNode = queue.DeQueue();
	
	if(tNode->left) 
	   queue.EnQueue(tNode->left);
	 else
	 {
	    //Insert Node here
	    tNode->left = nNode;
	    //Free Queue
	    queue.DeleteQueue();
	    return;
	 }
	 if(tNode->right)
	   queue.EnQueue(tNode->right);
	 else
	 {
	    //Insert Node here
	   tNode->right = nNode;
	   //Free Queue
	   queue.DeleteQueue();
	   return;
	 }
      }
  }
}
/**************************************************
 * Que 2. InOrder Traversal Recursion
 * 
 * Time Complexity  : O(n)
 * Space Complexity : O(n) Due to recursion
 * ***********************************************/
void BinaryTree::InOrderTraversal(BinaryTreeNode* root)
{
  if(root)
  {
    InOrderTraversal(root->left);
    printf("%d ",root->data);
    InOrderTraversal(root->right);
  }
}
/**************************************************
 * Que 3. InOrder Traversal Without Recursion
 * 
 * Time Complexity  : O(n)
 * Space Complexity : O(n) Due to recursion
 * ***********************************************/
void BinaryTree::InOrderTraversalWORecursion(BinaryTreeNode* root)
{
  if(!root) return;
 
  BinaryTreeNode * tNode;
  BinaryTreeStack stack;
  
  while(true)
  {
    while(root)
    {
      stack.Push(root);
      root = root->left;
    }
    
    if(stack.IsEmpty())
      break;
    
    tNode = stack.Pop();
    printf("%d ",tNode->data);
    
    root = tNode->right;
  }
  stack.DeleteStack();
}
/******************************************************
 * Que 4. PreOrder Traversal with Recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::PreOrderTraversal(BinaryTreeNode* root)
{
   if(root)
   {
      printf("%d ",root->data);
      PreOrderTraversal(root->left);
      PreOrderTraversal(root->right);
   }
}
/******************************************************
 * Que 5. PreOrder Traversal without Recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::PreOrderTraversalWORecursion(BinaryTreeNode* root)
{
    BinaryTreeStack stack;
    
    while(true)
    {
       while(root)
       {
		   printf("%d ",root->data);
		   if(root->left)
			   stack.Push(root);
		   root = root->left;
       }
       
       if(stack.IsEmpty())
		   break;
       
       root = stack.Pop();
       root = root->right;
    }
    //Delete stack
    stack.DeleteStack();
}
/******************************************************
 * Que 6. PostOrder Traversal with Recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::PostOrderTraversal(BinaryTreeNode* root)
{
  if(root)
  {
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    printf("%d ",root->data);
  }
}
/******************************************************
 * Que 7. PostOrder Traversal with out Recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::PostOrderTraversalWORecursion(BinaryTreeNode* root)
{
  if(root == NULL)
    return;
  
  BinaryTreeStack stack;

  do {
    
    while(root)
    {
		if(root->right)
		  stack.Push(root->right);
		stack.Push(root);
		root = root->left;
    }
    
    root = stack.Pop();
    
    if(root->right && stack.Top() == root->right)
    {
		stack.Pop();
		stack.Push(root);
		root = root->right;
    }
    else
    {
		printf("%d ",root->data);
		root = NULL;
    }
  } while(!stack.IsEmpty());
  
  //Delete Stack
  stack.DeleteStack();
}
/******************************************************
 * Que 8. Level Order Traversal with out Recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::LevelOrderTraversal(BinaryTreeNode* root)
{
   if(!root)
     return;
   
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      printf("%d ",root->data);
      
      if(root->left)  queue.EnQueue(root->left);
      if(root->right) queue.EnQueue(root->right);
   }
   queue.DeleteQueue();
}
/******************************************************
 * Que 9. Find Maximum element of binary tree
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindMax(BinaryTreeNode* root)
{
  if(root)
  {
     int left  = FindMax(root->left);
     int right = FindMax(root->right);
     if(root->data > left && root->data > right)
       return root->data;
     else if(left > root->data && left > right)
       return left;
     else
       return right;
  }
  return -1;
}
/******************************************************
 * Que 10. Find Maximum element of binary tree without
 *      Recursion
 * 
 * Comment : Use level order traversal to find max
 * element
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindMaxWORecursion(BinaryTreeNode* root)
{
   if(!root) return -1;
   int data = -1;
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(data < root->data) data = root->data;
      if(root->left) queue.EnQueue(root->left);
      if(root->right)queue.EnQueue(root->right);
   }
  return data;
}
/******************************************************
 * Que 11. Find element of binary tree with Recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
bool BinaryTree::FindElement(BinaryTreeNode* root, int data)
{
  if(!root) return false;
  if(root->data == data) return true;
  
  return FindElement(root->left,data) || FindElement(root->right,data);
}
/******************************************************
 * Que 12. Find element of binary tree without Recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
bool BinaryTree::FindElementWORecursion(BinaryTreeNode* root, int data)
{
   if(!root) return false;
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(root->data == data)
      {
	queue.DeleteQueue();
	return true;
      }
      if(root->left) queue.EnQueue(root->left);
      if(root->right)queue.EnQueue(root->right);
   }
   queue.DeleteQueue();
   return false;
}
/******************************************************
 * Que 13. Find Size of binary tree with recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindSize(BinaryTreeNode* root)
{
   if(!root) return 0;
   
   return FindSize(root->left) + 1 + FindSize(root->right);
}
/******************************************************
 * Que 14. Find Size of binary tree without recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindSizeWORecursion(BinaryTreeNode* root)
{
    if(!root) return 0;
    BinaryTreeQueue queue;
    queue.EnQueue(root);
    int count;
    while(!queue.IsEmpty())
    {
      root = queue.DeQueue();
      count++;
      if(root->left) queue.EnQueue(root->left);
      if(root->right)queue.EnQueue(root->right);
    }
    return count;
}
/******************************************************
 * Que 15. Print level traversal order in reverse order
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::LevelOrderTraversalReverse(BinaryTreeNode* root)
{
   if(!root) return;
   BinaryTreeQueue queue;
   BinaryTreeStack stack;
   queue.EnQueue(root);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      stack.Push(root);
      if(root->left) queue.EnQueue(root->left);
      if(root->right)queue.EnQueue(root->right);
   }
   while(!stack.IsEmpty())
   {
      printf("%d ",stack.Pop()->data);
   }
   printf("\n");
   stack.DeleteStack();
   queue.DeleteQueue();
}
/******************************************************
 * Que 16. Find algorithm to delete tree
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::DeleteTree(BinaryTreeNode* root)
{
    if(!root) return;
    BinaryTreeNode * left = root->left;
    BinaryTreeNode * right = root->right;
    delete root;
    DeleteTree(left);
    DeleteTree(right);
}
/******************************************************
 * Que 17. Find Height of tree with recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindHeight(BinaryTreeNode* root)
{
  if(!root) return 0;
  int left =  FindHeight(root->left);
  int right = FindHeight(root->right);
  
  return left > right ? left + 1 : right + 1;
}
/******************************************************
 * Que 18. Find Height of tree without recursion
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindHeightWORecursion(BinaryTreeNode* root)
{
  if(!root) return 0;
  int level = 0;
  BinaryTreeQueue queue;
  queue.EnQueue(root);
  queue.EnQueue(NULL);
  while(!queue.IsEmpty())
  {
    root = queue.DeQueue();
    if(root == NULL)
    {
      if(!queue.IsEmpty())
	queue.EnQueue(NULL);
      level++;
    }
    else
    {
      if(root->left)  queue.EnQueue(root->left);
      if(root->right) queue.EnQueue(root->right);
    }
  }
  return level;
}
/******************************************************
 * Que 19. Find the deepest node in binary tree.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
BinaryTreeNode *  BinaryTree::FindDeepestNode(BinaryTreeNode* root)
{
   if(!root) return 0;
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(root->left)  queue.EnQueue(root->left);
      if(root->right) queue.EnQueue(root->right);
   }
   return root;
}
/******************************************************
 * Que 20. Delete Node from binary tree
 * 
 * Comment : 1) Find the node to be deleted.
 * 	     2) Find the deepest node of the tree
 * 	     3) Swap these nodes
 * 	     4) Delete the deepest node
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::DeleteNode(BinaryTreeNode* root,int data)
{
  BinaryTreeNode * tNode = FindNode(root,data);
  BinaryTreeNode * dNode = FindDeepestNode(root);
  
  //Swap
  int temp = tNode->data;
  tNode->data = dNode->data;
  dNode->data = temp;
  
  //Delete Deepest Node
  DeleteGivenNode(dNode,root);
}
BinaryTreeNode* BinaryTree::FindNode(BinaryTreeNode* root, int data)
{
   if(root)
   {
      if(root->data == data) 
	return root;
      BinaryTreeNode * left  = FindNode(root->left,data);
      BinaryTreeNode * right = FindNode(root->right,data);
      if(left) return left;
      if(right)return right;
      return NULL;
   }
   return NULL;
}
void BinaryTree::DeleteGivenNode(BinaryTreeNode * dNode,BinaryTreeNode* root)
{
   if(!root) return;
   
   if(root->right && root->right == dNode)
   {
      delete dNode;
      root->right = NULL;
      return;
   }
   else if(root->left && root->left == dNode)
   {
     delete dNode;
     root->left = NULL;
     return;
  }
  DeleteGivenNode(dNode,root->left);
  DeleteGivenNode(dNode,root->right);
}
/******************************************************
 * Que 21. Count the number of leaves in given binary
 * 	   Tree.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindLeaves(BinaryTreeNode* root)
{
   int count = 0;
   if(!root) return count;
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(root->left == NULL && root->right == NULL)
	count++;
      if(root->left)  queue.EnQueue(root->left);
      if(root->right) queue.EnQueue(root->right);
   }
   queue.DeleteQueue();
   return count;
}
/******************************************************
 * Que 22. Count the number of Full nodes in the binary
 * 	   Tree.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindFullNodes(BinaryTreeNode* root)
{
   int count = 0;
   if(!root) return count;
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(root->right && root->left) count++;
      if(root->right) queue.EnQueue(root->right);
      if(root->left)  queue.EnQueue(root->left);
   }
   queue.DeleteQueue();
   return count;
}
/******************************************************
 * Que 23. Count the number of Half nodes in the binary
 * 	   Tree.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindHalfNodes(BinaryTreeNode* root)
{
   int count = 0;
   if(!root) return count;
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(root->right && !root->left || !root->right && root->left) count++;
      if(root->right) queue.EnQueue(root->right);
      if(root->left)  queue.EnQueue(root->left);
   }
   queue.DeleteQueue();
   return count;
}
/******************************************************
 * Que 24. Compair Two trees return true if identical
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
bool BinaryTree::CompairTwoBinaryTrees(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if(!root1 && !root2)
      return true;
    if(!root1 || !root2)
      return false;
    if(root1->data != root2->data)
      return false;
    
    return CompairTwoBinaryTrees(root1->left,root2->left) && 
           CompairTwoBinaryTrees(root1->right,root2->right);
}
/******************************************************
 * Que 25. Find the diameter of tree
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::DiameterOfTree(BinaryTreeNode* root)
{
  if(!root) return 0;
  
  int leftHeight  = HeightOfTree(root->left);
  int rightHeight = HeightOfTree(root->right);
  
  int leftDia  = DiameterOfTree(root->left);
  int rightDia = DiameterOfTree(root->right);
  
  return Max(leftHeight + rightHeight + 1, Max(leftDia,rightDia));
}
int BinaryTree::HeightOfTree(BinaryTreeNode* root)
{
   if(!root) return 0;
   return 1 + Max(HeightOfTree(root->left),HeightOfTree(root->right));
}
int Max(int a, int b)
{
  return a > b ? a : b;
}
/******************************************************
 * Que 26. Find Level with maximum sum in binary tree
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
int BinaryTree::FindMaxSumLevel(BinaryTreeNode* root)
{
   if(!root) return 0;
   
   int maxSum = -1;
   int maxLevel = 0;
   int cSum = 0;
   int cLevel = 0;
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   queue.EnQueue(NULL);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(root == NULL)
      {
	if(cSum > maxSum)
	{
	  maxLevel = cLevel;
	  maxSum = cSum;
	}
	if(!queue.IsEmpty())
	{
	  queue.EnQueue(NULL);
	}
	cSum = 0;
	cLevel++;
      }
      else
      {
	cSum += root->data;
	if(root->left)  queue.EnQueue(root->left);
	if(root->right) queue.EnQueue(root->right);
      }
   }
   queue.DeleteQueue();
   return maxLevel;
}
/******************************************************
 * Que 27. Print all the possible paths from root to 
 * 	   leaves
 * 
 * Comment : Back Tracking
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * ***************************************************/
void BinaryTree::PrintAllPathsToLeaves(BinaryTreeNode* root, int path[], int pathLen)
{
   if(!root) return;
   if(root->right || root->left) 
      path[pathLen++] = root->data;
   else if(!root->right && !root->left)
   {
      path[pathLen++] = root->data;
      PrintPath(path,pathLen);
      return;
   }
   if(root->left)   PrintAllPathsToLeaves(root->left,path,pathLen);
   if(root->right)  PrintAllPathsToLeaves(root->right,path,pathLen);
}
void BinaryTree::PrintPath(int path[], int pathLen)
{
   for(int i=0;i<pathLen;i++)
     printf("%d->",path[i]);
   printf("Leave\n");
}
/************************************************************
 * Que 28. Give an algorithm for checking the existence 
 * of path with given sum. That means, given a sum check 
 * whether there exists a path from root to any of the nodes.
 * 
 * Comment : 1) Back Tracking
 * 	     2) Substract current node vlaue from total sum 
 * 		& call same function for sum-data value
 *           3) Return true if given path is found
 * 	     4) Print the path
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * **********************************************************/
bool BinaryTree::PrintAllPathsWithSum(BinaryTreeNode* root, int path[], int pathLen,int sum)
{
   if(!root) 
     return false;
   if(root->data == sum && !root->right && !root->left)
   {
      path[pathLen++] = root->data;
      PrintPath(path,pathLen);
      return true;
   }
   
   if(sum - root->data < 0) 
     return false;
   
   path[pathLen++] = root->data;
   
   bool bleft  = PrintAllPathsWithSum(root->left,path,pathLen,sum - root->data);
   bool bright = PrintAllPathsWithSum(root->right,path,pathLen,sum - root->data); 
   
   return (bleft || bright);
          
}
/***************************************************************
 * Que 29. Find sum of all elements in binary tree
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * ************************************************************/
int BinaryTree::FindSumOfAllElement(BinaryTreeNode* root)
{
    if(!root) return 0;
    return (root->data + 
	    FindSumOfAllElement(root->left) + 
	    FindSumOfAllElement(root->right));
}
/***************************************************************
 * Que 30. Find LCA (Least common ancestor) of two given nodes 
 * of given tree
 * 
 * Comment : 1) LCA will be parent of both the nodes.
 * 
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * *************************************************************/
int BinaryTree::FindLCA(BinaryTreeNode* root, int a, int b)
{
   if(!root) 
     return -1;

   bool lNode = FindNode(root->left,a) && FindNode(root->right,b);
   bool rNode = FindNode(root->left,b) && FindNode(root->right,a);

   if(lNode || rNode)
   {
      //Parent Found
      return root->data;
   }
   int leftFound  = FindLCA(root->left,a,b);
   int rightFound = FindLCA(root->right,a,b);
   
   if(leftFound != -1 || rightFound != -1)
   {
      return leftFound != -1 ? leftFound : rightFound;
   }
   return  -1;
}
bool BinaryTree::CheckNode(BinaryTreeNode* root, int a)
{
   if(!root) return false;
   if(root->data == a) return true;
   return CheckNode(root->left,a) || CheckNode(root->right,a);
}
/***************************************************************
 * Que 31. Create Binary tree from inorder and preorder 
 *         Traversal
 * 
 * Comments   : 1) From preOrder traversal have the first element
 * 		   it will be the root of the tree.
 * 		2) inOrder traversal position of the element gives 
 * 		   right and left sub tree of the root node;
 * 		3) Method can be called recursively.
 * 
 * 
 * Parameters : InOrder Traversal
 *              PreOrder Traversal
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * *************************************************************/
BinaryTreeNode* BinaryTree::ConstructBinaryTreeFromInOrderANDPreOrder(int inOrder[], int preOrder[], int inStr,int endStr,bool _reset)
{
  static int preIndex = 0; if(_reset) preIndex = 0;
  if(inStr > endStr) return NULL;
  
  BinaryTreeNode * nNode = NULL;
  nNode = new BinaryTreeNode(preOrder[preIndex]);
  preIndex++;
  if(inStr == endStr)
    return nNode;
  
  int inIndex = SearchIndex(inOrder,inStr,endStr,nNode->data);
  if(inIndex == -1)
  {
    printf("NULL\n");
    return NULL;
  }
  
  nNode->left  = ConstructBinaryTreeFromInOrderANDPreOrder(inOrder,preOrder,inStr,inIndex - 1);
  nNode->right = ConstructBinaryTreeFromInOrderANDPreOrder(inOrder,preOrder,inIndex + 1,endStr);
  
  return nNode;
}
int BinaryTree::SearchIndex(int inOrder[], int inStr, int endStr, int data)
{
  for(int i=inStr;i<=endStr;i++)
  {
    if(data == inOrder[i])
      return i;
  }
  return -1;
}
/***************************************************************
 * Que 32. Create Binary tree from inorder and postOrder
 *         Traversal
 * ***********
 * NOT WORKING
 * *********** 
 * Parameters : InOrder Traversal
 *              PostOrder Traversal
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * *************************************************************/
BinaryTreeNode* BinaryTree::ConstructBinaryTreeFromInOrderANDPostOrder(int inOrder[], int postOrder[], int inStr, 
								       int endStr, bool _reset)
{
  static int preIndex = endStr; if(_reset) preIndex = endStr;
  if(inStr > endStr) return NULL;
  
  BinaryTreeNode * nNode = NULL;
  nNode = new BinaryTreeNode(postOrder[preIndex]);
  preIndex--;
  if(inStr == endStr)
    return nNode;
  
  int inIndex = SearchIndex(inOrder,inStr,endStr,nNode->data);
  if(inIndex == -1)
  {
    printf("NULL\n");
    return NULL;
  }
  
  nNode->left  = ConstructBinaryTreeFromInOrderANDPostOrder(inOrder,postOrder,inStr,inIndex - 1);
  nNode->right = ConstructBinaryTreeFromInOrderANDPostOrder(inOrder,postOrder,inIndex + 1,endStr);
  
  return nNode;
}
/****************************************************************
 * Que 33. Print all the ancestor of the given node
 * 
 * Comments : BackTracking
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * 
 * **************************************************************/
void BinaryTree::PrintAllAncestor(BinaryTreeNode* root, int path[], int pathLen, int data)
{
   if(!root) return;
   
   if(root->data == data)
   {
      path[pathLen++] = data;
      PrintPath(path,pathLen);
      return;
   }
   path[pathLen++] = root->data;
   PrintAllAncestor(root->left,path,pathLen,data);
   PrintAllAncestor(root->right,path,pathLen,data);
}
/****************************************************************
 * Que 34. Give an algorithm for printing the nodes in Zig-Zag 
 * Order. For Example
 * 
 *                       1
 *                      / \
 *                     2   3
 *                    /\   /\
 *                   4 5   6 7
 * 
 * Output will be :  1 3 2 4 5 6 7
 * 
 * Comments :  1) Traverse nodes in level-order traversal
 *             2) Use stack to print alternate leve nodes.
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * 
 * **************************************************************/
void BinaryTree::LevelOrderTraversalZigZag(BinaryTreeNode* root)
{
   if(!root) return;
   
   BinaryTreeQueue queue;
   BinaryTreeStack stack;
   bool pReverse = false;
   queue.EnQueue(root);
   queue.EnQueue(NULL);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue(); 
      if(root == NULL)
      {
	if(!queue.IsEmpty())
	  queue.EnQueue(NULL);
	if(pReverse)
	{
	  while(!stack.IsEmpty())
	    printf("%d ",stack.Pop()->data);
	}
	printf("\n");
	pReverse = pReverse ? false : true;
      }
      else
      {
	  if(pReverse)
	    stack.Push(root);
	  else
	    printf("%d ",root->data);
	  if(root->left)  queue.EnQueue(root->left);
	  if(root->right) queue.EnQueue(root->right);
      }
   }
   queue.DeleteQueue();
   stack.DeleteStack();
   return;
}
/**************************************************************
 * Que 35. Given a tree with a special property where 
 * leaes are represented with '0' and internal nodes are 
 * represented as '2' Also assume each node can have one 
 * or two children. Given preorder traversal of this tree. 
 * Construct the binary tree.
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * 
 * ***********************************************************/
BinaryTreeNode *  BinaryTree::ConstructBinaryTreeFromPreOrder(int preOrder[], int sIndex, int eIndex,bool _reset)
{
   if(sIndex > eIndex ) return NULL;
   static int index = 0;
   if(_reset) index = 0;
   
   BinaryTreeNode * nNode = new BinaryTreeNode(preOrder[index++]);
   
   if(sIndex == eIndex)
     return nNode;
   
   if(nNode->data == 0)
     return nNode;
   
   nNode->left  = ConstructBinaryTreeFromPreOrder(preOrder,++sIndex,eIndex);
   nNode->right = ConstructBinaryTreeFromPreOrder(preOrder,++sIndex,eIndex);
   
   return nNode;
}
/**************************************************************
 * Que 36. Given two trees are said to be isomorphic. if they
 * have the same structure. the values of node does not affect
 * if two trees are isomorphic tree or not.
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * 
 * ***********************************************************/
bool BinaryTree::CheckIsomorphicTrees(BinaryTreeNode* roo1, BinaryTreeNode* root2)
{
   if(!roo1 && !root2)
     return true;
   if(!roo1 || !root2)
     return false;
   return CheckIsomorphicTrees(roo1->left,root2->left) &&
          CheckIsomorphicTrees(roo1->right,root2->right);
}
/**************************************************************
 * Que 37. Given two trees are said to be quasi-isomorphic if 
 * root1 can be transformed into root2 by swapping left and right
 * children of some of the nodes of root1. The data in the nodes
 * are not important in checking for quasi-isomorphic.
 * 
 * Time  Complexity : O(N)
 * Space Complexity : O(N)
 * 
 * ***********************************************************/
bool BinaryTree::CheckQuasiIsomorphicTrees(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
   if(!root1 && !root2)
     return true;
   if(!root1 || !root2)
     return false;
   return CheckQuasiIsomorphicTrees(root1->left,root2->left) && CheckQuasiIsomorphicTrees(root1->right,root2->right) ||
          CheckQuasiIsomorphicTrees(root1->right,root2->left)&& CheckQuasiIsomorphicTrees(root1->left,root2->right);
}
/*************************************************************
 * Que 38. Find InOrder Successor of the given node in binary
 * Tree.
 * 
 * Comments  : 1) Find key node and find the next inorder 
 * 		traversal node.
 * 
 * Time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
BinaryTreeNode* BinaryTree::FindInOrderSuccessor(BinaryTreeNode* root,int key)
{
   if(!root) return NULL;
   BinaryTreeNode * tNode = root;
   bool found = false;
   
   BinaryTreeStack stack;
   
   while(true)
   {
      while(root)
      {
	 stack.Push(root);
	 root = root->left;
      }
      
      if(stack.IsEmpty())
	break;
      
      tNode = stack.Pop();
      
      if(found)
      {
	stack.DeleteStack();
	return tNode;
      }
	
      if(tNode->data == key)
	found = true;
      
      root = tNode->right;
   }
   stack.DeleteStack();
   return NULL;
}
/*************************************************************
 * Que 39. Find PreOrder Successor of the given node in binary
 * Tree.
 * 
 * Comment  : Find the key node and find the next node in 
 * preOrder traversal.
 * 
 * Time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
BinaryTreeNode* BinaryTree::FindPreOrderSuccessor(BinaryTreeNode* root, int key)
{
   if(!root) return NULL;
   BinaryTreeStack stack;
   bool found = false;
   while(true)
   {
      while(root)
      {
	if(found)
	{
	  stack.DeleteStack();
	  return root;
	}
	
	if(root->data == key)
	  found = true;
	
	stack.Push(root);
	root = root->left;
      }
      
      if(stack.IsEmpty())
	break;
      
      root = stack.Pop();
      root = root->right;
      
   }
   stack.DeleteStack();
   return NULL;
}
/*************************************************************
 * Que 40. Find PostOrder Successor of the given node in binary
 * Tree.
 * 
 * Comment  : Find the key node and find the next node in 
 * preOrder traversal.
 * 
 * Time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
BinaryTreeNode* BinaryTree::FindPostOrderSuccessor(BinaryTreeNode* root, int key)
{
   if(!root) return NULL;
   
   bool found = false;
   BinaryTreeStack stack;
   
   while(true)
   {
      while(root)
      {
	if(root->right)
	  stack.Push(root->right);
	stack.Push(root);
	root = root->left;
      }
      
      if(stack.IsEmpty())
	break;
      
      root = stack.Pop();
      
      if(root->right && root->right == stack.Top())
      {
	  stack.Pop();
	  stack.Push(root);
	  root = root->right;
      }
      else
      {
	  if(found)
	  {
	    stack.DeleteStack();
	    return root;
	  }
	  
	  if(key == root->data)
	    found = true;
	  
	  root = NULL;
      }
   }
   
   stack.DeleteStack();
   return NULL;
}
/************************************************************
 * INSERT BINARY SEARCH TREE NODE
 * *********************************************************/
void BinarySearchTree::InsertNode(int data)
{
   if(root == NULL)
    root = new BinaryTreeNode(data);
   else
   {
      BinaryTreeNode * tNode = root;
      while(true)
      {
	if(data < tNode->data)
	{
	  if(tNode->left == NULL)
	  {
	    tNode->left = new BinaryTreeNode(data);
	    return;
	  }
	  tNode = tNode->left;
	}
	else if(data > tNode->data)
	{
	  if(tNode->right == NULL)
	  {
	    tNode->right = new BinaryTreeNode(data);
	    return;
	  }
	  tNode = tNode->right;
	}
	else
	{
	  //Node->data and node to be added data is same.
	  return;
	}
      }
   }
}
/*************************************************************
 * Que 41. Find a element in given binary search tree
 * 
 * Comment  : if found for current node return true
 * 	      if not found search in appropriate sub-tree.
 * 
 * Time  Complexity  : O(nlogn) avg case
 * Worst case timeComplexity : O(N)
 * Space Complexity  : O(n)
 * 
 * ***********************************************************/
bool BinarySearchTree::SearchElement(BinaryTreeNode* root, int data)
{
   if(!root) return false;
   if(root->data == data) return true;
   
   if(data < root->data)
     return SearchElement(root->left,data);
   return SearchElement(root->right,data);
}
/*************************************************************
 * Que 42. Find min element in given binary search tree
 * 
 * Comment  : Find the leftmost element of the tree
 * 
 * Time  Complexity  : O(nlogn) avg case
 * Worst case timeComplexity : O(N)
 * Space Complexity  : O(n)
 * 
 * ***********************************************************/
int BinarySearchTree::SearchMin(BinaryTreeNode* root)
{
   if(!root) return -1;
   if(root->left == NULL)
     return root->data;
   else
     return SearchMin(root->left);
}
/*************************************************************
 * Que 43. Find maximum element in given binary search tree
 * 
 * Comment  : Find the right most element of the tree
 * 
 * Time  Complexity  : O(nlogn) avg case
 * Worst case timeComplexity : O(N)
 * Space Complexity  : O(n)
 * 
 * ***********************************************************/
int BinarySearchTree::SearchMax(BinaryTreeNode* root)
{
   if(!root) return -1;
   if(root->right == NULL)
     return root->data;
   else
     return SearchMax(root->right);
}
/*************************************************************
 * Que 44. Delete a given node from binary search tree
 * 
 * Comment  : 1) Find the node to delete.
 * 	      2) Consider node with one child and node with
 * 		 single child case.
 * 
 * Time  Complexity  : O(nlogn) avg case
 * Worst case timeComplexity : O(N)
 * Space Complexity  : O(n)
 * 
 * ***********************************************************/
BinaryTreeNode * BinarySearchTree::DeleteNode(BinaryTreeNode* root, int data)
{
    if(!root) 
    { 
      printf("Element not in Tree.\n");
      return NULL;
    }
    if(root->data > data)
      root->left = DeleteNode(root->left,data);
    else if(root->data < data)
      root->right = DeleteNode(root->right,data);
    else
    {
       //Element found
       if(root->right && root->left)
       {
	  //Node with both child
	  //Replace with largest in left substree
	 BinaryTreeNode * tNode = SearchMaxNode(root->left);
	 root->data = tNode->data;
	 root->left = DeleteNode(root->left,root->data);
       }
       else
       {
	  //Node with single substree
	  BinaryTreeNode * tNode = root;
	  if(!root->left)
	    root = root->right;
	  else if(!root->right)
	    root = root->left;
	  delete tNode;
       }
    }
    return root;
}
/* Utility function to find max node */
BinaryTreeNode* BinarySearchTree::SearchMaxNode(BinaryTreeNode* root)
{
   if(!root) return NULL;
   if(root->right)
     return SearchMaxNode(root->right);
   return root;
}
/*************************************************************
 * Que 45. Find the LCA of two given nodes
 * 
 * Comment  : 
 * 
 * Time  Complexity  : O(nlogn) avg case
 * Worst case timeComplexity : O(N)
 * Space Complexity  : O(n)
 * 
 * ***********************************************************/
int BinarySearchTree::FindLCA(BinaryTreeNode* root, int a, int b)
{
    while(true)
    {
	if(!root) break;
	if(a < root->data && root->data < b || a > root->data && root->data > b )
	  return root->data;
	if(a < root->data)
	  root = root->left;
	else
	  root = root->right;
    }
    return -1;
}
/*************************************************************
 * Que 46. Check whether a given binary tree is BST or not
 * 
 * Comment  : 
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(n)
 * 
 * ***********************************************************/
bool BinarySearchTree::IsBST(BinaryTreeNode* root)
{
   if(!root)
     return true;
   if(root->left && root->left->data > root->data)
     return false;
   if(root->right && root->right->data < root->data)
     return false;
   return IsBST(root->left) && IsBST(root->right);
}
/*************************************************************
 * Que 47. Check whether a given binary tree is BST or not
 * More correct algorithm
 * 
 * Comment  : 
 * 
 * time  Complexity  : O(N^2)
 * Space Complexity  : O(1)
 * 
 * ***********************************************************/
bool BinarySearchTree::IsBST(BinaryTreeNode* root, bool _reset)
{
    if(!root) return true;
    if(root->right && root->data > SearchMax(root->right) || root->left && root->data < SearchMin(root->left))
      return false;
    return IsBST(root->left,false) && IsBST(root->right,false);
}
/*************************************************************
 * Que 48. Check whether a given binary tree is BST or not
 * More correct algorithm
 * 
 * Comment  : 1) To make the BST balanced durint each iteration
 * 		 select middle element.
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
BinaryTreeNode* BinarySearchTree::CreateBSTFromSortedArray(int A[], int left, int right)
{
    if(left > right) return NULL;
    int mid = (left + right) / 2;
    
    BinaryTreeNode * nNode = new BinaryTreeNode(A[mid]);
    
    if(right == left)
      nNode->data = A[left]  ;
    else
    {
      nNode->data = A[mid];
      nNode->left = CreateBSTFromSortedArray(A,left,mid-1);
      nNode->right= CreateBSTFromSortedArray(A,mid+1,right);
    }
    return nNode;
}
/*************************************************************
 * Que 49. Find Kth smallest node in Binary search tree
 * 
 * Comment  : 
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
int BinarySearchTree::SearchKthMin(BinaryTreeNode* root, int k, int& count)
{
   if(!root) return -1;
   int data = -1;
   if(root->left) data = SearchKthMin(root->left,k,count);
   if(data != -1) return data;
   if(++count == k)
     return root->data;
   return SearchKthMin(root->right,k,count);
}
/*************************************************************
 * Que 50. If a given key is less than the key at the root of
 * the BST then floor of key (less than or equal to key).
 * 
 * Comment  : 1) Use Inorder traversal if element is found
 * 		return the element otherwise just return element
 * 		which are just less than key.
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
int BinarySearchTree::Floor(BinaryTreeNode* root, int key,int pValue)
{
    if(!root)
    {
	if(pValue <= key)
	  return pValue;
	return -1;
    }
    
    if(root->data == key) 
      return key;
    
    int data = -1;
    if(root->left)
    data = Floor(root->left,key,root->data);
    
    if(data != -1 && root->data > key)
      return data;
    
    if(root->data > key && pValue != 0)
      return pValue;
    
    return Floor(root->right,key,root->data);
}
/*************************************************************
 * Que 51. Find ceiling of the given value.
 * 
 * Comment  : 1) use Inorder traversal for check for key.
 * 		if key is present return value.
 * 	      2) if key is not present return next element
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
int BinarySearchTree::Ceiling(BinaryTreeNode* root, int key,int pValue)
{
    if(!root)
    {
	if(pValue >= key)
	  return pValue;
	return -1;
    }
    
    if(root->data == key) 
      return key;
    
    int data = -1;
    if(root->left)
    data = Ceiling(root->left,key,root->data);
    
    if(data != -1 && root->data > key)
      return data;
    
    if(root->data > key && pValue != 0 && pValue < key)
      return root->data;
    
    return Ceiling(root->right,key,root->data);
}
/*************************************************************
 * Que 52. Print all element in given range K1 to K2
 * 
 * Comment  : 1)Print root->data if K1 <= root->data <= K2
 * 	      2)Use Inorder traversal	
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
void BinarySearchTree::PrintInRange(BinaryTreeNode* root, int K1, int K2)
{
    if(!root) return;
    
    if(root->data >= K1)
      PrintInRange(root->left,K1,K2);
    if(root->data >= K1 && root->data <= K2)
      printf("%d ",root->data);
    if(root->data <= K2)
      PrintInRange(root->right,K1,K2);
}
/*************************************************************
 * Que 53. Print all element in given range K1 to K2 using 
 * Queue
 * 
 * Comment  : 	1)Print root->data if K1 <= root->data <= K2
 * 	      	2)EnQueue nodes which are found in range
 * 	      	3)Use Level Order traversal
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
void BinarySearchTree::PrintInRangeQueue(BinaryTreeNode* root, int K1, int K2)
{
    if(!root) return;
    BinaryTreeQueue queue;
    queue.EnQueue(root);
    while(!queue.IsEmpty())
    {
	root = queue.DeQueue();
	if(root->data >= K1 && root->data <= K2)
	  printf("%d ",root->data);
	if(root->left && root->data >= K1)
	  queue.EnQueue(root->left);
	if(root->right && root->data <= K2)
	  queue.EnQueue(root->right);
    }
    queue.DeleteQueue();
}
/*************************************************************
 * Que 54. Compair two BSTs. If both have same set of elements
 * return true, else false.
 * 	
 * Comment  :	Use inorder traversal to get ordered element 
 *		Compair retreived sets if equal return true
 *  	     	else false.
 * 
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
bool BinarySearchTree::CompairBinaryTrees(BinarySearchTree& tree1, BinarySearchTree& tree2)
{
   int tree1Elements[128];
   int tree1Count = 0;
   int tree2Elements[128];
   int tree2Count = 0;
   
   //Populate sets
   tree1.PopulateInOrderSet(tree1.GetRoot(),tree1Elements,tree1Count);
   tree2.PopulateInOrderSet(tree2.GetRoot(),tree2Elements,tree2Count);
   
   for(int i=0;i<tree1Count;i++)
     printf("%d ",tree1Elements[i]);
   NL;
   
   for(int i=0;i<tree2Count;i++)
     printf("%d ",tree2Elements[i]);
   NL;   
   
   if(tree1Count != tree2Count)
     return false;
   for(int i=0;i<tree1Count;i++)
     if(tree1Elements[i] != tree2Elements[i])
       return false;
   
   return true;
}
void BinarySearchTree::PopulateInOrderSet(BinaryTreeNode* root, int A[], int& count)
{
    if(!root) return;
    PopulateInOrderSet(root->left,A,count);
    A[count++] = root->data;
    PopulateInOrderSet(root->right,A,count);
}
/*************************************************************
 * Que 55. Print Left view of the given binary tree.
 * 
 *        12
 *     /     \
 *   10       30
 *          /    \
 *        25      40
 * 
 * Here left view is : 12 10 25
 * 
 * Comemnt  :	Do level order traversal print the first node 
 * 		on changing level, start with root and go first
 * 		left then right.
 * 	
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
void BinarySearchTree::PrintLeftView(BinaryTreeNode* root, int level, int& max_level)
{
    if(!root) return;
    if(max_level < level)
    {
       printf("%d ",root->data);
       max_level = level;
    }
    
    PrintLeftView(root->left,level+1,max_level);
    PrintLeftView(root->right,level+1,max_level);
}
/*************************************************************
 * Que 56. Print Right view of the given binary tree.
 * 
 *        12
 *     /     \
 *   10       30
 *          /    \
 *        25      40
 * 
 * Here left view is : 12 30 40
 * 
 * Comemnt  :	Do level order traversal print the first node 
 * 		on changing level, start with root and go first
 * 		right then left.
 * 	
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
void BinarySearchTree::PrintRightView(BinaryTreeNode* root, int level, int& max_level)
{
    if(!root) return;
    if(max_level < level)
    {
      printf("%d ",root->data);
      max_level = level;
    }
    PrintRightView(root->right,level + 1,max_level);
    PrintRightView(root->left, level + 1,max_level);
}


/**********************************************************************
 *  AVL Tree (All Operations) Adelson, Velskii and Landis Trees
 * *******************************************************************/
int AVLTree::HeightOfTree()
{
   if(!root) return -1;
   return root->height;
}
void AVLTree::InsertNode(int data)
{
   if(root == NULL)
    root = new BinaryTreeNode(data);
   else
   {
      BinaryTreeNode * tNode = root;
      while(true)
      {
	if(data < tNode->data)
	{
	  if(tNode->left == NULL)
	  {
	    tNode->left = new BinaryTreeNode(data);
	    return;
	  }
	  tNode = tNode->left;
	}
	else if(data > tNode->data)
	{
	  if(tNode->right == NULL)
	  {
	    tNode->right = new BinaryTreeNode(data);
	    return;
	  }
	  tNode = tNode->right;
	}
	else
	{
	  printf("!!! Inserting Duplicate Element\n");
	  //Node->data and node to be added data is same.
	  return;
	}
      }
   }
}
void AVLTree::LevelOrderTraversal(BinaryTreeNode* root)
{
  if(!root)
     return;
   
   BinaryTreeQueue queue;
   queue.EnQueue(root);
   queue.EnQueue(NULL);
   while(!queue.IsEmpty())
   {
      root = queue.DeQueue();
      if(root == NULL)
      {
	 printf("\n");
	 if(!queue.IsEmpty())
	   queue.EnQueue(NULL);
      }
      else
      {
	printf("( %d, %d )",root->data,root->height);
	if(root->left)  queue.EnQueue(root->left);
	if(root->right) queue.EnQueue(root->right);
      }
   }
   queue.DeleteQueue();
}
/*************************************************************
 * Que 57. Convert Binary tree in Doubly linked list.
 * 
 *        12
 *     /     \
 *   10       30
 *          /    \
 *        25      40
 * 
 * Here DLL will be : 10 12 25 30 40
 * 
 * Comemnt  :	
 * 	
 * time  Complexity  : O(N)
 * Space Complexity  : O(N)
 * 
 * ***********************************************************/
BinaryTreeNode* BinaryTree::ConvertTreeToDLLRecur(BinaryTreeNode* root)
{
    if(!root)
      return NULL;
    
    if(root->left) //Process left node
    {
       BinaryTreeNode * tNode = ConvertTreeToDLLRecur(root->left);
       //Find in order predecessor
       while(tNode->right != NULL)
	 tNode = tNode->right;
      
       //Complete DLL
       tNode->right = root;
       root->left = tNode;
    }
    
    if(root->right) //Process right node
    {
       BinaryTreeNode * rNode = ConvertTreeToDLLRecur(root->right);
       //Find inorder successor
       
       while(rNode->left != NULL)
	 rNode = rNode->left;
       
       //Complete DLL
       rNode->left = root;
       root->right = rNode;
    }
    
    return root;
}
BinaryTreeNode* BinaryTree::ConvertTreeToDLL(BinaryTreeNode* root)
{
    if(!root) return NULL;
    
    if(root)
      root = ConvertTreeToDLLRecur(root);
    
    //Return Left most element
    while(root->left != NULL)
      root = root->left;
    
    return root;
}
void BinaryTree::PrintDLL(BinaryTreeNode* root)
{
    if(!root)
      return;
    while(root != NULL)
    {
      printf("%d ",root->data);
      root = root->right;
    }
    printf("\n");
}

























