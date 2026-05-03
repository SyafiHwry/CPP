#include <iostream>
using namespace std;

class Book{
    private:
        string kode, judul;
        int halaman, jumlah;
        int arr[];
    public:
        void printData() {
            for(int i = 0; i < jumlah; i++) {
                cout << kode << " ";
                cout << judul << " ";
                cout << halaman << " ";
            }
            cout << endl;
        }

        void printSort() {
            for(int i = 0; i < jumlah; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void printArr() {
            for(int i = 0; i < jumlah; i++) {
                cout << arr[i] << " ";
            }
            cout <<endl;
        }

        void inputData() {
            for(int i = 0; i < jumlah; i++) {
                cout << "data ke- " << i <<endl; 
                cout << "Masukkan Kode Buku: ";
                getline(cin >> ws, kode);
                cout << "Masukkan Judul Buku: ";
                getline(cin >> ws, judul);
                cout << "Masukkan Jumlah halaman: ";
                cin >> halaman;
            }
        }

        void sorting() {
            for (int i = 0; i < jumlah-1; i++) {          // Loop untuk setiap elemen
            cout << "Langkah " << i+1 << ":" << endl;
                for (int j = 0; j < jumlah-i-1; j++) {    // Loop untuk membandingkan elemen
                    if (arr[j] > arr[j+1]) {         // Jika elemen saat ini lebih besar dari elemen berikutnya
                        cout << "   Tukar " << arr[j] << " dan " << arr[j+1] << ": ";
                        swap(arr[j], arr[j+1]);      // Tukar elemen menggunakan swap bawaan
                        printData();         // Tampilkan array setelah penukaran
                    }
                }
            }
        }
};

int main() {
    // data awal penjualan
    int jumlah;
    Book obj;
    
    cout << "Masukkan Jumlah buku: ";
    cin >> jumlah;
    
    int arr[jumlah];
    jumlah = sizeof(arr) / sizeof(arr[0]);  

    obj.printArr();
    
    cout << "Data sebelum di urutkan: ";
    obj.inputData();
    
}