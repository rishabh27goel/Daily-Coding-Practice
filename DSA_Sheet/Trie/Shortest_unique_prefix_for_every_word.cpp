#include <iostream>
#include <vector>
using namespace std;

// Method : Using Trie 
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
class TrieNode {

    public:
        char data;
        TrieNode* child[26];
        int wordCount;

    TrieNode(char data){

        this->data = data;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }

        this->wordCount = 1;
    }
};

void insertWord(TrieNode* node, string &word, int index){

    if(index == word.size()){

        return;
    }

    char data = word[index];
    TrieNode* newNode;

    if(node->child[data-'a'] == NULL){

        newNode = new TrieNode(data);
        node->child[data-'a'] = newNode;
    }
    else{

        newNode = node->child[data-'a'];
        newNode->wordCount += 1;
    }

    insertWord(newNode, word, index + 1);
}

vector<string> shortestUniquePrefix(vector<string> &words){

    vector <string> prefix;

    // Create a trie
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<words.size(); i++){

        insertWord(root, words[i], 0);
    }

    // Create shortest unique prefix
    for(int i=0; i<words.size(); i++){

        TrieNode* itr = root;
    
        int j = 0;
        string pfx = "";

        while(j < words[i].size() && itr->child[words[i][j]-'a'] != NULL){

            itr = itr->child[words[i][j]-'a'];

            pfx += words[i][j];

            // When no other word is present with this character
            if(itr->wordCount == 1)
                break;

            j++;
        }

        prefix.push_back(pfx);
    }

    return prefix;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <string> words;

    cout << "Enter words : ";
    for(int i=0; i<size; i++){

        string s;
        cin >> s;

        words.push_back(s);
    }

    // Shortest Unique Prefix
    vector<string> prefix = shortestUniquePrefix(words);

    cout << "Shortest Unique Prefix : ";
    for(int i=0; i<prefix.size(); i++){

        cout << prefix[i] << " ";
    }

    cout << endl;
    return 0;
}