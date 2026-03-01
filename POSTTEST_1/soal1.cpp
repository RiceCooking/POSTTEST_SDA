#include <iostream>
using namespace std;

int main(){
    int IMO[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int nilaimin = IMO[0];
    int indexmin = 0;

    for(int i = 1;i < n;i++){
        if(IMO[i] < nilaimin){
            nilaimin = IMO[i];
            indexmin = i;
        }
    }
    cout << "Data\t\t\t: {1, 1, 2, 3, 5, 8, 13, 21}" << '\n';
    cout << "Nilai Minimum\t\t: " << nilaimin << endl;
    cout << "Index\t\t\t: " << indexmin;
    return 0;
}