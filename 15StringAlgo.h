#ifndef _H_STRING_ALGO
#define _H_STRING_ALGO

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

#define ALPHABET_SIZE (26)
#define MAX 50

// KPM algorithm
void computeLPSArray(std::string pat,std::vector<int> &lps);
void KMPSearch(std::string &pat, std::string &txt);

// Trie

// trie node
typedef struct trie_node_t
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
} trie_node_t ;
 
// trie ADT
typedef struct trie_t
{
    trie_node_t *root;
    int count;
}trie_t;

trie_node_t *getNode(void);
void initialize(trie_t *pTrie);
void insert(trie_t *pTrie, char key[]);
int  search(trie_t *pTrie, char key[]);


// Ternary Search Tree

// A node of ternary search tree
struct Node
{
    char data;
 
    // True if this character is last character of one of the words
    unsigned isEndOfString: 1;
 
    struct Node *left, *eq, *right;
};
struct Node* newNode(char data);
void insert(struct Node** root, char *word);
void traverseTST(struct Node* root);
void traverseTSTUtil(struct Node* root, char* buffer, int depth);
int searchTST(struct Node *root, char *word);

// Que 1. Find patterns in a given string pattern has wild card 
bool FindPatternWithWildCard(char * pattern, char * text);
// Que 2. Permutation of given string
void Perm(char A[],int n,int i);
void Sw(char &a, char &b);

#endif
