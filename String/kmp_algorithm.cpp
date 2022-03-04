#include <iostream>
using namespace std;
#include <vector>

void createLPSVector(string needle, vector<int> &lps){

    int len = 0;
    lps[0] = 0;

    int i = 1;

    while(i < needle.size()){

        if(needle[len] == needle[i]){

            len++;
            lps[i] = len;
            i++;
        }
        else{

            if(len != 0){

                len = lps[len-1];
            }
            else{

                lps[i] = 0;
                i++;
            }
        }
    }
}

int myStrStr(string haystack, string needle){

    if(needle.size() == 0) return 0;
    if(needle.size() > haystack.size()) return -1;

    vector<int> lps(needle.size());

    createLPSVector(needle, lps);

    int i = 0;
    int j = 0;

    while(i < haystack.size()){

        if(haystack[i] == needle[j]){

            i++;
            j++;
        }

        if(j == needle.size()){

            cout<<"Match found at index "<< i-j<<endl;
            j = lps[j-1];
        }

        if(i < haystack.size() and haystack[i] != needle[j]){

            if(j != 0){

                j = lps[j-1];
            }
            else{

                i = i + 1;
            }
        }

    }

    return 0;
}

int main()
{
    cout<< "Enter haystack string: ";    
    string haystack;
    cin>> haystack;

    cout<<"Enter needle string: ";
    string needle;
    cin>> needle;

    int output = myStrStr(haystack, needle);
    // cout<< output;

    cout<<endl;
    return 0;
}