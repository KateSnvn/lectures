#include <iostream>
#include <cmath>
using namespace std;

//3 вариант 

int main(){

//---------------------------------------------------------------------------------------- задача 1


    // int nums[6];
    // for (int i = 0; i < 6; ++i){
    //     cin >> nums[i];
    // }


    // bool same = false;
    // for (int i = 0; i < 6; i++){
    //     if (nums[i] == nums[i + 1]){
    //         same = true;
    //     }
    // }


    // if (same){
    //     for (int i = 0; i < 6; i++){
    //         for (int j = i + 1; j < 6; j++){
    //             if(nums[i] > nums[j]){
    //                 swap(nums[i], nums[j]);
    //             }
    //         }
    //     }
    // }

    // for (int i = 0; i < 6; i++){
    //         cout << nums[i] << " ";
    //     }


//---------------------------------------------------------------------------------------- задача 2

    int rows = 3;
    int cols = 4;
    int matrix[rows][cols];
    int max_sum = -1;
    int max_index = -1;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << " " << endl;

    for (int i = 0; i < rows; i++){
        int summa = 0;
        for (int j = 0; j < cols; j++){
            summa += abs(matrix[i][j]);
        }
        if (summa > max_sum){
            max_sum = summa;
            max_index = i;
        }
    }

    for (int j = 0; j < cols; j++){
        matrix[max_index][j] = 0;
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}