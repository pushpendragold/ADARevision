#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cmath>
#include <set>
#include <malloc.h>

#include "15StringAlgo.h"

using namespace std;

// KPM algorithm
void computeLPSArray(std::string pat,std::vector<int> &lps)
{
	int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while(i < pat.length())
    {
       if( pat.at(i) == pat.at(len) )
       {
		   len++;
		   lps[i] = len;
		   i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len - 1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
void KMPSearch(std::string &pat, std::string &txt)
{
    int M = pat.length();
    int N = txt.length();
 
    // create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps;
	int j  = 0;  // index for pat[]

	lps.resize(M);
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, lps);
 
    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
	lps.clear();
}

/**********************************************
// Tries 
**********************************************/
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


// Returns new trie node (initialized to NULLs)
trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;
	pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
 
    if( pNode )
    {
        int i;
		pNode->value = 0;
		for(i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
    }
    return pNode;
}
 
// Initializes trie (root is dummy node)
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->value = pTrie->count;
}
 
// Returns non zero, if key presents in trie
int search(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if( !pCrawl->children[index] )
            return 0;
        pCrawl = pCrawl->children[index];
    }
 
    return (0 != pCrawl && pCrawl->value);
}
 
/**********************************************************
// Ternary Search Tree
**********************************************************/
 // A utility function to create a new ternary search tree node
struct Node* newNode(char data)
{
    struct Node* temp = (struct Node*) malloc(sizeof( struct Node ));
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}
// Function to insert a new word in a Ternary Search Tree
void insert(struct Node** root, char *word)
{
    // Base Case: Tree is empty
    if (!(*root))
        *root = newNode(*word);
 
    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if ((*word) < (*root)->data)
        insert(&( (*root)->left ), word);
 
    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data)
        insert(&( (*root)->right ), word);
 
    // If current character of word is same as root's character,
    else
    {
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);
 
        // the last character of the word
        else
            (*root)->isEndOfString = 1;
    }
}
// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node* root, char* buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);
 
        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }
 
        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1);
 
        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}
// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}
 
// Function to search a given word in TST
int searchTST(struct Node *root, char *word)
{
    if (!root)
        return 0;
 
    if (*word < (root)->data)
        return searchTST(root->left, word);
 
    else if (*word > (root)->data)
        return searchTST(root->right, word);
 
    else
    {
        if (*(word+1) == '\0')
		{
            return root->isEndOfString;
		}
 
        return searchTST(root->eq, word+1);
    }
}
/*****************************************************************
// Que 1. Find patterns in a given string pattern has wild card 
*****************************************************************/
bool FindPatternWithWildCard(char * pattern, char * text)
{
	if( *pattern == '\0' ) return true;
	if( *text == '\0' ) return *pattern == '\0';

	if(*pattern == '?' ) return FindPatternWithWildCard(pattern+1,text+1 );
	if(*pattern == '*' ) return FindPatternWithWildCard(pattern,text+1 ) || FindPatternWithWildCard(pattern+1,text );

	if( *text == *pattern ) return FindPatternWithWildCard(pattern+1,text+1);

	return false;
}
/*****************************************************************
// Que 2. Perumtation for given string of length n
*****************************************************************/
void Perm(char A[],int n,int i)
{
	if( i >= n ) 
	{
		printf("%s\n",A);
		return;
	}
	else
	{
		for(int j = i; j < n; j++) 
		{
			Sw(A[i],A[j]);
			Perm(A,n,i+1);
			Sw(A[i],A[j]);
		}
	}
}
void Sw(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}
