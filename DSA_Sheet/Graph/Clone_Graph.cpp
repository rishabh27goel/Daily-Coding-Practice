#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {

    public:
        int data;
        vector<Node*> neighbours;

    Node(int data){

        this->data = data;
        neighbours = vector<Node*> ();
    }
};

// For Printing purpose

// Method : Depth First Search [Mapping of Old to New Nodes]
// Time Complexity : O(V + E)  Space Complexity : O(V + E)
unordered_map <Node*, Node*> mapping;

Node* cloneGraph(Node* node){

    if(node == NULL) return NULL;

    // Create Copy of Node
    Node* newNode = new Node(node->data);
    mapping[node] = newNode;

    // Iterate all the childs
    for(int i=0; i<node->neighbours.size(); i++){

        // If we have not created the copy
        if(mapping.find(node->neighbours[i]) == mapping.end()){

            Node* newChild = cloneGraph(node->neighbours[i]);


            newNode->neighbours.push_back(newChild);
        }
        // If copy is created
        else{

            newNode->neighbours.push_back(mapping[node->neighbours[i]]);
        }
    }

    return newNode;
}

int main()
{
    cout << "Enter number of nodes : ";
    int n;
    cin >> n;

    // Creating a Graph
    unordered_map <int, Node*> store;

    for(int i=1; i<=n; i++){

        store[i] = new Node(i);
    }

    cout << "\nEnter Adjacency List : \n";

    for(int i=1; i<=n; i++){

        Node* node = store[i];

        cout << "Enter nodes of " << i << " : ";
        int data = 0;

        while(data != -1){

            cin >> data;

            if(data == -1)
                break;
            node->neighbours.push_back(store[data]);
        }
    }

    // Clone Graph
    Node* newGraph = cloneGraph(store[1]);

    cout << "\nNew Graph Created : \n";

    for(int i=1; i<=n; i++){

        Node* node = mapping[store[i]];

        cout << "Node " << i << " : ";

        for(int i=0; i<node->neighbours.size(); i++){

            cout << node->neighbours[i]->data << " ";
        }

        cout << endl;
    }



    cout << endl;
    return 0;
}