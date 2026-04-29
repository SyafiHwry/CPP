#include <iostream>
using namespace std;

class Book{
    public:
        void printArray(int arr[], int n) {
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";  // Cetak setiap elemen array
            }
            cout << endl;
        }

        void bubbleSort(int arr[], int n) {
            for (int i = 0; i < n-1; i++) {          // Loop untuk setiap elemen
                cout << "Langkah " << i+1 << ":" << endl;
                for (int j = 0; j < n-i-1; j++) {    // Loop untuk membandingkan elemen
                    if (arr[j] > arr[j+1]) {         // Jika elemen saat ini lebih besar dari elemen berikutnya
                        cout << "   Tukar " << arr[j] << " dan " << arr[j+1] << ": ";
                        swap(arr[j], arr[j+1]);      // Tukar elemen menggunakan swap bawaan
                        printArray(arr, n);         // Tampilkan array setelah penukaran
                    }
                }
            }
        }

       int binarySearch(int arr[], int l, int r, int x, int jumlahInput) {
            while(l <= r) { // 0<=5
                int mid = l + (r - l) / 2; // mid = 0 + (5-0) / 2 = 2
                if(arr[mid] == x) { // jika: 150 == 100
                    // for(int i = 0; i < jumlahInput; i++) {
                        cout << "Element found at data " << mid+1 << endl;
                        return mid;
                    // }
                }
                else if(arr[mid] < x) { // jika: 150 < 100
                    cout << "Checking right half of the array." << endl;
                    l = mid + 1; // l = 2 + 1 | potong index
                }
                else {
                    cout << "Checking left half of the array." << endl;
                    r = mid - 1; // r = 2 - 1 | potong index
                }
            }
            return -1; 
        } 
};

int main() {
    int x, jumlahInput;
    Book obj;
    
    cout << "\n===> SORTING BUBBLE & BINARY SEARCH <===\n" <<endl;
    
    cout << "berapa jumlah array yang anda input: ";
    cin >> jumlahInput;
    int arr[jumlahInput];  
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0; i < jumlahInput; i++) {
        cout << "index ke-" << i << " : ";
        cin >> arr[i];
    }

    cout << "Array sebelum diurutkan: ";
    obj.printArray(arr, n);  // Tampilkan array sebelum diurutkan

    cout << "\nProses Bubble Sort ASC:\n";
    obj.bubbleSort(arr, n);  // Panggil fungsi Bubble Sort

    cout << "\nArray setelah diurutkan: ";
    obj.printArray(arr, n);  // Tampilkan array setelah diurutkan

    cout << "jumlah dari halaman yang ingin anda cari: ";
    cin >> x;

    int result = obj.binarySearch(arr, 0, n - 1, x, jumlahInput); //0 -> untuk mengambil index-0 | n - 1 untuk mengambil index-9
    if(result == -1) {
        cout << "Element not found in the array" << endl;
    }

    // int jumlahInput;
    // cout << "Jumlah buku apa yang ingin anda cari: ";
    // cin >> jumlahInput;

    return 0;
} 