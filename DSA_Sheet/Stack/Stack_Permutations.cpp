#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Method : Using Stack
// Time Complexity : O(n)  Space Complexity : 
bool checkStackPermutation(vector<int> first, vector<int> second){

    if(first.size() == 0) return true;

    stack<int> st;
    int i = 0;
    int j = 0;

    while(i < first.size()){

        st.push(first[i]);

        while(!st.empty() && st.top() == second[j]){

            st.pop();
            j++;
        }

        i++;
    }

    return st.empty();
}

int main()
{
    cout << "Enter the size of the array : ";
    int n;
    cin >> n;

    vector<int> first;
    vector<int> second;
    int data;

    cout << "Enter first array : ";
    for(int i=0; i<n; i++){

        cin >> data;
        first.push_back(data);
    }
    
    cout << "Enter second array : ";
    for(int i=0; i<n; i++){

        cin >> data;
        second.push_back(data);
    }

    bool get = checkStackPermutation(first, second);

    if(get){

        cout << "Stack Permutation !!";
    }
    else{

        cout << "Not a Stack Permutation !!";
    }

    cout << endl;
    return 0;
}