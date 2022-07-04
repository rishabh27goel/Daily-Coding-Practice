#include <iostream>
#include <queue>
using namespace std;

// Method 1 : Count array & two Iteration [Odd Position and Even Position] 
// Time Complexity : O(n)  Space Complexity : O(26)
// string reorganizeString(string input){

//     if(input.size() < 2) return input;

//     int count[26] = {0};

//     int maxIndex = 0;
//     int maxFreq = INT_MIN;

//     for(int i=0; i<input.size(); i++){

//         int x = input[i]-'a';

//         count[x]++;

//         if(maxFreq < count[x]){

//             maxFreq = count[x];
//             maxIndex = x;
//         }
//     }

//     // Not Possible to create string
//     if(maxFreq > (input.size() + 1) / 2) return "";

//     int i = 0;

//     while(maxFreq--){

//         input[i] = (char) (maxIndex + 'a');
//         i += 2;
//     }

//     for(int j=0; j<26; j++){

//         if(j == maxIndex || count[j] == 0) continue;
    
//         while(count[j]--){

//             if(i >= input.size())
//                 i = 1;

//             input[i] = (char) (j + 'a');
//             i += 2;
//         }
//     }

//     return input;
// }

// Method 2 : Using Max Heap & two Iteration [Odd Position and Even Position]
// Time Complexity : O(n)  Space Complexity : O(26 * log(26))
string reorganizeString(string input){

    if(input.size() < 2) return input;

    priority_queue < pair<int, char> > pq;
    
    int count[26] = {0};
    int maxFreq = INT_MIN;

    for(int i=0; i<input.size(); i++){

        int x = input[i]-'a';

        count[x]++;

        if(maxFreq < count[x]){

            maxFreq = count[x];
        }
    }

    // Not Possible to create string
    if(maxFreq > (input.size() + 1) / 2) return "";

    // Push count and character in Max Heap
    for(int i=0; i<26; i++){

        pq.push(make_pair(count[i], (char) (i + 'a')));
    }

    // Make the new string using max heap
    int i = 0;

    while(!pq.empty()){

        int count = pq.top().first;
        char ch = pq.top().second;
        pq.pop();

        while(count--){

            if(i >= input.size())
                i = 1;
        
            input[i] = ch;
            i += 2;
        }
    }

    return input;
}

int main()
{
    cout << "Enter Input : ";
    string input;
    cin >> input;

    // Reorganize String
    input = reorganizeString(input);

    if(input.size() == 0){

        cout << "Not Possible !";
    }
    else{

        cout << "Modified String is : " << input;
    }


    cout << endl;
    return 0;
}