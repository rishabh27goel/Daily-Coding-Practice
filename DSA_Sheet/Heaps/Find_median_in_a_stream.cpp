#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Using Sort Function
// Time Complexity : O(n * n * log(n))  Space Complexity : O(n)
// vector<int> findMedian(vector<int> &arr){

//     vector<int> output;
//     if(arr.size() == 0) return output;

//     vector<int> median;

//     for(int i=0; i<arr.size(); i++){

//         // Store element 
//         median.push_back(arr[i]);

//         // Sort the stream vector
//         sort(median.begin(), median.end());

//         int n = median.size();

//         if(n % 2 == 0){

//             output.push_back((median[(n-1)/2] + median[n/2]) / 2);
//         }
//         else{

//             output.push_back(median[n/2]);
//         }
//     }

//     return output;
// }

// Method 2 : Insertion in sorted form
// Time Complexity : O(n * n)  Space Complexity : O(n)
// void searchData(vector<int> &median, int value){

//     int i = 0;
//     int j = median.size()-1;


//     while(i < j){

//         int mid = (i + j) / 2;

//         if(median[mid] > value){

//             j = mid - 1;
//         }
//         else{

//             i = mid + 1;
//         }
//     }

//     if(median.size() == 0 || value < median[i]){

//         median.insert(median.begin() + i, value);
//     }
//     else{

//         median.insert(median.begin() + i + 1, value);
//     }
// }

// vector<int> findMedian(vector<int> &arr){

//     vector<int> output;
//     if(arr.size() == 0) return output;

//     vector<int> median;

//     for(int i=0; i<arr.size(); i++){

//         searchData(median, arr[i]);

//         int n = median.size();

//         if(n % 2 == 0){

//             output.push_back((median[(n-1)/2] + median[n/2]) / 2);
//         }
//         else{

//             output.push_back(median[n/2]);
//         }
//     }

//     return output;
// }

// Method 3 : Using Min Heap and Max Heap
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
void insertData(priority_queue <int> &left, priority_queue <int, vector<int>, greater<int> > &right, double &median, int value){

    if(left.size() == right.size()){

        if(median < value){

            right.push(value);
            median = right.top();
        }
        else{

            left.push(value);
            median = left.top();
        }
    }
    else if(left.size() > right.size()){

        if(median < value){

            right.push(value);
        }
        else{

            int x = left.top();
            left.pop();

            left.push(value);
            right.push(x);
        }

        median = (left.top() + right.top()) / 2;
    }
    else if(left.size() < right.size()){

        if(median < value){

            int x = right.top();
            right.pop();

            left.push(x);
            right.push(value);
        }
        else{

            left.push(value);
        }

        median = (left.top() + right.top()) / 2;
    }
}

vector<int> findMedian(vector<int> &arr){

    vector<int> output;
    if(arr.size() == 0) return output;

    // For storing median
    double median = 0;

    // Max Heap for Left
    priority_queue <int> left;
 
    // Min Heap for Right
    priority_queue <int, vector<int>, greater<int> > right;

    

    for(int i=0; i<arr.size(); i++){

        insertData(left, right, median, arr[i]);
        output.push_back((int) median);
    }

    return output;
}

int main()
{
    cout << "Enter size : ";
    int size;
    cin >> size;

    // Input { 9384 887 2778 6916 7794 8336 5387 493 6650 }
    cout << "Enter array : ";
    vector <int> arr;
    int data;

    for(int i=0; i<size; i++){

        cin >> data;
        arr.push_back(data);
    }

    // Find the median in the stream
    vector<int> output = findMedian(arr);

    cout << "Medians in Stream : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}