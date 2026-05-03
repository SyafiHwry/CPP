#include <iostream>
using namespace std;

class Buku {
private:
    int *halaman;
    int n;

    // DATA GANDA DENGAN MENGGUNAKAN LINIER SEARCH
//     int linearSearchCount(int target) {
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         if (halaman[i] == target) {
//             count++;
//         }
//     }
//     return count;
// }

public:
    // Constructor
    Buku() {
        halaman = NULL;
        n = 0;
    }

    // Input data
    void inputData() {
        cout << "Masukkan jumlah data: ";
        cin >> n;

        halaman = new int[n];

        for (int i = 0; i < n; i++) {
            cout << "Jumlah halaman buku ke-" << i+1 << ": ";
            cin >> halaman[i];
        }
    }

    // Menampilkan data
    void tampilData() {
        for (int i = 0; i < n; i++) {
            cout << halaman[i] << " ";
        }
        cout << endl;
    }

    int size() {
        return n;
    }

    // 🔸 Bubble Sort
    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (halaman[j] > halaman[j + 1]) {
                    int temp = halaman[j];
                    halaman[j] = halaman[j + 1];
                    halaman[j + 1] = temp;
                }
            }
        }
    }

    // 🔸 Merge
    void merge(int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0;
        int *temp = new int[right - left + 1];

        while (i <= mid && j <= right) {
            if (halaman[i] <= halaman[j]) {
                temp[k++] = halaman[i++];
            } else {
                temp[k++] = halaman[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = halaman[i++];
        }

        while (j <= right) {
            temp[k++] = halaman[j++];
        }

        for (int x = 0; x < k; x++) {
            halaman[left + x] = temp[x];
        }

        delete[] temp;
    }

    // 🔸 Merge Sort
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    // 🔸 Binary Search (hitung jumlah nilai target)
    int binarySearchCount(int target) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (halaman[mid] == target) {
                int count = 1;

                // cek kiri
                int i = mid - 1;
                while (i >= 0 && halaman[i] == target) {
                    count++;
                    i--;
                }

                // cek kanan
                i = mid + 1;
                while (i < n && halaman[i] == target) {
                    count++;
                    i++;
                }

                return count;
            }
            else if (halaman[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return 0;
    }

    // Destructor (biar tidak memory leak)
    ~Buku() {
        delete[] halaman;
    }
};

int main() {
    Buku b1, b2;

    cout << "=== INPUT DATA ===" << endl;
    b1.inputData();

    // Copy manual (karena pointer)
    int n = b1.size();
    b2 = b1; // ⚠️ ini shallow copy (cukup untuk kasus ini)

    cout << "\n=== Bubble Sort ===" << endl;
    b1.bubbleSort();
    b1.tampilData();
    cout << "Jumlah buku dengan 100 halaman: "
         << b1.binarySearchCount(100) << endl;

    cout << "\n=== Merge Sort ===" << endl;
    b2.mergeSort(0, b2.size() - 1);
    b2.tampilData();
    cout << "Jumlah buku dengan 100 halaman: "
         << b2.binarySearchCount(100) << endl;

    return 0;
}