#ifndef _H_TREES_
#define _H_TREES_

#define NL printf("\n")

/* Utility function */
int Max(int a,int b);

class BinaryTreeNode
{
public :
    int data;
    int height;
    BinaryTreeNode * right,*left;
    BinaryTreeNode(int _data):data(_data),right(NULL),left(NULL),height(0){}
   ~BinaryTreeNode(){}
};

class BinaryTree{
   
protected:

  BinaryTreeNode * root;

public :
  
    BinaryTree():root(NULL){}
    virtual ~BinaryTree(){}
    void InsertNode(int data);
    BinaryTreeNode * GetRoot(){return root;}
    void SetRoot(BinaryTreeNode * _root) {root = _root; }

    //Que 2. InOrder Traversal (Recursion)
    void InOrderTraversal(BinaryTreeNode * root);
    //Que 3. InOrder Traversal without Recursion
    void InOrderTraversalWORecursion(BinaryTreeNode * root);
    //Que 4. PreOrder Traversal (Recursion)
    void PreOrderTraversal(BinaryTreeNode * root);
    //Que 5. PreOrder Traversal without Recursion
    void PreOrderTraversalWORecursion(BinaryTreeNode *root);
    //Que 6. PostOrder Traversal with recursion
    void PostOrderTraversal(BinaryTreeNode * root);
    //Que 7. PostOrder Traversal without recursion
    void PostOrderTraversalWORecursion(BinaryTreeNode * root);
    //Que 8. Level Order Traversal
    void LevelOrderTraversal(BinaryTreeNode * root);
    //Que 9. Find Maximum element in binary tree
    int  FindMax(BinaryTreeNode * root);
    //Que 10. Find Maximum element in binary tree without recursion
    int FindMaxWORecursion(BinaryTreeNode * root);
    //Que 11. Find element in given binary tree with recursion
    bool FindElement(BinaryTreeNode *root,int data);
    //Que 12. Find element in given binary tree without recursion
    bool FindElementWORecursion(BinaryTreeNode * root,int data);
    //Que 13. Find the size of binary tree
    int  FindSize(BinaryTreeNode * root);
    //Que 14. Find the size of binary tree without recursion
    int  FindSizeWORecursion(BinaryTreeNode * root);
    //Que 15. Print the level order data in reverse order
    void LevelOrderTraversalReverse(BinaryTreeNode *root);
    //Que 16. Give algorithm to delete the tree
    void DeleteTree(BinaryTreeNode * root);
    //Que 17. Find the height of binary tree
    int  FindHeight(BinaryTreeNode * root);
    //Que 18. Find the height of binary tree without recursion
    int FindHeightWORecursion(BinaryTreeNode * root);
    //Que 19. Find the deepest node of the binary tree
    BinaryTreeNode * FindDeepestNode(BinaryTreeNode * root);
    //Que 20. Delete a node from binary tree
    void DeleteNode(BinaryTreeNode * root,int data);
    BinaryTreeNode * FindNode(BinaryTreeNode * root,int data);
    void DeleteGivenNode(BinaryTreeNode * dNode,BinaryTreeNode * root);
    //Que 21. Find an algorithm to count number of leaves in the binary tree without recursion
    int FindLeaves(BinaryTreeNode * root);
    //Que 22. Find the number of full nodes (Full Nodes : have both children)
    int FindFullNodes(BinaryTreeNode * root);
    //Que 23. Find the number of half nodes (Half Nodes : have only one child)
    int FindHalfNodes(BinaryTreeNode * root);
    //Que 24. Check if two given binary trees are identical
    static bool CompairTwoBinaryTrees(BinaryTreeNode * root1,BinaryTreeNode * root2);
    //Que 25. Find length of diameter of a given binary tree                          (**********************************)
    int DiameterOfTree(BinaryTreeNode * root);
    int HeightOfTree(BinaryTreeNode * root);
    //Que 26. Find the level number in binary tree which has maximum sum
    int FindMaxSumLevel(BinaryTreeNode * root);
    //Que 27. Give an algorithm to print all the possible path from root to leaves    (*********************************)
    void PrintAllPathsToLeaves(BinaryTreeNode * root,int path[],int pathLen);
    void PrintPath(int path[],int pathLen);
    //Que 28. Give an algorithm for checking the existence of path with given sum. That means, given a sum check whether there
    //exists a path from root to any of the nodes.
    bool PrintAllPathsWithSum(BinaryTreeNode * root,int path[],int pathLen,int sum);
    //Que 29. Find sum of all elements of binary tree.
    int  FindSumOfAllElement(BinaryTreeNode * root);
    //Que 30. Find LCA (Least common ancestor) of two given nodes of given tree
    int  FindLCA(BinaryTreeNode * root,int a,int b);
    bool CheckNode(BinaryTreeNode * root,int a);
    //Que 31. Construct Binary tree from inorder and preorder traversal
    static BinaryTreeNode * ConstructBinaryTreeFromInOrderANDPreOrder(int inOrder[],int preOrder[],int inStr,int endStr,bool _reset = false);
    static int SearchIndex(int inOrder[],int inStr,int endStr,int data);
    //Que 32. Construct Binary tree from inorder and postorder traversal 
    //(***********NOT WORKING **********************)
    static BinaryTreeNode * ConstructBinaryTreeFromInOrderANDPostOrder(int inOrder[],int postOrder[],int inStr,int endStr,bool _reset = false);
    //Que 33. Find all the ancestor of a given node
    void PrintAllAncestor(BinaryTreeNode * root,int path[],int pathLen,int data);
    //Que 34. Print nodes in zigzag order
    void LevelOrderTraversalZigZag(BinaryTreeNode * root);
    //Que 35. Given a tree with a special property where leaes are represented with '0' and internal nodes are represented as '2' 
    //Also assume each node can have one or two children. Given preorder traversal of this tree. Construct the binary tree.
    static BinaryTreeNode * ConstructBinaryTreeFromPreOrder(int preOrder[],int sIndex, int eIndex,bool _reset = false);
    //Que 36. Check if two given tree are isomorphic to each other or not
    static bool CheckIsomorphicTrees(BinaryTreeNode * root1,BinaryTreeNode * root2);
    //Que 37. Given two trees are said to be quasi-isomorphic if root1 can be transformed into root2 by swapping left and right
    //children of some of the nodes of root1. The data in the nodes are not important in checking for quasi-isomorphic.
    static bool CheckQuasiIsomorphicTrees(BinaryTreeNode * root1,BinaryTreeNode * root2);
    //Que 38. Find InOrder successor of the given node in binary tree.
    BinaryTreeNode * FindInOrderSuccessor(BinaryTreeNode * root,int key);
    //Que 39. Find PreOrder successor of the given node in binary tree
    BinaryTreeNode * FindPreOrderSuccessor(BinaryTreeNode * root,int key);
    //Que 40. Find PostOrder successor of the given node in binary tree
    BinaryTreeNode * FindPostOrderSuccessor(BinaryTreeNode * root,int key);
    
    //Que 57. Convery Binary tree to Doubly linked list.
    BinaryTreeNode * ConvertTreeToDLL(BinaryTreeNode * root);
    BinaryTreeNode * ConvertTreeToDLLRecur(BinaryTreeNode * root);
    void PrintDLL(BinaryTreeNode * root);
        
};

class BinarySearchTree : public BinaryTree{
  
public :
  BinarySearchTree():BinaryTree(){}
  virtual ~BinarySearchTree(){}
  
  void InsertNode(int data);
  //Que 41. Search a given element in given binary search tree
  bool SearchElement(BinaryTreeNode * root,int data);
  //Que 42. Search minimum element in given bst.
  int SearchMin(BinaryTreeNode * root);
  //Que 43. Search maximum element in given BST.
  int SearchMax(BinaryTreeNode * root);
  //Que 44. Delete A given node
  BinaryTreeNode * DeleteNode(BinaryTreeNode * root,int data);
  BinaryTreeNode * SearchMaxNode(BinaryTreeNode * root);
  //Que 45. Find Lowest common ancestor for binary tree
  int FindLCA(BinaryTreeNode * root, int a,int b);
  //Que 46. Check if given binary tree is BST or Not
  static bool IsBST(BinaryTreeNode * root);
  //Que 47. Check if given binary tree is BST or Not (More correct algo)
  bool IsBST(BinaryTreeNode * root,bool _reset);
  //Que 48. Create a BST from an integer sorted array
  static BinaryTreeNode * CreateBSTFromSortedArray(int A[],int left,int right);
  //Que 49. Find the kth smallest number in given binary search tree.
  int SearchKthMin(BinaryTreeNode * root,int k, int &count);
  //Que 50. Floor in BST
  int Floor(BinaryTreeNode * root,int key,int pValue);
  //Que 51. Ceiling in BST
  int Ceiling(BinaryTreeNode * root,int key,int pValue);
  //Que 52. Print all nodes value in given range K1 and K2
  void PrintInRange(BinaryTreeNode * root,int K1,int K2);
  //Que 53. Solving Que 52. Using Queue
  void PrintInRangeQueue(BinaryTreeNode * root,int K1,int K2);
  //Que 54. Compair Two Binary search tree for its elements
  static bool CompairBinaryTrees(BinarySearchTree &tree1, BinarySearchTree & tree2);
  void PopulateInOrderSet(BinaryTreeNode * root,int A[],int &count);
  //Que 55. Print Left View of the binary search Tree
  void PrintLeftView(BinaryTreeNode * root,int level,int &max_level);
  //Que 56. Print Right View of the binary search Tree
  void PrintRightView(BinaryTreeNode * root,int level,int &max_level);
};

class AVLTree : public BinarySearchTree 
{
  public :
    AVLTree(){};
    virtual ~AVLTree(){};
    
    void InsertNode(int data);
    int HeightOfTree();
    void LevelOrderTraversal(BinaryTreeNode * root);
    
};

class BinaryTreeQueue{
  
  class BinaryTreeQueueNode
  {
    public:
      BinaryTreeNode * data;
      BinaryTreeQueueNode * next;
      
      BinaryTreeQueueNode(BinaryTreeNode * _data){ 
	data = _data;
	next = NULL; 
      }
  };
private :
  BinaryTreeQueueNode * front;
  BinaryTreeQueueNode * rear;
public :
  BinaryTreeQueue():front(NULL),rear(NULL){}
 ~BinaryTreeQueue(){}
  bool IsEmpty();
  void EnQueue(BinaryTreeNode * _data);
  BinaryTreeNode * DeQueue();
  void DeleteQueue();
};

class BinaryTreeStack{
  
  class BinaryTreeStackNode{
  public : 
    BinaryTreeNode * data;
    BinaryTreeStackNode * next;
    BinaryTreeStackNode(BinaryTreeNode * _data){data = _data;next = NULL;}
   ~BinaryTreeStackNode(){}
  };
  
private :
  BinaryTreeStackNode * top;
public :
  BinaryTreeStack():top(NULL){}
 ~BinaryTreeStack(){}
  
  void Push(BinaryTreeNode * _data);
  BinaryTreeNode * Pop();
  bool IsEmpty(){return top == NULL;}
  BinaryTreeNode * Top() { return top ? top->data : NULL; }
  void DeleteStack();
  
};

#endif