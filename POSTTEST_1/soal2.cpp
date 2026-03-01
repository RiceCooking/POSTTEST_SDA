#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string NIM;
    float IPK;
};

int main(){
    int total  = 5;
    Mahasiswa skom[total];
    for(int i = 0; i < total; i++){
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama\t\t: ";getline(cin, skom[i].nama);
        cout << "NIM\t\t: ";getline(cin, skom[i].NIM);
        cout << "IPK\t\t: ";cin >> skom[i].IPK;
        cout << endl;
        cin.ignore();
    }

    int index = 0;
    for(int i = 0; i < total; i++){
        if(skom[i].IPK > skom[index].IPK){
            index = i;
        }
    }

    cout << endl << endl << "Mahasiswa dengan IPK tertinggi" << endl;
    cout << "Nama\t\t: " << skom[index].nama << endl;
    cout << "NIM\t\t: " << skom[index].NIM << endl;
    cout << "IPK\t\t: " << skom[index].IPK << endl;
    return 0;
}