#include <iostream>
using namespace std;

class Data{
    private: 
        int Pertambahan(int angkaSatu, int angkaDua) {
            return angkaSatu + angkaDua;
        }
        string tryPrivate() {
            return "Ini Private";
        }
    public:
        void kalkulasi(int angkaSatu, int angkaDua) {
            cout << "Masukkan angka Satu: ";
            cin >> angkaSatu;
            cout << "Masukkan angka Dua: ";
            cin >> angkaDua;
            cout << "Hasil: " << Pertambahan(angkaSatu, angkaDua);
        }
        void outputPrivate() {
            tryPrivate(); 
        }
};

int main() {
    cout << "\nFunction Pertambahan\n" <<endl;

    Data object;
    int angkaSatu, angkaDua;
    object.kalkulasi(angkaSatu, angkaDua);
}