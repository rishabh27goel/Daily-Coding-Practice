#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// Method : Breadth First Search
// Time Complexity : O(m * m * n)  Space Complexity : O(m * n)
// m -> word size   n -> word list 
int wordLadder(string beginWord, string endWord, vector <string> &wordList){

    if(beginWord == endWord) return 1;

    // Push wordList in the set
    unordered_set <string> wordMap;
    
    for(int i=0; i<wordList.size(); i++){

        wordMap.insert(wordList[i]);
    }

    // Create Word Ladder [Using Queue]
    int count = 1;
    unordered_set <string> visited;
    queue <string> q;

    q.push(beginWord);
    visited.insert(beginWord);

    while(!q.empty()){

        int size = q.size();

        while(size--){

            string current = q.front();
            q.pop();

            if(endWord == current)
                return count;

            for(int i=0; i<current.size(); i++){

                char org = current[i];

                for(char ch='a'; ch<='z'; ch++){

                    current[i] = ch;

                    if(wordMap.find(current) != wordMap.end() && visited.find(current) == visited.end()){

                        q.push(current);
                        visited.insert(current);
                    }
                }

                current[i] = org;
            }
        }

        count++;
    }
    
 
    return 0;
}

int main()
{
    cout << "Enter begin word : ";
    string beginWord;
    cin >> beginWord;

    cout << "Enter end word : ";
    string endWord;
    cin >> endWord;

    vector <string> wordList;

    cout << "Enter words list size : ";
    int n;
    cin >> n;

    for(int i=0; i<n; i++){

        string word;
        cin >> word;

        wordList.push_back(word);
    }

    // Word Ladder
    int shortest = wordLadder(beginWord, endWord, wordList);

    cout << "Shortest Transformation : " << shortest;

    cout << endl;
    return 0;
}