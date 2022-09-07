#include <iostream>
using namespace std;

class TrieNode {

    public:
        char data;
        TrieNode* child[26];
        int endCount;
        int startCount;

    TrieNode(char data){

        this->data = data;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }

        this->startCount = 0;
        this->endCount = 0;
    }
};

class Trie {

    public:
        TrieNode* root;

    Trie(){

        root = new TrieNode('\0');
    }

    // insert() in trie
    void insert(string word){

        TrieNode* itr = root;
        int i = 0;

        while(i < word.size()){

            char data = word[i];
            TrieNode* newNode;
            
            if(itr->child[data-'a'] == NULL){

                newNode = new TrieNode(data);
                itr->child[data-'a'] = newNode;
            }
            else{

                newNode = itr->child[data-'a'];
            }

            itr = newNode;

            itr->startCount += 1;
            i++;
        }

        itr->endCount += 1;
    }

    // countWordsStartWith() -> count words that starts with
    int countWordsStartWith(string word){

        TrieNode* itr = root;
        int i = 0;

        while(i < word.size()){

            char data = word[i];
            
            if(itr->child[data-'a'] == NULL){

                return 0;
            }
            else{

                itr = itr->child[data-'a'];
            }
            
            i++;
        }

        return itr->startCount;
    }

    // countWordsEndWith() -> count words that ends with
    int countWordsEndWith(string word){

        TrieNode* itr = root;
        int i = 0;

        while(i < word.size()){

            char data = word[i];
            
            if(itr->child[data-'a'] == NULL){

                return 0;
            }
            else{

                itr = itr->child[data-'a'];
            }
            
            i++;
        }

        return itr->endCount;
    }

    // erase() word from trie
    void erase(string word){

        TrieNode* itr = root;
        int i = 0;

        while(i < word.size()){

            char data = word[i];
            
            if(itr->child[data-'a'] == NULL){

                return;
            }
            else{

                itr = itr->child[data-'a'];
            }

            itr->startCount -= 1;
            i++;
        }

        itr->endCount -= 1;
    }
};

int main()
{
    Trie t;

    // Insert Words
    t.insert("Coding");
    t.insert("Coding");
    t.insert("Hacker");

    cout << "Words Start : " << t.countWordsStartWith("Cod") << endl; 
    cout << "Words End : " << t.countWordsEndWith("Hack") << endl;

    t.erase("Coding");

    cout << "Words Start : " << t.countWordsStartWith("C") << endl; 
    cout << "Words End : " << t.countWordsEndWith("Hacker") << endl;

    cout << endl;
    return 0;
}