#include <iostream>
#include <utility>
using namespace std;

int nimSearch(int nim[], int nimLength, int dataNim) {
    cout << "Cheking NIM: " <<endl;
   for(int i = 0; i < nimLength; i++) {
      if(nim[i] == dataNim) {
        cout << "=======================================================================" <<endl;
        cout << "NIM " << nim[i] << " found at index " << i << endl;
        cout << "=======================================================================" <<endl;
         return i;
      }
      cout << "Checking NIM " << nim[i] << " at index " << i << endl;
   }
   cout << "=======================================================================" <<endl;
   return -1;
}

int nameSearch(string name[], int nameLength, string dataName) {
    cout << "Checking Name: " <<endl;
   for(int i = 0; i < nameLength; i++) {
      if(name[i] == dataName) {
        cout << "=======================================================================" <<endl;
        cout << "Name "<< name[i] << " found at index " << i << endl;
        cout << "=======================================================================" <<endl;
         return i;
      }
      cout << "Checking " << name[i] << " at index " << i << endl;  
   }
   cout << "=======================================================================" <<endl;
   return -1;
}

int main() {
    int nim[] = {16501,16503,16505, 16502,16504,16506}, dataNim;
    string name[] = {"Riski", "Aziz", "Surya", "Andhika", "Farid", "Iqbal"}, dataName;
    int nimLength = sizeof(nim)/sizeof(*nim);
    int nameLength = sizeof(name)/sizeof(*name);
    for(int i = 0; i < nimLength;i++) {
        cout << nim[i] <<" ";
    }
    cout <<endl;
    cout << "NIM: ";
    cin >> dataNim;
    cout << "----------------------------------------------------------------" <<endl;
    
    for(int i = 0; i < nameLength;i++) {
        cout << name[i] <<" ";
    }
    cout <<endl;
    cout << "Nama: ";
    cin >> dataName;
    cout << "----------------------------------------------------------------" <<endl;

    int resultNim = nimSearch(nim, nimLength, dataNim);
    if(resultNim == -1) {
        cout << "NIM not found in the array" << endl;
        cout << "=======================================================================" <<endl;

    }
    int resultName = nameSearch(name, nameLength, dataName);
    if(resultName == -1) {
        cout << "Name not found in the array" << endl;
        cout << "=======================================================================" <<endl;
    }
   return 0;
}