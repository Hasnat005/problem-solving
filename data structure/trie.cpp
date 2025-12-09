#include <bits/stdc++.h>
using namespace std;


/* =================================================================
  POINTER CHEAT SHEET
 =================================================================
 1. & (Ampersand) -> "Address Of"
    Usage: &x
    Meaning: "Tell me WHERE x lives in memory." 
 
 2. * (Asterisk) -> Has TWO meanings:
 
    A) When Declaring: "I am a Pointer"
       Usage: int *p;
       Meaning: "p is a special variable that holds an address."
 
    B) When Using: "Go to Address" (Dereference)
       Usage: *p
       Meaning: "Teleport to the address inside p and give me the value."
 =================================================================
*/

// ---------------------------------------------------------
// int x = 10;
// int *p = &x;   // Declare p, store address of x in it.
// int y = *p;    // Go to address in p, get value (10).
// ---------------------------------------------------------
/*
int *a; means "a is a variable that stores the memory address of an integer."
In C++, the & symbol is called the Address-of Operator.
When you write &x, it translates to: "Give me the memory address where the variable x is located."
*/

/* =================================================================
   KEYWORD: new
   =================================================================
   Usage: Type *ptr = new Type();
   
   WHAT IT DOES:
   1. ALLOCATE: Reserves space in the HEAP memory.
   2. CONSTRUCT: Runs the constructor to clean/setup the object.
   3. RETURN: Returns the memory address to your pointer.

   CRITICAL:
   Objects created with 'new' are PERMANENT. They do not vanish 
   when the function ends. You must eventually use 'delete ptr' 
   to free the memory, otherwise you get a "Memory Leak".
   ================================================================= */

/* =================================================================
   EXPLANATION: root = new Node();
   =================================================================
   1. "new Node()" does THREE things:
      a) Allocates memory: Finds space in the HEAP (permanent storage) 
         for a Node.
      b) Runs Constructor: Triggers Node() to set flag=false and 
         links=nullptr.
      c) Returns Address: Gives back the memory location (e.g., 0x900).

   2. "root =" does ONE thing:
      a) Stores that address into the pointer variable 'root'.
   
   WHY USE 'new'? 
   Variables created with 'new' stay in memory forever until you 
   delete them. If we didn't use 'new', the Node would disappear 
   when the function ends.
   ================================================================= */
// root = new Node();


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