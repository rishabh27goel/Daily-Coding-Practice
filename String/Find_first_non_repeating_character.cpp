#include <iostream>
using namespace std;

// Method 1 : Using HashMap and Double Pass
// Time Complexity : O(n)  Space Complexity : O(26)
// char firstNonRepeatingCharacter(string input){

//     if(input.size() == 0) return NULL;

//     // Store char count
//     int arr[26] = {0};

//     for(int i=0; i<input.size(); i++){

//         arr[input[i]-'a']++;
//     }

//     // Check for First Non-Repeating
//     for(int i=0; i<input.size(); i++){

//         if(arr[input[i]-'a'] == 1){

//             return input[i];
//         }
//     }

//     return NULL;
// }

// Method 2 : Using HashMap and Single Pass
// Time Complexity : O(n)  Space Complexity : O(2 * 26)
// char firstNonRepeatingCharacter(string input){

//     if(input.size() == 0) return NULL;

//     int arr[26][2] = {0};

//     // Store the Count and First Position of the Character
//     for(int i=0; i<input.size(); i++){

//         if(arr[input[i]-'a'][0] == 0){

            
//             arr[input[i]-'a'][1] = i;
//         }

//         arr[input[i]-'a'][0]++;
//     }

//     int min = INT_MAX;

//     for(int i=0; i<26; i++){

//         if(arr[i][0] == 1){

//             if(arr[i][1] < min){

//                 min = arr[i][1];
//             }
//         }
//     }

//     if(min == INT_MAX) return NULL;

//     return input[min];
// }

// Method 3 : Using HashMap and Single Pass
// Time Complexity : O(n)  Space Complexity : O(26)
char firstNonRepeatingCharacter(string input){

    if(input.size() == 0) return NULL;

    int arr[26] = {0};

    // Store First Position of the Character
    for(int i=0; i<input.size(); i++){

        if(arr[input[i]-'a'] == 0){

            arr[input[i]-'a'] = i+1;
        }
        else{

            arr[input[i]-'a'] = -1;
        }
    }

    int min = INT_MAX;

    for(int i=0; i<26; i++){

        if(arr[i] > 0 && arr[i] < min){

            min = arr[i]-1;
        }
    }

    if(min == INT_MAX) return NULL;

    return input[min];
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    // Find first non-repeating character
    char nonReap = firstNonRepeatingCharacter(input);

    if(nonReap != NULL){

        cout << "First Non-Repeating Character : " << nonReap;
    }
    else{

        cout << "Empty String !";
    }
    

    cout << endl;
    return 0;
}