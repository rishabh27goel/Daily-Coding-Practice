#include <iostream>
using namespace std;

int largestRectangularArea(int *arr, int n){

    if(n == 1) return arr[0];

    int maxArea = INT_MIN;
    int area;

    // Iterate Histogram
    for(int i=0; i<n; i++){

        int count = 1;

        // Left Check
        for(int j=i-1; j>=0; j--){

            if(arr[j] < arr[i]){

                break;
            }
            else{

                count++;
            }
        }

        // Right Check
        for(int j=i+1; j<n; j++){

            if(arr[j] < arr[i]){

                break;
            }
            else{

                count++;
            }
        }

        area = (arr[i] * count);

        if(area > maxArea){

            maxArea = area;
        }
    }

    return maxArea;
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array : ";
    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    int maxValue = largestRectangularArea(arr, n);
    cout << "Max Area is : " << maxValue;

    cout << endl;
    return 0;
}