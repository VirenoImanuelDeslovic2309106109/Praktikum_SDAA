#include <iostream>
using namespace std;

void menara_hanoi(int n, int menara_asal_a, int menara_sementara_b, int menara_tujuan_c ){
    if (n==1){
        cout<<"Piringan "<< n <<" dari menara "<<menara_asal_a<<" di pindahkan ke menara "<<menara_tujuan_c<<endl;
    } else{
        menara_hanoi(n-1,menara_asal_a, menara_tujuan_c, menara_sementara_b);
        cout<<"Piringan "<< n <<" dari menara "<<menara_asal_a<<" di pindahkan ke menara "<<menara_tujuan_c<<endl;
        menara_hanoi(n-1, menara_sementara_b, menara_asal_a, menara_tujuan_c);
    }
}

int main()
{
    int jumlah_piringan = 3;
    menara_hanoi(jumlah_piringan, 1,2,3);
    return 0;
}