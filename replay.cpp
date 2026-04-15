#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputArr(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
}

void outputArr(int arr[], int length) {
    cout << "Data: ";
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

class Searching{
public: 
    int linier(int arr[], int length, int find) {
        for(int i = 0; i < length; i++) {
            if(arr[i] == find) {
                cout << "===================================" <<endl;
                cout << "founded at index-" << i <<endl;
                cout << "===================================" <<endl;
                return i;
            }
            cout << "Search at index- " << i <<endl;
        }
        return -1;
    }

    int binary(int arr[], int left, int right, int find) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == find ) {
                cout << "Element Found at index-" << mid;
                return mid;
            }
            if(arr[mid] < left) {
                cout << "Checking right half element" <<endl;
                left = mid + 1;
            }
            if(arr[mid] > left) {
                cout << "Checking left hald element" <<endl;
                left = mid - 1;
            }
        }
        return -1;
    }
};

class Sorting{
    private:
        void printArr(int arr[], int length) {
            for(int i = 0; i < length; i++) {
                cout << "Hasil Sorting: " << arr[i] << " ";
            }
            cout << endl;
        }
    public: 
        class BogoSort{
            public:
                bool isSorted(int arr[], int length) {
                    for(int i = 0; i < length - 1; i++) {
                        if(arr[i] > arr[i + 1]) {
                            return false;
                        }
                        return true;
                    }
                }
                void shuffle(int arr[], int length) {
                    for(int i = 0; i < length; i++) {
                        int randomIndex = rand() % length;
                        swap(arr[i], arr[randomIndex]);
                    }
                }
        }
};

int main() {
    cout << "\n===> REPLAY SORTING AND SEARCHING <===\n" <<endl;
    
    int answerSorting, answerSearching, length, find;

    cout << "Jumlah data yang diinput: ";
    cin  >> length;
    int arr[length];
    inputArr(arr, length);
    outputArr(arr, length);

    Searching obj;

    cout << "Pilih sorting yang akan anda lakukan: " <<endl;
    cout << "1. Linier\n2. Binary" <<endl;
    cout << "Ur Answer: ";
    cin >> answerSearching;
    
    if(answerSearching == 2) {
        if(arr[0] > arr[1]) {
            cout << "Pilih Sorting yang akan anda lakukan: " <<endl;
            cout << "1. Bogo Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Merge Sort\n5. Selection Sort\n6. Swap" <<endl;
            cout << "Ur Answer: ";
            cin >> answerSorting;
            switch (answerSorting) {
                case 1:
                    cout << "Bogo Sort: " <<endl;
                    break;
                case 2:
                    cout << "Bubble Sort: " <<endl;
                    break;
                case 3:
                    cout << "Insertion Sort: " <<endl;
                    break;
                case 4:
                    cout << "Merge Sort: " <<endl;
                    break;
                case 5:
                    cout << "Selection Sort: " <<endl;
                    break;
                case 6:
                    cout << "Swap: " <<endl;
                    break;
                default:
                    cout << "Invalid Answer!" <<endl;
            }
        }
    } else if (answerSearching == 1){
        cout << "Berapa angka yang anda cari: ";
        cin >> find;
        obj.linier(arr, length, find);
    }

    return 0;
}