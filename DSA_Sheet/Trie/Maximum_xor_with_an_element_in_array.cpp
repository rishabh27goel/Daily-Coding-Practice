#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(q * n)  Space Complexity : O(1)   
// vector<int> maximumXor(vector<int> &arr, vector< pair<int, int> > &query){

//     vector<int> output;

//     for(int i=0; i<query.size(); i++){

//         int x = query[i].first;
//         int y = query[i].second;

//         int maxXor = -1;

//         // Find the xor for query
//         for(int j=0; j<arr.size(); j++){

//             if(arr[j] <= y){

//                 maxXor = max (maxXor, arr[j] ^ x);
//             }
//         }

//         output.push_back(maxXor);
//     }

//     return output;
// } 

// Method 2 : Using Trie
// Time Complexity : O(q*log(q) + n*log(n) + 32*(q + n))  Space Complexity : O(q + (32 * n))   
class TrieNode {

    public:
        TrieNode* child[2];
        int number;

    TrieNode(){

        for(int i=0; i<2; i++){

            child[i] = NULL;
        }

        this->number = -1;
    }
};

void insertNumber(TrieNode* node, int index, int number){

    if(index == 0){

        node->number = number;
        return;
    }

    int data = (number & (1 << (index-1))) ? 1 : 0;
    TrieNode* newNode;

    if(node->child[data] == NULL){

        newNode = new TrieNode();
        node->child[data] = newNode;
    }
    else{

        newNode = node->child[data];
    }

    insertNumber(newNode, index-1, number);
}

void findXor(TrieNode* node, int index, int number, int &maxXor){

    if(node == NULL)  return;

    if(node->number != -1){

        maxXor = (node->number ^ number);
        return;
    }

    int org = (number & (1 << (index-1))) ? 1 : 0;
    int data = !org;

    if(node->child[data] == NULL){

        findXor(node->child[org], index-1, number, maxXor);
    }
    else{

        findXor(node->child[data], index-1, number, maxXor);
    }
}

vector<int> maximumXor(vector<int> &arr, vector< pair<int, int> > &query){

    vector<int> output(query.size());

    // Sort the queries array
    vector< pair<int, pair<int, int> > > updatedQuery;

    for(int i=0; i<query.size(); i++){

        updatedQuery.push_back(make_pair(query[i].second, make_pair(query[i].first, i)));
    }

    // Sort the vectors
    sort(updatedQuery.begin(), updatedQuery.end());
    sort(arr.begin(), arr.end());

    // Get the xor for queries
    TrieNode* root = new TrieNode();
    int j = 0;

    for(int i=0; i<updatedQuery.size(); i++){

        int x = updatedQuery[i].first;
        int y = updatedQuery[i].second.first;
        int ind = updatedQuery[i].second.second;

        while(j < arr.size() && arr[j] <= x){

            insertNumber(root, 31, arr[j]);
            j++;
        }

        int maxXor = -1;
        findXor(root, 31, y, maxXor);

        output[ind] = maxXor;
    }

    return output;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    vector<int> arr(size);

    cout << "Enter array : ";
    for(int i=0; i<size; i++){

        cin >> arr[i];
    }

    cout << "Enter query size : ";
    int qs;
    cin >> qs;

    vector< pair<int, int> > query;

    cout << "Enter queries : ";
    for(int i=0; i<qs; i++){

        int a, b;
        cin >> a >> b;

        query.push_back(make_pair(a, b));
    }

    // Maximum xor with an element
    vector<int> output = maximumXor(arr, query);

    cout << "Maximum Xor : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}