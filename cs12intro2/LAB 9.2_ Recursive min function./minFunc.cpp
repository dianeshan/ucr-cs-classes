#include "minFunc.h"

// const int * min(const int arr[], int arrSize) {
//     const int * mini; 
//     if (arrSize == 0) {
//         return 0;
//     }
//     if (arrSize == 1) {
//         return &arr[0];
//     }
//     else {
//         mini = min(arr, arrSize - 1);
//         if (arr[arrSize - 1] < *mini) {
//             return &arr[arrSize - 1];
//         }
//         else {
//             return mini;
//         }
//     }
// }

const int * min(const int arr[], int arrSize) {
    const int *mini;
    if (arrSize == 0) {
        return 0;
    }
    if (arrSize == 1) {
        return &arr[0];
    }
    else {
        mini = min(arr, arrSize - 1);
        if (arr[arrSize - 1] > *mini) {
            return mini;
        }
        return &arr[arrSize - 1];
    }    
}