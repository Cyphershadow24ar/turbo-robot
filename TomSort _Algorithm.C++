#include <iostream>
#include <vector>

using namespace std;

void TomSort(vector<int>& arr) {
    int n = arr.size();

    // Base case: If the array has 0 or 1 elements, it's already sorted
    if (n <= 1) {
        return;
    }

    // Divide the array into two halves
    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    // Recursively sort   
 the left and right halves
    TomSort(left);
    TomSort(right);

    // Merge the sorted halves
    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Unsorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    TomSort(arr);

    cout << "\nSorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
