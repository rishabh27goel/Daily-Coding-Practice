#include <iostream>
#include <vector>
using namespace std;

// Method : Using Trie & Dynamic Programming
// Time Complexity : O((n * m) + N)   Space Complexity : O((n * m) + N)
// N - Input String   n - words array size  m - max word size
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

bool wordBreak(string input, vector<string> &words){

    // Create Trie
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<words.size(); i++){

        insertWord(root, words[i], 0);
    }

    // Use memoization to keep track of all the words and combinations
    vector <bool> dp(input.size() + 1, false); 
    int i = 0;

    // Start as empty string
    // Now reach all the words using trie which can be the starting words 
    dp[0] = true;

    for(int i=0; i<input.size(); i++){

        if(dp[i] == false)  continue; 
            
        TrieNode* itr = root;
        int j = i;

        while(j < input.size() && itr->child[input[j]-'a'] != NULL){

            itr = itr->child[input[j++]-'a'];

            // Mark the nodes which are terminal
            if(itr->isEnd)
                dp[j] = true;
        }

    }

    return dp[input.size()];
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<string> words;

    cout << "Enter words : ";
    for(int i=0; i<size; i++){

        string str;
        cin >> str;

        words.push_back(str);
    }

    // Word Break
    wordBreak(input, words);

    cout << endl;
    return 0;
}