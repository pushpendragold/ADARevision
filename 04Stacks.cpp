#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#include "04Stacks.h"

/* DEBUG PRINTS */
int ShowPop = 0;

LinkedListStack::LL::LL(int data)
{
  this->data = data;
  this->next = NULL;
}
LinkedListStack::LL::~LL()
{

}
bool LinkedListStack::IsEmpty()
{
  return top == NULL;
}
LinkedListStack::LinkedListStack()
{
  top = NULL;
  count = 0;
}
LinkedListStack::~LinkedListStack()
{
}
void LinkedListStack::Push(int data)
{
  if(IsEmpty())
  {
    top = new LL(data);
  }
  else
  {
    LL * temp = new LL(data);
    temp->next = top;
    top = temp;
  }
  count++;
}
void LinkedListStack::PrintStack()
{
   LL *tNode = top;
   while(tNode != NULL)
   {
      printf("%d ",tNode->data);
      tNode = tNode->next;
   }
   printf("\n");
}
int LinkedListStack::Pop()
{
  if(count == 0)
  {
    printf("Stack already empty.\n");
    return -1;
  }
  count--;
  LL * tmp = top->next;
  int data = top->data;
  delete top;
  top = tmp;
  if(ShowPop)
  printf("Pop : %d %c\n",data,data);
  return data;
}
int LinkedListStack::Top()
{
  if(IsEmpty())
  return -1;
  return top->data;
}
/*******************************************************
 * Que 1. Discuss how stacks can be used for balancing 
 *        of symbols
 * 
 * Parameters : Expression (char array)
 * 		size of array
 * returns    : bool (true/false)
 *******************************************************/
bool IsExpressionBalanced(char A[], int size)
{
   LinkedListStack stack;
   printf("Expression : %s\n",A);
   int i;
   char a,temp;
   for(i=0;i<size;i++)
   {
      a = A[i];
      switch(a)
      {
	case '(': case '{': case '[':
	  stack.Push(a);
	  break;
	
	case ')': case '}' : case ']':
	  temp = stack.Pop();
	  if(temp == -1)
	    return false;
	  else
	  {
	    if((temp == '(' && a != ')') || 
	       (temp == '{' && a != '}') ||
	       (temp == '[' && a != ']') 
	    )
	      return false;
	  }
	  break;
      }
   }
   if(stack.Pop() != -1)
      return false;
   else
      return true;
} /* END QUE 1 */

/*******************************************************
 * Que 2. Infix to Postfix conversion.
 * 
 * Parameters : Expression
 * Retuns     : None
 * 
 * Time Complexity : O(N)
 *******************************************************/
char * InfixToPostFix(char A[])
{
  LinkedListStack stack;
  char * output = new char[1024];
  int iOutput = 0;
  int tokenType = EMPTY;
  int i=0,num;
  char token;
  char topStack = '\0';
  
  while((tokenType = ReadToken(A,i,token,num)) != EMPTY)
  {
      if(tokenType == OPERAND) //Numbers
      {
		  //Add simply in output string
		  output[iOutput++] = token; //num - '0';
      }
      else if(tokenType == OPERATOR) //Mathematical operator
      {
		  if(!stack.IsEmpty()) topStack = stack.Top();
				else topStack = '\0';
	
				if(topStack == '\0' || topStack == '(' || 
				   topStack == '{' || topStack == '[')
				{
					stack.Push(token);
				}
				else
				{
					if(CompairPrecedence(topStack,token))
						stack.Push(token);
					else
					{
						while( topStack != -1   && !CompairPrecedence(topStack,token) && 
							   topStack != '\0' && 
							   topStack != '('  && 
							   topStack != '{'  && 
							   topStack != '[')
						{
							output[iOutput++] = stack.Pop();
							topStack = stack.Top();
						}
						stack.Push(token);
					}
				}
		}
		else if(tokenType == RIGHTP)   //Right parenthesis
		{
			char top = stack.Top();
			while(top != '(' ) //&& topStack != '{'  && topStack != '[')
			{
				output[iOutput++] = stack.Pop();
				top = stack.Top();
			}
			stack.Pop();
		}
		else if(tokenType == LEFTP)    //Left parenthesis
		{
			stack.Push(token);
		}
  }
  while(!stack.IsEmpty())
    output[iOutput++] = stack.Pop();
  output[iOutput] = '\0';
  return output;
}
int ReadToken(char A[], int& i, char &token,int &num)
{
   int tokenType = EMPTY;
   if( (A[i] >= '0' && A[i] <= '9') || (A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= 'a' && A[i] <= 'z'))
   {
     tokenType = OPERAND;
     token = A[i++];
   }
   else if(A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
   {
     //Operator
      token = A[i++];
      tokenType = OPERATOR;
   }
   else if(A[i] == '(' || A[i] == '[' || A[i] == '{')
   {
      token = A[i++];
      tokenType = LEFTP;
   }
   else if(A[i] == ')' || A[i] == ']' || A[i] == '}')
   {
      token = A[i++];
      tokenType = RIGHTP;
   }
   return tokenType;
}
/**********************************************************
 * PRECEDENCE TABLE :
 * ------------------
 * 3.  ~ ! 
 * 2.  * / %
 * 1.  + -
 * 
 * CompairPrecedence
 * Comment   : if operators are equal return false.
 * 
 * Parameters: operator top element of stack and current
 *             operator
 * Return    : true if current operator has more priority
 *             false if current operator has less priority
 *********************************************************/
bool CompairPrecedence(char top, char A)
{
   int iTop = -1,iA = -1;
   //stack top operator
   switch(top)
   {
     case '~' : case '!': 
       iTop = 3; 
       break;
     
     case '*' : case '/': case '%': 
       iTop = 2;
       break;
       
     case '+': case '-':
       iTop = 1;
       break;
   }
   //Current operator
   switch(A)
   {
     case '~' : case '!': 
       iA = 3; 
       break;
     
     case '*' : case '/': case '%': 
       iA = 2;
       break;
       
     case '+': case '-':
       iA = 1;
       break;
   }
   assert(iTop != -1 && iA  != -1);
   return iTop < iA ? true : false;
}
/* END QUE 2 */
/*************************************************************
 * Que 3. Post fix expression evaluation
 * 
 * Comment    : 1) prepare stack for holding operands only.
 *              2) Push when numbers are read.
 *              3) Pop two numbers when ever operand is encountered.
 * 
 * Parameters : expression array
 * Returns    : int (eval result)
 *************************************************************/
int  PostFixEval(char A[])
{
   LinkedListStack stack;
   int tokenType = EMPTY,num,i=0;;
   char token;

   while((tokenType = ReadToken(A,i,token,num)) != EMPTY)
   {
      if(tokenType == OPERAND) //Numbers
      {
		  stack.Push(token - '0');
      }
      else if(tokenType == OPERATOR) //Mathematical operator
      {
		  int A = stack.Pop();
		  int B = stack.Pop();
		  stack.Push(Operate(A,B,token));
      }
      else 
      {
		  //Should not reach here
		  assert(1 == 0);
      }
  }
  if(stack.IsEmpty())
    return -1;
  return stack.Pop();   
}
/*********************************
 * Utility function for eval
 ********************************/
int  Operate(int A,int B,char op)
{
   switch(op)
   {
     case '*' : return A*B;
     case '-' : return B-A;
     case '+' : return A+B;
     case '/' : return B/A;
   }
   assert(1 == 0);
   return -1;
}
/* END Que. 3 */
/*************************************************************
 * Que 4. Infix expression evaluation
 * 
 * Comment    : 1) Convert Infix to postfix expression
 *              2) Eval using postfix evaluation and return 
 * 		   result
  * 
 * Parameters : expression array
 * Returns    : int (eval result)
 *************************************************************/
int  InfixEval(char A[])
{
  //Convert expression to postfix then eval,
  return PostFixEval(InfixToPostFix(A));
}
/*************************************************************
* Que 5. Use stack to find minimum element for all stack 
* elements
* 
* Comment    : Creating min stack to get current index minimum
* 	       Element for all elements.
* 
*    1. Improved space complexity by pushing in stack
*       Only if there is more less value available &
*       and popped only when the current stack top value
*	is equal to array value.
* 
* Parameters : integer array
* Retuns     : None
**************************************************************/
void  GetMinimum(int A[],int size)
{
   if(size == 0) return;
   LinkedListStack stack;
   stack.Push(A[0]);
   for(int i=1; i<size; i++)
   {
      if(stack.Top() > A[i])
	stack.Push(A[i]);
       //else
       //stack.Push(stack.Top());
   }
   for(int i=size - 1;i>=0;i--)
      printf("%d ",A[i]);
   printf("\n");
   
   int c = stack.GetSize();
   for(int i=0;i<c;i++)
      printf("%d ",stack.Pop());
   printf("\n");
}
/* END OF QUE 5 */
/*************************************************************
 * Que 6. Reverse stack element using recursion. without using
 * 	  Another stack.
 * 
 * Comment    : 
 * 
 * Parameters : Stack
 * Returns    : None
 *************************************************************/
void ReveseStack(LinkedListStack &stack)
{
    if(stack.IsEmpty())
      return;
  int data = stack.Pop();
  ReveseStack(stack);
  AddElementAtBottom(stack,data);
}
void AddElementAtBottom(LinkedListStack &stack, int data)
{
   if(stack.IsEmpty())
   {
      stack.Push(data);
      return;
   }
   int temp = stack.Pop();
   AddElementAtBottom(stack,data);
   stack.Push(temp);
}
/* END OF QUE 6 */
/***************************************************************
 * Que 7. Given an array A, the apan S[i] of A[i] is the 
 *        maximum number of consecutive elements A[j]
 *        elements A[j] and such that A[j] <= A[i]
 * 
 * Commenst   :
 * 
 * Parameters : integer arrays.
 * Retuns     : longest spans
 * 
 **************************************************************/
int *FindingSpans(int A[],int size)
{
   LinkedListStack stack;
   int p;
   int * s = new int[size];
   
   for(int i=0;i<size;i++)
   {
      while(!stack.IsEmpty())
      {
	if(A[i] > A[stack.Top()])
	  stack.Pop();
	else
	  break;
      }
   
      if(stack.IsEmpty())
	p = -1;
      else
	p = stack.Top();
      
      s[i] = i-p;
      stack.Push(i);
   }
   return s;
}
/* END OF QUE 7 */
/***************************************************************
 * Que 8. Find the maximum area of histogram included inside
 * 	  Given histogram.
 * 
 * Commenst   :
 * 
 * Parameters : integer arrays.
 * Retuns     : Maximum Histogram area
 * 
 **************************************************************/
int MaxRectangleArea(int A[],int n)
{
	int i,maxArea = -1, top = -1,left,currentArea;
	StackItem *s = (StackItem *) malloc (sizeof(StackItem)*n);
	for(i=0;i<=n;i++)
	{
		while(top >=0 && (i == n || s[top].data > A[i]))
		{
			if(top > 0) 
				left = s[top-1].index;
			else		
				left = -1;

			currentArea = (i-left-1)*s[top].data;
			--top;

			if(currentArea > maxArea)
				maxArea = currentArea;
		}
		if(i<=n) {
			++top;
			s[top].data = A[i];
			s[top].index = i;
		}
	}
	return maxArea;
}
