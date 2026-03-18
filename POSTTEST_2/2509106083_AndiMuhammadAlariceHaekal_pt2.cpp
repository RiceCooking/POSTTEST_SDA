#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> 
using namespace std;

struct Pet{
    int id;
    string nama;
    string spesies;
    double harga;
};
const int batas = 100;

void swapPet(Pet* a, Pet* b){
    Pet temp = *a;
    *a = *b;
    *b = temp;
}

void tampilkanhewan(Pet* arr, int n){
    if (n == 0) {
        cout << "Info\t: Data hewan kosong" << endl;
        return;
    }
    cout << "=================================================================" << endl;
    cout << "| ID  | Nama Hewan           | Spesies      | Harga             |" << endl;
    cout << "=================================================================" << endl;
    for(int i = 0; i < n; i++){
        cout << "| " << setw(3) << (arr + i)->id
             << "| " << setw(20) << left << (arr + i)->nama
             << "| " << setw(12) << left << (arr + i)->spesies
             << "| Rp." << setw(14) << right << fixed << setprecision(0) << (arr + i)->harga << " |" << endl;
    }
    cout << "=================================================================" << endl;
}

void addPet(Pet* arr, int* n){
    if(*n >= batas){
        cout << "Info\t: Kapasitas data penuh" << endl;
        return;
    }
    cout << "=== Tambah Data Hewan ===" << endl;
    cout << "ID Hewan\t: ";
    cin >> (arr + *n)->id;

    while(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Info\t: Input tidak valid! Masukkan angka." << endl;
        cout << "ID Hewan\t: ";
        cin >> (arr + *n)->id;
    }
    cin.ignore(); 
    
    cout << "Nama Hewan\t: ";
    getline(cin, (arr + *n)->nama);
    cout << "Spesies\t\t: ";
    getline(cin, (arr + *n)->spesies);
    cout << "Harga(Rp)\t: ";
    cin >> (arr + *n)->harga;
    
    while(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Info\t: Input tidak valid! Masukkan angka." << endl;
        cout << "Harga(Rp)\t: ";
        cin >> (arr + *n)->harga;
    }
    
    (*n)++;
    cout << "Info\t: Data berhasil ditambahkan" << endl;
}

void linearsearch(Pet* arr, int n, string target){
    bool valid = false;
    cout << "=== Hasil Pencarian  ==="<< endl;
    for(int i = 0; i < n; i++){
        if ((arr + i)->nama == target) {
            cout << "-> Ditemukan pada indeks " << i << ":" << endl;
            cout << "   ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama 
                 << " | Harga: Rp." << fixed << setprecision(0) << (arr + i)->harga << endl;
            valid = true;
        }
    }
    if(!valid){
        cout << "Info\t: Hewan dengan nama '" << target << "' tidak ditemukan" << endl;
    }
}

void sortID(Pet* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if((arr + j)->id > (arr + j + 1)->id){
                swapPet((arr + j), (arr + j + 1));
            }
        }
    }
}

void fibonaccisearchID(Pet* arr, int n, int x) {
    sortID(arr, n);
    cout << "Info\t: Data diurutkan sementara berdasarkan ID untuk Fibonacci Search" << endl;

    int fibMMm2 = 0; 
    int fibMMm1 = 1; 
    int fibM = fibMMm2 + fibMMm1; 

    while(fibM < n){
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    bool valid = false;
    int iterasi = 1;

    cout << "=== Proses Iterasi ===" << endl;
    while(fibM > 1){
        int i = min(offset + fibMMm2, n - 1);
        cout << "Iterasi " << iterasi++ << " | Mengecek indeks ke-" << i  << " (ID indeks ini: " << (arr + i)->id << ")" << endl;

        if((arr + i)->id < x){
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
            cout << "   -> ID di array (" << (arr + i)->id << ") < Target (" << x << ") geser rentang pencarian ke kanan" << endl;
        } 
        else if((arr + i)->id > x){
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            cout << "   -> ID di array (" << (arr + i)->id << ") > Target (" << x << ") geser rentang pencarian ke kiri" << endl;
        } 
        else{
            cout << "   -> ID ditemukan pada iterasi ini" << endl;
            cout << "=== DATA DITEMUKAN ===" << endl;
            cout << "ID\t: " << (arr + i)->id << '\n' <<"Nama\t: " << (arr + i)->nama << endl;
            cout << "Spesies\t: " << (arr + i)->spesies << endl << "Harga\t: Rp." << fixed << setprecision(0) << (arr + i)->harga << '\n';
            valid = true;
            break;
        }
    }
    if(!valid && fibMMm1 && (arr + offset + 1)->id == x){
        cout << "Iterasi " << iterasi << " | Mengecek indeks sisa ke-" << offset + 1 << endl;
        cout << "   -> MATCH! ID ditemukan pada indeks sisa" << endl;
        cout << "=== DATA DITEMUKAN ==="<< endl;
        cout << "ID\t: " << (arr + offset + 1)->id << "\nNama\t: " << (arr + offset + 1)->nama << endl;
        cout << "Spesies\t: " << (arr + offset + 1)->spesies << endl << "Harga\t: Rp." << fixed << setprecision(0) << (arr + offset + 1)->harga << '\n';
        valid = true;
    }
    if(!valid){
        cout << "Info\t: Hewan dengan ID " << x << " tidak ditemukan dalam sistem" << endl;
    }
}

void bubblesort(Pet* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if ((arr + j)->nama > (arr + j + 1)->nama){
                swapPet((arr + j), (arr + j + 1));
            }
        }
    }
    cout << "Info\t: Data berhasil diurutkan berdasarkan Nama (A-Z)" << '\n';
}

void selectionsortharga(Pet* arr, int n){
    for(int i = 0; i < n - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if((arr + j)->harga < (arr + min_idx)->harga){
                min_idx = j;
            }
        }
        if(min_idx != i){
            swapPet((arr + i), (arr + min_idx));
        }
    }
    cout << "Info\t: Data berhasil diurutkan berdasarkan Harga (Termurah ke Termahal)" << endl;
}

int main(){
    Pet pets[batas];
    int jumlah = 0;
    int opsi;

    do{
        cout << endl <<"============================================" << '\n';
        cout << "       PAWCARE PETSHOP & KLINIK HEWAN" << endl;
        cout << "============================================" << endl;
        cout << "1. Tampil Semua Data Hewan" << endl;
        cout << "2. Tambah Data Hewan Baru" << endl;
        cout << "3. Cari Hewan berdasarkan Nama" << endl;
        cout << "4. Cari Hewan berdasarkan ID" << endl;
        cout << "5. Urutkan berdasarkan Nama A-Z" << endl;
        cout << "6. Urutkan Harga Termurah ke Termahal" << endl;
        cout << "7. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Pilih menu\t: ";
        cin >> opsi;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << endl;

        switch(opsi){
            case 1:
                tampilkanhewan(pets, jumlah);
                break;
            case 2:
                addPet(pets, &jumlah);
                break;
            case 3:{
                if(jumlah == 0){
                    cout << "Info\t: Data kosong" << endl;
                }
                else{
                    string nama;
                    cout << "Masukkan nama hewan: ";
                    cin.ignore();
                    getline(cin, nama);
                    linearsearch(pets, jumlah, nama);
                }
                break;
            }
            case 4:{
                if(jumlah == 0){
                    cout << "Info\t: Data kosong" << endl;
                }
                else{
                    int id;
                    cout << "Masukkan ID hewan: ";
                    cin >> id;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Info\t: Input tidak valid" << endl;
                        break; 
                    }
                    fibonaccisearchID(pets, jumlah, id);
                }
                break;
            }
            case 5:
                if(jumlah == 0){
                    cout << "Info\t: Data kosong" << endl;
                }
                else{
                    bubblesort(pets, jumlah);
                    tampilkanhewan(pets, jumlah);
                }
                break;
            case 6:
                if(jumlah == 0){
                    cout << "Info\t: Data kosong" << endl;
                }
                else{
                    selectionsortharga(pets, jumlah);
                    tampilkanhewan(pets, jumlah);
                }
                break;
            case 7:
                cout << "Info\t: Keluar dari program, terima kasih" << endl;
                break;
            default:
                cout << "Info\t: Pilihan tidak valid (1-7)" << endl;
        }
    }while(opsi != 7);
    
    return 0;
}