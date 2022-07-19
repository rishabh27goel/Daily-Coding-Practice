#include <iostream>
using namespace std;

// Method : Backtracking 
// Time Complexity : O(n * (n ^ k))  Space Complexity : O(n)
void largestNumberHelper(string &number, string &maxNum, int start, int k){

    if(k == 0 || start >= number.size()) return;

    char maxChar = number[start];

    // Find the max number ahead of start
    for(int i=start+1; i<number.size(); i++){

        if(number[i] > maxChar){

            maxChar = number[i];
        }
    }

    // If max is at start only
    if(maxChar != number[start])
        k--;

    for(int i=start; i<number.size(); i++){

        if(number[i] == maxChar){

            swap(number[i], number[start]);

            if(maxNum.compare(number) < 0){

                maxNum = number;
            }

            largestNumberHelper(number, maxNum, start+1, k);

            // Backtracking
            swap(number[i], number[start]);
        }
    }
}

string largestNumber(string number, int k){

    if(k == 0) return number;

    // Generate combinations by swapping and keep track of max number
    string maxNum = number;

    largestNumberHelper(number, maxNum, 0, k);

    return maxNum;
}

int main()
{
    cout << "Enter Input String : ";
    string number;
    cin >> number;

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    // Largest Number in K Swaps
    string largest = largestNumber(number, k);

    cout << "Largest Number is : " << largest;


    cout << endl;
    return 0;
}