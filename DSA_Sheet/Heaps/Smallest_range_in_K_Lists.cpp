#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Keeping track of indexes and (min and max element)
// Time Complexity : O(k * n * k)  Space Complexity : O(k)
// pair<int, int> smallestRange(vector< vector<int> > &kSorted){

//     pair<int, int> output = make_pair(0, 0);
//     if(kSorted.size() == 0) return output;

//     // For keeping track for index
//     vector<int> index(kSorted.size(), 0);
//     int minRange = INT_MAX;

//     // First element from K Sorted 
//     while(true){

//         pair<int, int> minIndex;

//         int minLimit = INT_MAX;
//         int maxLimit = INT_MIN;

//         for(int i=0; i<kSorted.size(); i++){

//             if(kSorted[i].size() == 0) continue;

//             if(minLimit > kSorted[i][index[i]]){

//                 minLimit = kSorted[i][index[i]];
//                 minIndex = make_pair(i, index[i]);
//             }

//             if(maxLimit < kSorted[i][index[i]]){

//                 maxLimit = kSorted[i][index[i]];
//             }
//         }

//         if(minRange > (maxLimit - minLimit)){

//             minRange = maxLimit - minLimit;
//             output = make_pair(minLimit, maxLimit);
//         }

//         // Insert Element for Checking
//         if(minIndex.second + 1 < kSorted[minIndex.first].size()){

//             index[minIndex.first] = minIndex.second + 1;
//         }
//         else{

//             break;
//         }
//     }

//     return output;
// }

// Method 2 : Keeping track of indexes and (min and max element)
// Time Complexity : O(k * n * log(k))  Space Complexity : O(k)
class Store {
        
    public:
        int value;
        int row;
        int col;
    
    Store(int value, int row, int col){
        
        this->value = value;
        this->row = row;
        this->col = col;
    }
};

class CompareData {
    
    public:
        bool operator()(Store* s1, Store* s2){
            
            return s1->value > s2->value;
        }
    
};

pair<int, int> smallestRange(vector< vector<int> > &kSorted){

    pair<int, int> output;
    if(kSorted.size() == 0) return output;

    priority_queue <Store*, vector<Store*>, CompareData> pq;
    int maxLimit = INT_MIN;
    int minRange = INT_MAX;

    // First element of K Sorted 
    for(int i=0; i<kSorted.size(); i++){

        if(kSorted.size()){

            maxLimit = max(maxLimit, kSorted[i][0]);
            pq.push(new Store(kSorted[i][0], i, 0));
        }
    }

    // Rest Elements
    while(!pq.empty()){

        Store* top = pq.top();
        pq.pop();

        int minLimit = top->value;
        int row = top->row;
        int col = top->col;

        if(minRange > (maxLimit - minLimit)){

            minRange = maxLimit - minLimit;
            output = make_pair(minLimit, maxLimit);
        }

        if(col + 1 < kSorted[row].size()){

            maxLimit = max(maxLimit, kSorted[row][col+1]);
            pq.push(new Store(kSorted[row][col+1], row, col+1));
        }
        else{

            break;
        }
    }


    return output;
}

int main()
{
    cout << "Enter k : ";
    int k;
    cin >> k;

    vector< vector<int> > kSorted;
    int data;

    for(int i=0; i<k; i++){

        vector<int> input;
        cout << "Enter data : ";
        data = 0;

        while(data != -1){

            cin >> data;
            if(data == -1) break;

            input.push_back(data);
        }

        kSorted.push_back(input);
    }

    // Smallest Range in K List
    pair<int, int> pr = smallestRange(kSorted);

    cout << "Smallest Range is : " << pr.first << " " << pr.second;

    cout << endl;
    return 0;
}