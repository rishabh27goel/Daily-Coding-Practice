#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Brute Force (Start from every Pump) [Circular Queue Based]
// Time Complexity : O(n ^ 2)   Space Complexity : O(1)
// int circularTour(vector<int> petrol, vector<int> distance){

//     int tank = 0;
//     int start = 0;
//     int travel = 0;

//     while(start < petrol.size()){

//         tank = tank + petrol[travel] - distance[travel];

//         // We can't reach to Petrol Pump
//         if(tank < 0){

//             tank = 0;
//             start = start + 1;
//             travel = start;
//             continue;
//         }
//         else{

//             travel = (travel + 1) % petrol.size();
//         }

//         // We are able to reach to start
//         if(start == travel) return start;
//     }

//     return -1;
// }

// Method 2 : Optimised from Above [Circular Queue Based]
// Time Complexity : O(n ^ 2)   Space Complexity : O(1)
// int circularTour(vector<int> petrol, vector<int> distance){

//     int tank = 0;
//     int start = 0;
//     int travel = 0;

//     while(start < petrol.size()){

//         tank = tank + petrol[travel] - distance[travel];

//         if(tank < 0){

//             tank = 0;

//             // If start to travel not possible then there is no
//             // point of traversing till travel we will start from travel + 1

//             // Reason : If tank + petrol[travel] - distance[travel] is negative then
//             // petrol[travel] - distance[travel] will always be negative [And can not happen]

//             if(travel < start){

//                 start = start + 1;
//             }
//             else{

//                 start = travel + 1;
//             }

//             travel = start;

//             continue;
//         }
//         else{

//             travel = (travel + 1) % petrol.size();
//         }

//         if(start == travel) return start;
//     }

//     return -1;
// }

// Method 3 : Single Tour [Keep track of Deficit]
// Time Complexity : O(n)   Space Complexity : O(1)
int circularTour(vector<int> petrol, vector<int> distance){

    int tank = 0;
    int deficit = 0;

    int start = 0;
    int travel = 0;
    
    while(travel < petrol.size()){

        tank = tank + petrol[travel] - distance[travel];

        if(tank < 0){

            // Deficit is keeping track of all petrol needed till travel index 
            // [Can be individual or combination of some pumps]
            deficit += tank;
            tank = 0;
            start = travel + 1;
        }

        travel = travel + 1;
    }

    if(tank + deficit >= 0){

        return start;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter number of petrol pumps : ";
    cin >> n;

    int data;
    cout << "Enter petrol values : ";
    vector<int> petrol;
    for(int i=0; i<n; i++){

        cin >> data;
        petrol.push_back(data);
    }

    cout << "Enter distance values : ";
    vector<int> distance;
    for(int i=0; i<n; i++){

        cin >> data;
        distance.push_back(data);
    }

    int index = circularTour(petrol, distance);

    if(index == -1){

        cout << "Circular Tour Not Possible !!";
    }
    else{

        cout << "Circular Tour Possible At : " << index;
    }

    cout << endl;
    return 0;
}