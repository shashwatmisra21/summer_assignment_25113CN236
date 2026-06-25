#include <iostream>
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0; 
    int j = 0; 
    int k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int merged[n1 + n2];

    mergeSortedArrays(arr1, n1, arr2, n2, merged);

    std::cout << "Merged Sorted Array: ";
    for (int x = 0; x < n1 + n2; x++) {
        std::cout << merged[x] << " ";
    }
    std::cout << std::endl;

    return 0;
}
