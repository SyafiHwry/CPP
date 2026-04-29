#include <iostream>
#include <utility>
using namespace std;

class Book{
    public:
        void printArr(int arr[], int jumlah) {
            for(int i = 0; i < jumlah; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void bubbleSort(int arr[], int jumlah) {
            for (int i = 0; i < jumlah-1; i++) {          // Loop untuk setiap elemen
                cout << "Langkah " << i+1 << ":" << endl;
                for (int j = 0; j < jumlah-i-1; j++) {    // Loop untuk membandingkan elemen
                    if (arr[j] > arr[j+1]) {         // Jika elemen saat ini lebih besar dari elemen berikutnya
                        cout << "   Tukar " << arr[j] << " dan " << arr[j+1] << ": ";
                        swap(arr[j], arr[j+1]);      // Tukar elemen menggunakan swap bawaan
                        printArr(arr, jumlah);         // Tampilkan array setelah penukaran
                    }
                }
            }
        }

        // int binarySearch(int arr[], int l, int r, int x) {
        //     while(l <= r) {
        //         int mid = l + (r - l) / 2;
        //         if(arr[mid] == x) {
        //             cout << "Element found at index " << mid << endl;
        //             return mid;
        //         }
        //         else if(arr[mid] < x) {
        //             cout << "Checking right half of the array." << endl;
        //             l = mid + 1;
        //         }
        //         else {
        //             cout << "Checking left half of the array." << endl;
        //             r = mid - 1;
        //         }
        //     }
        //     return -1;
        // }

        int linearSearch(int arr[], int n, int x) {
            for(int i = 0; i < n; i++) {
                if(arr[i] == x) {
                    cout << "Element found at index " << i << endl;
                    // return i;
                }
                else{
                    cout << "Element not found in the array" << endl;
                }
                cout << "Checking element at index " << i << endl;
            }
            return -1;
        }
};

int main() {
    cout << "\n===> LATIHAN UTS 1 <===\n" <<endl;   
    
    Book obj;
    int jumlah;
    
    cout << "berapa jumlah index: ";
    cin >> jumlah;

    int arr[jumlah];
    jumlah = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = 0; i < jumlah; i++) {
        cout << "Masukkan index ke- " << i+1 << " : ";
        cin >> arr[i];
    }

    cout << "Array sebelum diurutkan: ";
    obj.printArr(arr, jumlah);  // Tampilkan array sebelum diurutkan

    cout << "\nProses Bubble Sort ASC:\n";
    obj.bubbleSort(arr, jumlah);  // Panggil fungsi Bubble Sort

    cout << "\nArray setelah diurutkan: ";
    obj.printArr(arr, jumlah);  // Tampilkan array setelah diurutkan

    int x;
    cout << "Berapa angka yang ingin anda cari: ";
    cin >> x;

    // int result = obj.binarySearch(arr, 0, jumlah - 1, x);
    // if(result == -1) {
    //     cout << "Element not found in the array" << endl;
    // }

    int result = obj.linearSearch(arr, jumlah, x);

    return 0;
}