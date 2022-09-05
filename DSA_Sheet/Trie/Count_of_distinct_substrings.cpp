#include <iostream>
using namespace std;

// Method : Using Trie
// Time Complexity : O(n^2)  Space Complexity : O(26 * n)
class TrieNode {

    public:
        char data;
        TrieNode* child[26];

    TrieNode(char data){

        this->data = data;
        
        for(int i=0; i<26; i++){

            child[i] = NULL;
        }
    }
};

int countDistinct(string word){

    int count = 0;

    // Create trie for each substring
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<word.size(); i++){

        TrieNode* itr = root;
        int j = i;

        while(j < word.size()){

            char data = word[j];
            TrieNode* newNode;

            if(itr->child[data-'a'] == NULL){

                newNode = new TrieNode(data);
                itr->child[data-'a'] = newNode;
                count++;
            }
            else{

                newNode = itr->child[data-'a'];
            }

            itr = newNode;
            j++;
        }
    }


    return count;
}


int main()
{
    cout << "Enter string : ";
    string word;
    cin >> word;

    // Count Distinct Substring
    int count = countDistinct(word);

    cout << "Distinct Substring : " << count;

    cout << endl;
    return 0;
}