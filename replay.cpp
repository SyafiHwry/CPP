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

void asking(int find) {
    cout << "berapa angka yang anda cari: ";
    cin >> find;
}

void printArr(int arr[], int length) {
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
                cout << "Element Found at index-" << mid <<endl;
                return mid;
            }
            else if(arr[mid] < find) {
                cout << "Checking right half element" <<endl;
                left = mid + 1;
            }
            else {
                cout << "Checking left half element" <<endl;
                right = mid - 1;
            }
        }
        return -1;
    }
};

class BogoSort{
    public:
        bool isSorted(int arr[], int length) {
            for(int i = length - 1; i > 0; i--) {
                if(arr[i] > arr[i + 1]) {
                    return false;
                }
            }
            return true;
        }
        void shuffle(int arr[], int length) {
            for(int i = 0; i < length; i++) {
                int randomIndex = rand() % length;
                swap(arr[i], arr[randomIndex]);
            }
        }
        void bogoSort(int arr[], int length) {
            srand(time(NULL));
            int tries = 0;
            while (!isSorted(arr, length)) {
                shuffle(arr, length);
                tries++;
                cout << "Try " << tries << ": ";
                for (int i = 0; i < length; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

class BubbleSort{
    public:
        void bubbleSort(int arr[], int length) {
            for(int i = 0; i < length - 1; i++) {
                cout << "Langkah ke- " << i+1 << ": " <<endl;
                for(int j = 0; j < length - i - 1; j++) {
                    if(arr[j] > arr[j+1]) {
                        cout << "Tukar " << arr[j] << " Dengan " << arr[j+1] << " : ";
                        swap(arr[j], arr[j+1]);
                        printArr(arr, length);
                    }
                }
            }
            cout << "\nArray setelah diurutkan: ";
            printArr(arr, length);
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
    BogoSort bogoSort;
    BubbleSort bubbleSort;

    cout << "Pilih sorting yang akan anda lakukan: " <<endl;
    cout << "1. Linier\n2. Binary" <<endl;
    cout << "Ur Answer: ";
    cin >> answerSearching;
    
    if(answerSearching == 2) {
        for(int i = 0; i < length - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                cout << "Pilih Sorting yang akan anda lakukan: " <<endl;
                cout << "1. Bogo Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Merge Sort\n5. Selection Sort\n6. Swap" <<endl;
                cout << "Ur Answer: ";
                cin >> answerSorting;
                switch (answerSorting) {
                    case 1:
                        cout << "Bogo Sort: " <<endl;
                        bogoSort.bogoSort(arr, length);
                        asking(find);
                        obj.binary(arr, 0, length - 1, find);
                        break;
                    case 2:
                        cout << "Bubble Sort: " <<endl;
                        bubbleSort.bubbleSort(arr, length);
                        asking(find);
                        obj.binary(arr, 0, length - 1, find);
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
            } else{
                asking(find);
                obj.binary(arr, 0, length - 1, find);
            }
        }
    } else if (answerSearching == 1){
        cout << "Berapa angka yang anda cari: ";
        cin >> find;
        obj.linier(arr, length, find);
    }
    return 0;
}