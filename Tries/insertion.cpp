#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 25; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            root -> isTerminal = true;
            return;
        }

        // Assumption = word will be in caps
        int index = word[0] - 'A';
        TrieNode* child;
        // Present
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }   
};

int main()
{
    Trie *t = new Trie();

    t -> insertWord("abcd");

    return 0;
}