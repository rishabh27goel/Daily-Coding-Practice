#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Method : Greedy Approach
// Time Complexity : O(V^2)  Space Complexity : O(V^2)
int findMax(vector<int> &amount, int n){

    int index = 0;

    for(int i=1; i<n; i++){

        if(amount[i] > amount[index])
            index = i;
    }

    return index;
}

int findMin(vector<int> &amount, int n){

    int index = 0;

    for(int i=1; i<n; i++){

        if(amount[i] < amount[index])
            index = i;
    }

    return index;
}

void minimizeCashFlowUtil(vector<int> &amount, int n){

    int maxCredit = findMax(amount, n);
    int minDebit = findMin(amount, n);

    // Termination Condition [When things are Balanced]
    if(amount[minDebit] == 0 && amount[maxCredit] == 0)
        return;

    // Find the minimum amount to be settled first
    int minAmount = min(-amount[minDebit], amount[maxCredit]);

    // Update Cash Amount
    amount[minDebit] += minAmount;
    amount[maxCredit] -= minAmount;

    cout << "Friend " << minDebit << " pays " << minAmount << " to " << "Friend " << maxCredit << endl;

    minimizeCashFlowUtil(amount, n);
}

void minimizeCashFlow(int n, vector< vector<int> > &flow){

    // Step 1 : Create Adjacency Matrix
    vector< vector<int> > cashMatrix(n, vector<int> (n, 0));

    for(int i=0; i<flow.size(); i++){

        int f1 = flow[i][0];
        int f2 = flow[i][1];
        int cash = flow[i][2];

        cashMatrix[f1][f2] = cash;
    }

    // Step 2 : Store net amount (Credit - Debit)
    vector<int> amount(n, 0);

    for(int f=0; f<n; f++){

        for(int i=0; i<n; i++){

            amount[f] += (cashMatrix[i][f] - cashMatrix[f][i]);
        }
    }

    // Step 3 : Minimize Cash Flow
    minimizeCashFlowUtil(amount, n);
}

int main()
{
    cout << "Enter number of friends : ";
    int n;
    cin >> n;

    vector< vector<int> > flow;

    cout << "Enter number of flows : ";
    int m;
    cin >> m;

    for(int i=0; i<m; i++){

        int u, v, cash;
        cin >> u >> v >> cash;

        vector<int> edge;

        edge.push_back(u);
        edge.push_back(v);
        edge.push_back(cash);

        flow.push_back(edge);
    }

    // Minimize Cash Flow
    minimizeCashFlow(n, flow);

    cout << endl;
    return 0;
}