#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Creating prefix by iterating each word
// Time Complexity : O(n * m)  Space Complexity : O(1)
// n -> length of words array   m -> max word length
// string longestCommonPrefix(vector<string> &words){

//     if(words.size() == 1)  return words[0];

//     string prefix = "";

//     // Start iterating taking base as first word
//     int i = 0;

//     while(i < words[0].size()){

//         char ch = words[0][i];

//         // Check if character exits in all the words
//         for(int j=1; j<words.size(); j++){

//             if(i >= words[j].size() || words[j][i] != ch)
//                 return prefix;
//         }

//         prefix += ch;
//         i++;
//     }

//     return prefix;
// }

// Method 2 : Using trie data structure
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
class TrieNode {

    public:
        char data;
        TrieNode* child[26];
        bool isTerminal;
        int childCount;

    TrieNode(char data){

        this->data = data;
        
        for(int i=0; i<26; i++){

            child[i] = NULL;
        }

        this->isTerminal = false;
        this->childCount = 0;
    }
};

void insertWord(TrieNode* node, string &word, int index){

    if(index == word.size()){

        node->isTerminal = true;
        return;
    }

    char data = word[index];
    TrieNode* newNode;

    // If does not exists
    if(node->child[data-'a'] == NULL){

        newNode = new TrieNode(data);

        node->child[data-'a'] = newNode;
        node->childCount++;
    }
    else{

        newNode = node->child[data-'a'];
    }

    insertWord(newNode, word, index + 1);
}

string longestCommonPrefix(vector<string> &words){

    if(words.size() == 1)  return words[0];

    // Create trie for words
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<words.size(); i++){

        if(words[i].size() == 0)
            return "";

        insertWord(root, words[i], 0);
    }

    // Create the prefix using trie
    string prefix = "";
    TrieNode* itr = root;

    for(int i=0; i<words[0].size(); i++){

        char ch = words[0][i];

        if(itr->childCount != 1)  
            break;

        prefix += ch;
        itr = itr->child[ch-'a'];

        // If terminal is reached
        if(itr->isTerminal)  
            break;
    }

    return prefix;
}


int main()
{
    cout << "Enter number of words : ";
    int n;
    cin >> n;

    vector<string> words;

    for(int i=0; i<n; i++){

        string wd;
        cin >> wd;

        words.push_back(wd);
    } 

    // Longest Common Prefix
    string prefix = longestCommonPrefix(words);

    cout << "Common Prefix : " << prefix;

    cout << endl;
    return 0;
}