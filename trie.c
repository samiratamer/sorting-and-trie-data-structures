#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ALPHABET_SIZE 26
// Trie node structure
struct TrieNode {
struct TrieNode* children[ALPHABET_SIZE];
bool isEndOfWord;
};
// Function to create a new Trie node
struct TrieNode* getNode(void) {
struct TrieNode* pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
pNode->isEndOfWord = false;
for (int i = 0; i < ALPHABET_SIZE; i++) {
pNode->children[i] = NULL;
}
return pNode;
}
// Function to insert a word into the Trie
void insert(struct TrieNode* root, const char* word) {
struct TrieNode* pCrawl = root;
for (int i = 0; word[i] != '\0'; i++) {
int index = word[i] - 'a';
if (!pCrawl->children[index]) {
pCrawl->children[index] = getNode();
}
pCrawl = pCrawl->children[index];
}
pCrawl->isEndOfWord = true;
}
// Function to search a word in the Trie
bool search(struct TrieNode* root, const char* word) {
struct TrieNode* pCrawl = root;
for (int i = 0; word[i] != '\0'; i++) {
int index = word[i] - 'a';
if (!pCrawl->children[index]) {
return false;
}
pCrawl = pCrawl->children[index];
}
return (pCrawl != NULL && pCrawl->isEndOfWord);
}
// Main function to test the Trie implementation
int main() {
// Array of words to be inserted
char* words[] = {"hello", "world", "trie", "algorithm"};
int n = sizeof(words) / sizeof(words[0]);
struct TrieNode* root = getNode();
// Insert words into the Trie
for (int i = 0; i < n; i++) {
insert(root, words[i]);
}
// Search for words in the Trie and print the result
char* queries[] = {"hello", "world", "trie", "data", "algo", "algorithm"};
int q = sizeof(queries) / sizeof(queries[0]);
for (int i = 0; i < q; i++) {
printf("Search for \"%s\": %s\n", queries[i], search(root, queries[i]) ?
"Found" : "Not Found");
}
return 0;
}
// This program demonstrates the implementation of a fundamental Trie data
structure, a specialized search tree designed for efficient storage and retrieval
of strings. The core component, TrieNode, defines each node within the Trie,
featuring an array of pointers for each alphabet letter and a boolean marker to
signify the end of a word. The software includes functionality for creating new
Trie nodes, inserting words into the Trie, and searching for specific words. In the
main routine, it populates the Trie with an array of words and performs searches
based on a series of queries. The results are then printed to show whether each
queried word exists in the Trie.
