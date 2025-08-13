#include <iostream>
using namespace std;

// Design the logic to remove the duplicate elements from an Array
// and after the deletion the array should contain the unique elements.
class duplicate {
    // creating an array 
    int i, n, j;
    int arr[100];

public:
    void create() {
        cout << "enter no:" << endl;
        cin >> n;
        cout << "enter elements:" << endl;
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "the final array is: " << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    void duplicatelm() {
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    // Shift elements to left
                    for (int m = j; m < n - 1; m++) {
                        arr[m] = arr[m + 1];
                    }
                    n--;  // reduce size
                    j--;  // recheck same position after shifting
                }
            }
        }

        cout << "Array after removing duplicates: " << endl;
        for (i = 0; i < n; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};

int main() {
    duplicate d;
    d.create();
    d.duplicatelm();
    return 0;
}
