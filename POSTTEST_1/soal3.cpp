#include <iostream>
using namespace std;

void balik(int* arr, int n){
    int *awal = arr;
    int *akhir = arr + (n - 1);

    while(awal < akhir){
        int wadah = *awal;
        *awal = *akhir;
        *akhir = wadah;
        awal++;
        akhir--;
    }
}
int main(){
    int total = 7;
    int angka[total] = {2, 3, 5, 7, 11, 13, 17};
    int angka1, angka2;
    int *p1 = angka;
    cout << "Array sebelum dibalik" << endl;
    cout << "Data\t\t: {2, 3, 5, 7, 11, 13, 17}" << endl;

    for(int i = 0; i < total; i++){
        cout << "Nilai\t\t: " << *p1 << "\tAlamat\t\t: " << p1 << endl;
        p1++;
    }
    cout << endl << endl;

    balik(angka, total);
    int *p2 = angka;
    cout << "Array sesudah dibalik" << endl;
    cout << "Data\t\t: {17, 13, 11, 7, 5, 3, 2}" << endl;

    for(int i = 0; i < total; i++){
        cout << "Nilai\t\t: " << *p2 << "\tAlamat\t\t: " << p2 << endl;
        p2++;
    }
    
    return 0;
}