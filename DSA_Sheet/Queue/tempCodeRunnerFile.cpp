vector<vector<int> > distanceNearestCell(vector<vector<int> > matrix){

//     int m = matrix.size();
//     if(m == 0) return matrix;
//     int n = matrix[0].size();

//     vector<vector<int> > output(m, vector<int> (n, 0));

//     // Iterate & check each element
//     for(int i=0; i<m; i++){

//         for(int j=0; j<n; j++){

//             if(matrix[i][j] == 1){

//                 output[i][j] = 0;
//             }
//             else{

//                 // If matrix[i][j] is 0
//                 int getMin = INT_MAX;

//                 for(int x=0; x<m; x++){

//                     for(int y=0; y<n; y++){

//                         if(matrix[x][y] == 1){

//                             getMin = min(getMin, abs(x-i) + abs(y-j));
//                         }
//                     }
//                 }

//                 output[i][j] = getMin; 
//             }
//         }
//     }

//     return output;
// }