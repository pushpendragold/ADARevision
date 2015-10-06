#ifndef _H_STACK_
#define _H_STACK_

class LinkedListStack{
  
private :
  
  class LL{
  public :
      int data;
      LL * next;
      LL(int data);
     ~LL();
  };

  LL * top;
  int count;
    
public :  
  
  LinkedListStack();
 ~LinkedListStack();
  int  GetSize(){ return count; }
  bool IsEmpty();
  void Push(int data);
  int  Pop();
  int  Top();
  void PrintStack();
};

//Que 1. Discuss how stacks can be used for checking balancing of symbols.
bool IsExpressionBalanced(char A[],int size);
//Que 2. Infix to post fix conversion.
char * InfixToPostFix(char A[]);

enum Token{EMPTY,OPERAND,OPERATOR,RIGHTP,LEFTP}; //ReadToken returns type of tokens
int  ReadToken(char A[], int& i, char &token,int &num);
bool CompairPrecedence(char top, char A);

//Que 3. Post fix evaluation using stacks
int  PostFixEval(char A[]);
int  Operate(int A,int B,char op);

//Que 4. Infix evaluation using postfix evaluation technique
int  InfixEval(char A[]);

//Que 5. Use stack to find min element for all element.
void  GetMinimum(int A[],int size);

//Que 6. Reverse stack element
void ReveseStack(LinkedListStack &stack);
void AddElementAtBottom(LinkedListStack &stack,int data);

//Que 7. Finding Increasing Span
int * FindingSpans(int A[],int size);

//Que 8. Find the maximum histogram area
int MaxRectangleArea(int A[],int n);

typedef struct StackItem{
	int index;
	int data;
} StackItem ;



#endif