#include <iostream>
#include <algorithm>
using namespace std;

// Method 1 : Brute Force [Sorting after each deletion]
// Time Complexity : O(n + k)  Space Complexity : O(26)
int gameWithString(string input, int k){

    if(input.size() == 0) return 0;

    // Store the frequency 
    int freq[26] = {0};
    
    for(int i=0; i<input.size(); i++){

        freq[input[i]-'a']++;
    }

    // Get initial value
    int value = 0;

    for(int i=0; i<26; i++){

        value += (freq[i] * freq[i]);
    }

    while(k--){

        // Sort in Decreasing
        sort(freq, freq + 26, greater<int>());

        if(freq[0] > 0){

            freq[0]--;
        }

        // Get value of string again
        value = 0;

        for(int i=0; i<26; i++){

            value += (freq[i] * freq[i]);
        }
    }

    return value;
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