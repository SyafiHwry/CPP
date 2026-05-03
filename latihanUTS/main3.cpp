#include <iostream>
using namespace std;

class Buku {
private:
    string kode, judul;
    int halaman;

public:
    void input() {
        cout << "Kode   : ";
        cin >> kode;
        cout << "Judul  : ";
        cin.ignore();
        getline(cin, judul);
        cout << "Halaman: ";
        cin >> halaman;
    }

    int getHalaman() {
        return halaman;
    }
};

// ================= BUBBLE SORT =================
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ================= MERGE SORT =================
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ================= BINARY SEARCH =================
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// ================= MAIN =================
int main() {
    int n;
    cout << "Masukkan jumlah buku: ";
    cin >> n;

    Buku b[n];
    int halamanArr[n];

    // INPUT DATA
    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        b[i].input();
        halamanArr[i] = b[i].getHalaman();
    }

    // TAMPIL SEBELUM SORT
    cout << "\nData sebelum sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << halamanArr[i] << " ";
    }
    cout << endl;

    // ================= PILIH SORT =================
    int pilihan;
    cout << "\nPilih metode sorting:\n";
    cout << "1. Bubble Sort (NIM Ganjil)\n";
    cout << "2. Merge Sort (NIM Genap)\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        bubbleSort(halamanArr, n);
    } else {
        mergeSort(halamanArr, 0, n - 1);
    }

    // TAMPIL SETELAH SORT
    cout << "\nData setelah sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << halamanArr[i] << " ";
    }
    cout << endl;

    // ================= BINARY SEARCH =================
    int target = 100;
    int index = binarySearch(halamanArr, n, target);

    if (index == -1) {
        cout << "\nData 100 tidak ditemukan\n";
    } else {
        // HITUNG JUMLAH DUPLIKAT
        int count = 1;

        // cek kiri
        int i = index - 1;
        while (i >= 0 && halamanArr[i] == target) {
            count++;
            i--;
        }

        // cek kanan
        i = index + 1;
        while (i < n && halamanArr[i] == target) {
            count++;
            i++;
        }

        cout << "\nData 100 ditemukan pada index: " << index << endl;
        cout << "Jumlah buku dengan 100 halaman: " << count << endl;
    }

    return 0;
}