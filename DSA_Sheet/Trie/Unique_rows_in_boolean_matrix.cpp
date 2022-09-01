#include <iostream>
#include <vector>
using namespace std;

// Method : Using Trie 
// Time Complexity : O(n * m)  Space Complexity : O(n * m)
class TrieNode {

    public:
        int data;
        int index;
        TrieNode* child[2];
        bool isEnd;

    TrieNode(int data){

        this->data = data;
        this->index = -1;

        for(int i=0; i<2; i++){

            child[i] = NULL;
        }

        this->isEnd = false;
    }
};

void insertWord(TrieNode* node, vector<int> &arr, int index, int x){

    if(index == arr.size()){

        node->isEnd = true;

        if(node->index == -1){

            node->index = x;
        }

        return;
    }

    int data = arr[index];
    TrieNode* newNode;

    if(node->child[data] == NULL){

        newNode = new TrieNode(data);
        node->child[data] = newNode;
    }
    else{

        newNode = node->child[data];
    }

    insertWord(newNode, arr, index + 1, x);
}

void getRows(TrieNode* node, vector<int> &rowIndex){

    if(node == NULL)  return;

    if(node->isEnd){

        rowIndex.push_back(node->index);
    }

    for(int i=0; i<2; i++){

        if(node->child[i] != NULL){

            getRows(node->child[i], rowIndex);
        }
    }
}

vector< vector<int> > uniqueRows(vector< vector<int> > &matrix){

    vector< vector<int> > output;

    // Create a trie 
    TrieNode* root = new TrieNode('\0');

    for(int i=0; i<matrix.size(); i++){

        insertWord(root, matrix[i], 0, i);
    }

    // Get the indexes from trie
    vector<int> rowIndex;

    getRows(root, rowIndex);

    // Sort the index vector
    sort(rowIndex.begin(), rowIndex.end());

    for(int i=0; i<rowIndex.size(); i++){

        vector <int> sub;

        for(int j=0; j<matrix[rowIndex[i]].size(); j++){

            sub.push_back(matrix[rowIndex[i]][j]);
        }

        output.push_back(sub);
    }

    return output;
}

int main()
{
    cout << "Enter matrix size : ";
    int n, m;
    cin >> n >> m;

    vector< vector<int> > matrix(n, vector<int> (m));

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            cin >> matrix[i][j];
        }
    }

    // Unique Rows in matrix
    vector< vector<int> > output = uniqueRows(matrix);

    cout << "Unique Rows : \n";
    for(int i=0; i<output.size(); i++){

        for(int j=0; j<output[i].size(); j++){

            cout << output[i][j] << " ";
        }

        cout << endl;
    }


    cout << endl;
    return 0;
}