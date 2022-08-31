#include <iostream>
#include <vector>
using namespace std;

// Method : Using Trie
// Time Complexity : O(|s| * n * m)  Space Complexity : O(n * m)
// s -> search string   n -> word list size  m -> max word size in list
class TrieNode {

    public:
        char data;
        TrieNode* child[26];
        bool isEnd;

    TrieNode(char data){

        this->data = data;
        this->isEnd = false;

        for(int i=0; i<26; i++){

            child[i] = NULL;
        }
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

void printWords(TrieNode* node, string s, vector<string> &list){

    if(node == NULL)  return;

    s += node->data;

    // If word is terminating 
    if(node->isEnd)
        list.push_back(s);


    for(int i=0; i<26; i++){

        if(node->child[i] != NULL){

            printWords(node->child[i], s, list);
        }
    }
}

vector< vector<string> > phoneDirectory(vector<string> &words, string &search){

    vector< vector<string> > output;

    // Create a trie
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<words.size(); i++){

        insertWord(root, words[i], 0);
    }

    // Implement Directory
    TrieNode* itrLast = root;
    string prefix = "";
    
    for(int i=0; i<search.size(); i++){

        if(itrLast->child[search[i]-'a'] == NULL){

            return output;
        }
        else{

            itrLast = itrLast->child[search[i]-'a'];

            vector<string> list;
            printWords(itrLast, prefix, list);

            
            prefix += search[i];
            output.push_back(list);
        }
    }

    return output;
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

    cout << "Enter Search String : ";
    string search;
    cin >> search;

    // Phone Directory
    vector< vector<string> > output = phoneDirectory(words, search);

    cout << "Search Results : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[i].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}