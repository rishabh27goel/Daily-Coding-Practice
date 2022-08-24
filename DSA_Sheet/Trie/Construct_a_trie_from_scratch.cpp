#include <iostream>
#include <vector>
using namespace std;

class TrieNode {

    public:
        char data;
        TrieNode* child[26];
        bool isTerminal;

    TrieNode(char data){

        this->data = data;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }

        this->isTerminal = false;
    }
};  

class Trie {

    public:
        TrieNode* root;

    Trie(){

        // Initialize the root node
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* node, string &word, int index){

        // Base Case
        if(index == word.size()){

            // Terminal Marking
            node->isTerminal = true;

            return;
        }

        // Get the character 
        char data = word[index];
        TrieNode* nextNode;

        // Check if char is present [If not add it]
        if(node->child[data-'a'] == NULL){

            // Create new node
            nextNode = new TrieNode(data);

            // Create link with parent
            node->child[data-'a'] = nextNode;
        }
        // Get the existing node
        else{

            nextNode = node->child[data-'a'];
        }

        insertUtil(nextNode, word, index + 1);
    }

    void insert(string word){

        insertUtil(root, word, 0);
    }

    bool searchWordUtil(TrieNode* node, string &word, int index){

        // Base Case [If word is completely traversed]
        if(index == word.size()){

            // If the node is terminal 
            if(node->isTerminal == true){

                return true;
            }

            return false;
        }

        // Get the character 
        char data = word[index];

        // If the character does not exits
        if(node->child[data-'a'] == NULL)  return false;
        

        return searchWordUtil(node->child[data-'a'], word, index + 1);
    }

    void searchWord(string word){

        if(searchWordUtil(root, word, 0)){

            cout << "Word Found !!" << endl;
        } 
        else{

            cout << "Not Found !!" << endl;
        }
    }

    void deleteWordUtil(TrieNode* node, string &word, int index){

        // Base Case [If word is completely traversed]
        if(index == word.size()){

            // Remove the terminal from this node to delete the word from trie
            if(node->isTerminal == true){

                node->isTerminal = false;
            }

            return;
        }

        // Get the character 
        char data = word[index];

        // If the character does not exits
        if(node->child[data-'a'] != NULL){

            deleteWordUtil(node->child[data-'a'], word, index + 1);
        }
    }

    void deleteWord(string word){

        deleteWordUtil(root, word, 0);
    }
};

int main()
{
    // Create Trie
    Trie t;

    // Add Words
    t.insert("cat");
    t.insert("dog");
    
    t.insert("door");
    t.insert("apple");
    

    // Searching Words
    // t.searchWord("cut");
    // t.searchWord("cat");

    // t.searchWord("dogg");
    // t.searchWord("dog");

    // t.searchWord("app");
    // t.searchWord("appl");
    // t.searchWord("do");

    // Delete Word
    t.searchWord("cat");
    
    t.deleteWord("cat");
    t.searchWord("cat");
 
    t.insert("cat");
    t.searchWord("cat");

    return 0;
}