#include <iostream>
#include <vector>
using namespace std;

void findUnion(int arr1[], int arr2[], int n1, int n2){

    int i = 0;
    int j = 0;
    vector<int> unionArray;

    while(i < n1 && j < n2){

        if(arr1[i] < arr2[j]){

            unionArray.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i] > arr2[j]){

            unionArray.push_back(arr2[j]);
            j++;
        }
        else{

            unionArray.push_back(arr2[j]);
            i++; j++;
        }
    }

    while(i < n1){

        unionArray.push_back(arr1[i]);
        i++;
    }

    while(j < n2){

        unionArray.push_back(arr2[j]);
        j++;
    }

    cout<<"Uni Array : ";
    for(int x = 0; x<unionArray.size(); x++){

        cout <<unionArray[x] <<" ";
    }

    cout<<endl;
}

void findIntersection(int arr1[], int arr2[], int n1, int n2){

    int i = 0;
    int j = 0;
    vector<int> intersectionArray;

    while(i < n1 && j < n2){

        if(arr1[i] < arr2[j]){

            i++;
        }
        else if(arr1[i] > arr2[j]){

            j++;
        }
        else{

            intersectionArray.push_back(arr1[i]);
            i++; j++;
        }
    }

    cout<<"Intersection Array : ";
    for(int x = 0; x<intersectionArray.size(); x++){

        cout <<intersectionArray[x] <<" ";
    }

    cout<<endl;
}

int main()
{
    int n1, n2;
    cout<<"Enter the size of the 1st array : ";
    cin>> n1;

    int arr1[n1];
    cout<<"Enter the elements of the 1st sorted array : ";
    for(int i=0; i<n1; i++){

        cin>> arr1[i];
    }

    cout<<"Enter the size of the 2nd array : ";
    cin>> n2;

    int arr2[n2];
    cout<<"Enter the elements of the 2nd sorted array : ";
    for(int i=0; i<n2; i++){

        cin>> arr2[i];
    }

    findUnion(arr1, arr2, n1, n2);
    findIntersection(arr1, arr2, n1, n2);

    return 0;
}