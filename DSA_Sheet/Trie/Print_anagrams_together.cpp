#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Method 1 : Using Hashmap
// Time Complexity : O(n * m)  Space Complexity : O((n * m) + constant[for creating key])
// vector< vector<string> > groupAnagrams(vector<string> &words){

//     vector< vector<string> > output;

//     unordered_map <string, vector<string> > store;

//     // Create a hash key using count of character
//     for(int i=0; i<words.size(); i++){

//         int wordCount[26] = {0};

//         for(int j=0; j<words[i].size(); j++){

//             wordCount[words[i][j]-'a']++;
//         }

//         // Create key using count array
//         string key = "";

//         for(int i=0; i<26; i++){

//             key = key + (char) ('a' + i) + (char) ('0' + wordCount[i]);
//         }

//         store[key].push_back(words[i]);
//     }

//     unordered_map <string, vector<string> > :: iterator itr;;

//     for(itr = store.begin(); itr != store.end(); itr++){

//         output.push_back(itr->second);
//     }

//     return output;
// }


// Method 2 : Using Trie
// Time Complexity : O((n * m) + (n * m * log(m)))  Space Complexity : O(n * m)
class TrieNode {

    public:
        char data;
        bool isEnd;
        vector<int> wordIndex;
        TrieNode* child[26];

    TrieNode(char data){

        this->data = data;
        this->isEnd = false;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }
    }
};

void insertWord(TrieNode* node, string &word, int index, int num){

    if(index == word.size()){

        node->isEnd = true;
        node->wordIndex.push_back(num);

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

    insertWord(newNode, word, index + 1, num);
}

void addAnagrams(TrieNode* node, vector<string> &words, vector< vector<string> > &output){

    if(node == NULL)  return;

    if(node->isEnd){

        vector<string> sub;

        for(int i=0; i<node->wordIndex.size(); i++){

            sub.push_back(words[node->wordIndex[i]]);
        }

        output.push_back(sub);
    }

    for(int i=0; i<26; i++){

        if(node->child[i] != NULL){

            addAnagrams(node->child[i], words, output);
        }
    }
}

vector< vector<string> > groupAnagrams(vector<string> &words){

    vector< vector<string> > output;

    // Insert words in trie
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<words.size(); i++){

        string tmp = words[i];
        sort(tmp.begin(), tmp.end());

        insertWord(root, tmp, 0, i);
    }

    // Add anagrams to output vector
    addAnagrams(root, words, output);

    return output;
}


int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<string> words; 

    cout << "Enter words : ";
    for(int i=0; i<size; i++){

        string s;
        cin >> s;

        words.push_back(s);
    }

    // Print Anagrams Together
    vector< vector<string> > output = groupAnagrams(words);


    cout << "Anagrams Groups : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[i].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}