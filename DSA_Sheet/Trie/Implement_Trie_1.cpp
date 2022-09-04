#include <iostream>
using namespace std;

class TrieNode {

    public:
        char data;
        TrieNode* child[26];
        bool isEnd;

    TrieNode(char data){

        this->data = data;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }

        this->isEnd = false;
    }
};

class Trie {

    public:
        TrieNode* root;

    Trie(){

        root = new TrieNode('\0');
    }

    // insert() word in trie
    void insert(string word){

        TrieNode* itr = root;
        int i = 0;

        while(i < word.size()){

            char data = word[i];
            TrieNode* node;

            if(itr->child[data-'a'] == NULL){

                node = new TrieNode(data);
                itr->child[data-'a'] = node;
            }
            else{

                node = itr->child[data-'a'];
            }

            itr = node;
            i++;
        }

        itr->isEnd = true;
    }

    // search() for word in trie
    bool search(string word){

        TrieNode* itr = root;
        int i = 0;

        while(i < word.size()){

            char data = word[i];
    
            if(itr->child[data-'a'] == NULL){

                cout << "Not Exits !!" << endl;
                return false;
            }
            else{

                itr = itr->child[data-'a'];
            }

            i++;
        }

        if(itr->isEnd)
            cout << "Exits !!" << endl;
        else
            cout << "Not Exits !!" << endl;
        
        return itr->isEnd;
    }

    // Any word startswith() in trie
    bool startsWith(string prefix){

        TrieNode* itr = root;
        int i = 0;

        while(i < prefix.size()){

            char data = prefix[i];

            if(itr->child[data-'a'] == NULL){

                cout << "Not Exits !!" << endl;
                return false;
            }
            else{

                itr = itr->child[data-'a'];
            }

            i++;
        }

        cout << "Exits !!" << endl;
        
        return true;
    }
};

int main()
{
    Trie t;

    // Insert Words
    t.insert("Climbing");
    t.insert("Running");
    t.insert("Walking");

    // Search Words
    t.search("Walking");
    t.search("Climb");
    t.search("Climbing");

    // Search Words
    t.startsWith("Walk");
    t.startsWith("Clmb");
    t.startsWith("Runnn");
    
    t.startsWith("Clim");
    t.startsWith("Run");

    cout << endl;
    return 0;
}