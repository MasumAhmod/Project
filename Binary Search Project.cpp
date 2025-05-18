#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

// Function to clear the console screen
void clearScreen() {
    system(CLEAR);
}

// Function to print the current search range along with the elements in the range.
void printSearchRange(const vector<int>& v, int l, int r) {
    // Show the current search range and the elements
    cout << "Current search range: [" << l << ", " << r << "] ";
    cout << "Elements in range: [";
    for (int i = l; i < r; i++) {
        cout << v[i];
        if (i != r - 1) cout << ", ";  // Add comma except after the last element
    }
    cout << "]\n";
}

bool isOkStandard(vector<int>& v, int x, int mid) {
    if (x >= v[mid]) return 0;
    return 1;
}

bool isOkUpperBound(vector<int>& v, int x, int mid) {
    if (x >= v[mid]) return 0;
    return 1;
}

bool isOkLowerBound(vector<int>& v, int x, int mid) {
    if (x > v[mid]) return 0;
    return 1;
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    int option;
    cout << "Choose search type (1 for Standard, 2 for Upper Bound, 3 for Lower Bound): ";
    cin >> option;

    int l = 0, r = v.size();
    int delay = 3000;  // Adjusted delay to 3 seconds (3000 milliseconds)

    clearScreen();  // Clear the screen before starting

    switch(option) {
        case 1: {
            // Standard Binary Search
            while (l < r) {
                int mid = (l + r) / 2;

                clearScreen();  // Clear the screen before showing the next step
                printSearchRange(v, l, r);  // Show the current range and elements
                cout << "Midpoint: v[" << mid << "] = " << v[mid] << "\n";
                cout << "Checking elements in range: ";
                for (int i = l; i < r; i++) {
                    cout << v[i] << " ";
                }
                cout << "\n";

                if (isOkStandard(v, key, mid) == 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }

                // Display process step and wait for a moment
                this_thread::sleep_for(chrono::milliseconds(delay));  // Adjust delay for 3 seconds
            }

            if (key == v[l - 1]) {
                cout << "Element found at index " << l << endl;
            } else {
                cout << "This value is not present in this list " << endl;
            }
            break;
        }
        case 2: {
            // Upper Bound Search
            while (l < r) {
                int mid = (l + r) / 2;

                clearScreen();  // Clear the screen before showing the next step
                printSearchRange(v, l, r);  // Show the current range and elements
                cout << "Midpoint: v[" << mid << "] = " << v[mid] << "\n";
                cout << "Checking elements in range: ";
                for (int i = l; i < r; i++) {
                    cout << v[i] << " ";
                }
                cout << "\n";

                if (isOkUpperBound(v, key, mid) == 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }

                // Display process step and wait for a moment
                this_thread::sleep_for(chrono::milliseconds(delay));  // Adjust delay for 3 seconds
            }
            cout << "Upper bound index: " << l + 1 << endl;  // The position of the first element strictly greater than key
            break;
        }
        case 3: {
            // Lower Bound Search
            while (l < r) {
                int mid = (l + r) / 2;

                clearScreen();  // Clear the screen before showing the next step
                printSearchRange(v, l, r);  // Show the current range and elements
                cout << "Midpoint: v[" << mid << "] = " << v[mid] << "\n";
                cout << "Checking elements in range: ";
                for (int i = l; i < r; i++) {
                    cout << v[i] << " ";
                }
                cout << "\n";

                if (isOkLowerBound(v, key, mid) == 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }

                // Display process step and wait for a moment
                this_thread::sleep_for(chrono::milliseconds(delay));  // Adjust delay for 3 seconds
            }
            cout << "Lower bound index: " << l << endl;  // The position of the first element greater than or equal to key
            break;
        }
        default:
            cout << "Invalid option. Please select 1 for Standard, 2 for Upper Bound, or 3 for Lower Bound." << endl;
            break;
    }
}
