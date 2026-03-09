#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    Node *get(char ch) { return links[ch - 'a']; }

    void put(char ch, Node *node) { links[ch - 'a'] = node; }

    bool isEnd() { return flag; }

    void setEnd() { flag = true; }
};

class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }

    void insert(string word)
    {
        Node *node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->get(ch);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }

        return true;
    }
};

class Solution
{
public:
    string longestValidWord(vector<string> &words)
    {
        Trie trie;

        // Step 1: Insert all words into the Trie
        for (auto &word : words)
            trie.insert(word);

        string ans = ""; 

        // Step 2: Check each word for validity
        for (auto &word : words)
        {
            Node *node = trie.root; 
            bool valid = true;      // Assume the word is valid initially

            // Step 2a: Traverse the word character by character
            for (char ch : word)
            {
                node = node->get(ch); // Move to the next node in Trie

                // Step 2b: If any prefix of this word is not a complete word, mark invalid
                if (!node->isEnd())
                {
                    valid = false;
                    break;
                }
            }

            // Step 3: Update answer only if the word is valid
            if (valid)
            {
                // Choose the word with longest length
                // If tie in length, choose lexicographically smaller
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans))
                    ans = word;
            }
        }

        return ans;
    }
};
