#include <iostream>
#include <vector>
using namespace std;

// Method : Using Trie
// Time Complexity : O()  Space Complexity : O()
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

void insertWord(TrieNode* node, string &word, int index){

    if(index == word.size()){

        node->isEnd = true;
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
    }

    insertWord(newNode, word, index + 1);
}

string longestString(vector<string> &words){

    // Create a trie
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<words.size(); i++){

        insertWord(root, words[i], 0);
    }

    // Now check the longest string with all prefixed in the array
    int ind = -1;
    int size = 0;

    for(int i=0; i<words.size(); i++){

        TrieNode* itr = root;
        int j = 0;

        while(j < words[i].size()){

            itr = itr->child[words[i][j]-'a'];

            if(itr->isEnd == false)
                break;

            j++;
        }   

        if(j == words[i].size()){

            if(j > size){

                size = j;
                ind = i;
            }
            else if(j == size){

                if(words[i] < words[ind]){

                    ind = i;
                }
            }
        }
    }

    if(ind == -1)
        return "";

    return words[ind];
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector <string> words;

    for(int i=0; i<size; i++){

        string s;
        cin >> s;

        words.push_back(s);
    }

    // Longest string with all prefixes
    string output = longestString(words);

    cout << "Longest String : " << output;

    cout << endl;
    return 0;
}