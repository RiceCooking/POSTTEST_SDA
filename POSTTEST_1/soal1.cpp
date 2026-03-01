#include <iostream>
using namespace std;

/*
|Baris                                     | Cost |  Tmin  |  Tmax  |
procedure FindMin(A : array of n elements)    c1     1         1
  min ← A[0]                                  c2     1         1
  for i ← 1 to n - 1 do                       c3     n         n
    if A[i] < min then                        c4     n-1       n-1
      min ← A[i]                              c5     0         n-1
    end if                                    c6     n-1       n-1
  end for                                     c7     n         n
  return min                                  c8     1         1
end procedure                                 c9     1         1

c1 akan dieksekusi 1 kali 
c2 akan dieksekusi 1 kali
c3 akan dieksekusi sebanyak jumlah data yaitu n, dalam kasus ini n = 8
c4 akan dieksekusi sebanyak n-1, dalam kasus ini n-1 = 8-1 = 7
c5 jika best case maka tidak dieksekusi karena nilai yang di cari sudah ditemukan dari awal
c5 jika worst case maka akan dieksekusi sebanyak n-1 atau dalam kasus ini 7 kali
c6 akan dieksekusi sebanyak n-1 atau dalam kasus ini 7 kali
c7 akan dieksekusi sebanyak n atau dalam kasus ini 8 kali
c8 akan dieksekusi sebanyak 1 kali
c9 akan dieksekusi sebanyak 1 kali

ANALISIS
1. Best case (Tmin)
Best case dalam kasus ini terjadi ketika kita mencari nilai terkecil dari suatu data dan data tersebut terurut secara acsceding
Hitung Tmin (Best case)
Tmin = (c1 x 1) + (c2 x 1) + (c3 x n) + (c4 x (n-1)) + (c5 x 0) + (c6 x (n-1)) + (c7 x n) + (c8 x 1) + (c9 x 1)
Tmin = c1 + c2 + c3n + c4n - c4 + 0 + c6n - c6 + c7n + c8 + c9
Tmin = (c3 + c4 + c6 + c7)n + (c1 + c2 - c4 - c6 + c8 + c9) : misalkan setiap c = 1
Tmin = (1 + 1 + 1 + 1)n + (1 + 1 - 1 - 1 + 1 + 1)
Tmin = 4n + 2
Tmin = 4(8) + 2 = 32 + 2 = 34 operasi
Karena membentuk fungsi linear maka Big-O dari best case -> O(n)

2. Worst case (Tmax)
Worst case dalam kasus ini hanya terjadi jika datanya terurut secara descending, karena komputer akan mengecek satu per satu nilai elemen tiap index
sampai akhir index elemen data
Hitung Tmax (Worst Case)
Tmax = (c1 x 1) + (c2 x 1) + (c3 x n) + (c4 x (n-1)) + (c5 x (n-1)) + (c6 x (n-1)) + (c7 x n) + (c8 x 1) + (c9 x 1)
Tmax = c1 + c2 + c3n + c4n - c4 + c5n - c5 + c6n - c6 + c7n + c8 + c9
Tmax = (c3 + c4 + c5 + c6 + c7)n + (c1 + c2 - c4 - c5 - c6 + c8 + c9) : misalkan setiap c = 1
Tmax = (1 + 1 + 1 + 1 + 1)n + (1 + 1 - 1 - 1 - 1 + 1 + 1)
Tmax = 5n + 1
Tmax = 5(8) + 1 = 40 + 1 =  41 operasi
Karena membentuk fungsi linear maka Big-O dari worst case -> O(n)
*/
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