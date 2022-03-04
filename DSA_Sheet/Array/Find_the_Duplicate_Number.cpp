#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Method 5 : Using sorting
// Time Complexity : O(n * log(n))    Space Complexity : O(1)
int findDuplicate(vector<int>& nums) {

    int result = 0;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-1; i++){

        if(nums[i+1] == nums[i]){

            result = nums[i];
            break;
        }
    }

    return result;
}

// Method 4 : Using Iteartive method 
// Time Complexity : O(n)    Space Complexity : O(1)
// int findDuplicate(vector<int>& nums) {

//     while(nums[0] != nums[nums[0]]){

//         swap(nums[0], nums[nums[0]]);
//     }

//     return nums[0];
// }
 
// Method 3 : Using Xor 
// Time Complexity : O(n)    Space Complexity : O(1)
// int findDuplicate(vector<int>& nums) {
    
//     if(nums.size() < 2) return 0;
    
//     int xorTrack = 0;
    
//     for(int i=0; i<nums.size(); i++){
        
//         if(i != nums.size()-1)
//             xorTrack = (xorTrack ^ (i+1));
        
//         xorTrack = (xorTrack ^ nums[i]);
//     }   
    
//     return xorTrack;
// }
    
// Method 2 : Using negative marking
// Time Complexity : O(n)    Space Complexity : O(1)
// int findDuplicate(vector<int>& nums) {

//     int result = 0;

//     for(int i=0; i<nums.size(); i++){
    
//         if(nums[abs(nums[i]) - 1] < 0){
        
//             result = abs(nums[i]);
//             break;
//         }
        
//         nums[abs(nums[i]) - 1] *= -1;
//     }
           
//     return result;
// }
    
// Method 1 : Using Map (extra space)
// Time Complexity : O(n)    Space Complexity : O(n)
// int findDuplicate(vector<int>& nums) {
    
//     map<int, int> track;
    
//     for(int i=0; i<nums.size(); i++){
        
//         if(track.find(nums[i]) != track.end()){
            
//             return nums[i];
//         }
//         else{
            
//             track[nums[i]] = 1;
//         }
//     }
            
//     return -1;
// }


int main()
{
    int n;
    cout <<"Enter the size of the array : ";
    cin>> n;

    vector<int> arr(n);;
    cout <<"Enter the elements of the array : ";
    
    for(int i=0; i<n; i++){

        cin>> arr[i];
    }

    int result = findDuplicate(arr);
    cout <<"Repeated Number is : " <<result;

    cout<<endl;
    return 0;
}