#include <iostream>
#include <utility>
using namespace std;

class Parkir{
    public: 
        void printArr(int arr[], int jumlah) {
            for(int i = 0; i < jumlah; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void bubbleSort(int arr[], int jumlah) {
            for (int i = 0; i < jumlah-1; i++) {       
                cout << "Langkah " << i+1 << ":" << endl;
                for (int j = 0; j < jumlah-i-1; j++) {   
                    if (arr[j] > arr[j+1]) {        
                        cout << "   Tukar " << arr[j] << " dan " << arr[j+1] << ": ";
                        swap(arr[j], arr[j+1]);      
                        printArr(arr, jumlah);      
                    }
                }
            }
        }

        void selectionSort(int arr[], int jumlah) {
            for (int i = 0; i < jumlah-1; i++) {   
                int minIndex = i;            
                for (int j = i+1; j < jumlah; j++) {   
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j; 
                    }
                }
                if (minIndex != i) {
                    cout << "   Tukar " << arr[i] << " dan " << arr[minIndex] << ": ";
                    swap(arr[i], arr[minIndex]); 
                    printArr(arr, jumlah); 
                }
            }
        }

        int binarySearch(int arr[], int l, int r, int x) {
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(arr[mid] == x) {
                    cout << "Element found at index " << mid << endl;
                    return mid;
                }
                else if(arr[mid] < x) {
                    cout << "Checking right half of the array." << endl;
                    l = mid + 1;
                }
                else {
                    cout << "Checking left half of the array." << endl;
                    r = mid - 1;
                }
            }
            return -1;
        }

        float avg(int arr[], int jumlah) {
            for(int i = 0; i < jumlah; i++) {
                arr[i]=+ arr[i+1];
                cout << arr[i];
            }
            // float hasil = avg(arr, jumlah)/jumlah;
            // cout << hasil;
            // return hasil;
        }
};

int main() {
    cout << "\n===> UTS <===\n" <<endl;

    int jumlah, target, pil;
    Parkir obj;
    
    cout << "berapa jumlah index: ";
    cin >> jumlah;

    int arr[jumlah] = {};
    jumlah = sizeof(arr) / sizeof(arr[0]);
    
    for(int i = 0; i < jumlah; i++) {
        cout << "Masukkan index ke- " << i+1 << " : ";
        cin >> arr[i];
    }

    cout << "Sorting yang akan anda lakukan: \n1. Selection Sort\n2. Bubble Sort" <<endl;
    cout << "Ur Choice: ";
    cin >> pil;
    if(pil == 1) {
        cout << "Array sebelum diurutkan: ";
        obj.printArr(arr, jumlah);  

        cout << "\nProses Selection Sort ASC:\n";
        obj.selectionSort(arr, jumlah);

        cout << "\nArray setelah diurutkan: ";
        obj.printArr(arr, jumlah); 
    } else if(pil == 2) {
        cout << "Array sebelum diurutkan: ";
        obj.printArr(arr, jumlah); 

        cout << "\nProses Bubble Sort ASC:\n";
        obj.bubbleSort(arr, jumlah);

        cout << "\nArray setelah diurutkan: ";
        obj.printArr(arr, jumlah);
    } else{
        cout << "Invalid pada pilihan anda";
    }    

    int x;

    int result = obj.binarySearch(arr, 0, jumlah - 1, x);
    if(result == -1) {
        cout << "Element not found in the array" << endl;
    }
    cout << "Durasi Parkir terpendek: " << arr[0] <<endl;
    cout << "Durasi Parkir Terlama: " << arr[jumlah - 1] <<endl;
    cout << "Rata-rata hasil: ";
    obj.avg(arr, jumlah);
}   