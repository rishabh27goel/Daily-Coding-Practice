#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// Method 1 : Brute Force [Sorting after each deletion]
// Time Complexity : O(n + k)  Space Complexity : O(26)
// int gameWithString(string input, int k){

//     if(input.size() == 0) return 0;

//     // Store the frequency 
//     int freq[26] = {0};
    
//     for(int i=0; i<input.size(); i++){

//         freq[input[i]-'a']++;
//     }

//     // Get initial value
//     int value = 0;

//     for(int i=0; i<26; i++){

//         value += (freq[i] * freq[i]);
//     }

//     while(k--){

//         // Sort in Decreasing
//         sort(freq, freq + 26, greater<int>());

//         value -= (freq[0] * freq[0]);

//         if(freq[0] > 0){

//             freq[0]--;
//         }

//         value += (freq[0] * freq[0]);
//     }

//     return value;
// }

// Method 2 : Using Priority Queue
// Time Complexity : O(n + k)  Space Complexity : O(26)
int gameWithString(string input, int k){

    if(input.size() == 0) return 0;

    // Get the count
    int count[26] = {0};

    for(int i=0; i<input.size(); i++){

        count[input[i]-'a']++;
    }

    int sum = 0;
    priority_queue <int> pq;

    for(int i=0; i<26; i++){

        pq.push(count[i]);
        sum += (count[i] * count[i]);
    }

    while(k--){

        int top = pq.top();
        pq.pop();


        sum -= (top * top);
        top -= 1;
        
        sum += (top * top);
        pq.push(top);
    }

    return sum;
}

int main()
{
    string input;
    cout << "Enter Input String : ";
    cin >> input;

    int k;
    cout << "Enter value of k : ";
    cin >> k;

    int value = gameWithString(input, k);
    cout << "String Value : " << value;

    cout << endl;
    return 0;
}