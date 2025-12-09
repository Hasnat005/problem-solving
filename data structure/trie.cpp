#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node *links[26] = {NULL};
    bool flag = false;

    void put(Node *node, char ch) {
        links[ch - 'a'] = node;
    }
    bool is_contains_key(char ch) {
        return links[ch - 'a'] != NULL;
    }
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    void put_end() {
        flag = true;
    }
    bool is_end_here() {
        return flag;
    }
};

class Trie{
    public:

    Node *root;

    Trie(){
        root = new Node();
    }
    void insert(string word) {
           Node *node = root;
           for(int i = 0; i < word.size(); i++) {
                if(node->is_contains_key(word[i]) == false) {
                    node->put(new Node(), word[i]);
                }
                node = node -> get(word[i]);
           }
           node->put_end();
    }

    bool search(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->is_contains_key(word[i]) == false) {
                return false;
            } 
            node = node -> get(word[i]);
        }
        return node->is_end_here();

    }

    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(node->is_contains_key(prefix[i]) == false) {
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;   // returns true
    cout << obj->search("app") << endl;     // returns false
    cout << obj->startsWith("app") << endl; // returns true
    obj->insert("app");
    cout << obj->search("app") << endl;     // returns true
    return 0;
}