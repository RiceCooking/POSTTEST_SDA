#include <iostream>
using namespace std;


void ubah(int *p1, int *p2){
    int wadah = *p1;
    *p1 = *p2;
    *p2 = wadah;
}

int main(){
    int ang1, ang2;
    cout << "Masukkan nilai pertama\t: ";cin >> ang1;
    cout << "Massukkan nilai kedua\t: ";cin >> ang2;

    cout << endl << endl << "Nilai sebelum ditukar" << endl << "Nilai pertama\t\t: " << ang1 << endl << "Nilai kedua\t\t: " << ang2 << endl << endl << endl;

    ubah(&ang1, &ang2);
    cout << "Nilai sesudah ditukar" << endl << "Nilai pertama\t\t: " << ang1 << endl << "Nilai kedua\t\t: " << ang2 << endl;   
    return 0;
}