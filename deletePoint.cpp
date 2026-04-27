#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteAfter(Node* head, int value) {
    Node* prev = head;
    cout << prev<< " ";
    while (prev != nullptr && prev->data != value) { //output data
        prev = prev->next; //pindah node
        cout << prev<< " ";
    }

    // if(value == 100) {
    //     Node* target = prev->next; // target = head->next           
    //     prev->next = target->next; //menghubungkan alamat                
    //     delete target;
    // }

    while (prev != nullptr) { //looping data
        if(prev->data == value) {
            Node* target = prev->next; // target = head->next
            cout << target << " ";
            prev->next = target->next; //menghubungkan alamat                
            delete target;     
            break;
        }
        else {
            cout << "Element with value " << value << " not found or does not have a node after it." << endl;
        }
    }

    // if (prev != nullptr && prev->next != nullptr) { 
    //     Node* target = prev->next; // target = head->next           
    //     cout << target << " ";
    //     prev->next = target->next; //menghubungkan alamat                
    //     delete target;                            
    // } 
}

void printList(Node* head) {
    cout << "Linked list: ";
    Node* prev = head;
    while (prev != nullptr) {
            cout << prev->data << " "; 
            prev = prev->next; 
    }
    cout << endl;
}

int main() {
    Node* head = new Node; // Membuat node pertama
    head->data = 100; // Mengisi data node pertama
    head->next = new Node; // Membuat node kedua
    head->next->data = 84; // Mengisi data node kedua
    head->next->next = new Node; // Membuat node ketiga
    head->next->next->data = 70; // Mengisi data node ketiga
    head->next->next->next = nullptr; // Menandai akhir linked list dengan nullptr
    
    // Mencetak linked list sebelum penghapusan
    cout << "Linked list sebelum penghapusan: ";
    printList(head);
    
    // Menghapus elemen setelah 100
    deleteAfter(head, 100);
    
    // Mencetak linked list setelah penghapusan
    cout << "Linked list setelah penghapusan: ";
    printList(head);

    return 0;
}