#include<iostream>

using namespace std;

void MergeFunction(int * arr, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l;

    int new_arr[r];
    //check both subarray which element is smaller and put that in new_array

    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            new_arr[k] = arr[i];
            i++;

        } else {
            new_arr[k] = arr[j];
            j++;

        }
        k++;
    }

// check if first array ends but second still have some elemets so put them in the end and vice versa

    if (i > mid) {
        while (j <= r) {
            new_arr[k++] = arr[j++];

        }
    }
    else {
        while (i <= mid ) {
            new_arr[k++] = arr[i++];

        }

    }

    // now copy all elements of new_array into old array

    for (int h = l; h <= r; h++) {
        arr[h] = new_arr[h];
    }
}



void mergeSort(int * arr, int l, int r) {
    // run only if elements in the array are more than single element
    if (l < r) {

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        MergeFunction(arr, l, mid, r);
    }
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}
         // mam ne karwaya hai copy mai 