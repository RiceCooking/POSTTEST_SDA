#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Perpustakaan
struct BukuNode {
    string judulBuku;
    BukuNode* next;

    // Constructor
    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

/**
 * @brief Fungsi untuk mencari buku berdasarkan judulnya dalam Circular Linked List.
 * @param head Pointer ke node pertama (head).
 * @param judulDicari String judul buku yang ingin dicari.
 * @return boolean true jika buku ditemukan, false jika tidak ditemukan.
 * @logic
 * 1. Jika list kosong (head == nullptr), kembalikan false.
 * 2. Mulai penelusuran dari head menggunakan pointer temp.
 * 3. Selama penelusuran, cek apakah temp->judulBuku sama dengan judulDicari.
 * Jika ya, langsung kembalikan true.
 * 4. Lanjutkan ke node berikutnya. Berhenti jika temp kembali mencapai head.
 * 5. Jika seluruh list sudah ditelusuri dan tidak ditemukan, kembalikan false.
 */
bool cariBuku(BukuNode* head, string judulDicari) {
    // --- LENGKAPI KODE DI SINI ---
    if (head == nullptr)//1. jika listnya kosong
    {
        return false;
    }
    BukuNode* temp = head; //2. mulai carinya dari head

    do 
    {
        if (temp->judulBuku == judulDicari)//3. cek apakah judul buku sekarang sama dengan judul yg di cari
        {
            return true;
        }
        temp = temp->next;//4.1 lanjut ke node berikutnya
    }while (temp != head);//4.2 berhenti saat kembali ke head

    return false;//5. jika tidak ketemu kembalikan nilai false
    // -----------------------------
}

int main() {
    BukuNode* head = nullptr;
    
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': " 
         << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl; 
         // Harusnya output: Ditemukan

    cout << "Mencari buku '" << buku2 << "': " 
         << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl; 
         // Harusnya output: Tidak Ditemukan

    return 0;
}