#include <iostream>
using namespace std;

int main() {
    int a[5];

    //Taking input to the array
    cout << "Enter five numbers \n";
    for (int i = 0; i < 5; i++){
        cin >> a[i];
    }

    //Displaying the unsorted array
    cout << "Unsorted array \n";
    for (int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }

    //Swapping
    for (int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if (a[i] > a[j]){
                //Swap a[i] and a[j]
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    //Displaying sorted array
    cout << "\n Array in ascending order \n";
    for (int n = 0; n < 5; n++) {
        cout << a[n] << " ";
    }

}
