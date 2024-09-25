#include <iostream>
#include <limits>
using namespace std;

struct anime{
    string nama_anime;
    int jumlah_episode;
    string tipe_anime;
    string genre_anime;
    string studio_anime;
    string sinopsis_anime;
};

void menambahkan(anime* list_anime, int &jumlah_anime){
    cout<<"\nmasukkan anime baru: ";
    cin.ignore();
    getline(cin, list_anime[jumlah_anime].nama_anime);
    do{
        cout<<"masukkan jumlah episode: ";
        if(cin >> list_anime[jumlah_anime].jumlah_episode){
            break;
        } else{
            cout<<"inputan tidak valid, silahkan masukkan angka"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
    cin.ignore();
    cout<<"TV/ONA/OVA/MOVIE/SPECIAL"<<endl;
    cout<<"Pilih tipe anime: ";
    cin>> list_anime[jumlah_anime].tipe_anime;
    cout<<"Action/Comedy/Romance/Fantasy/Adventure"<<endl;
    cout<<"Pilih genre anime: ";
    cin.ignore();
    getline(cin, list_anime[jumlah_anime].genre_anime);
    cout<<"Toei Animation/MAPPA/SILVER LINK/Kyoto Animation/Aniplex/Ufotable/Madhouse/Bones"<<endl;
    cout<<"Pilih studio anime: ";
    cin.ignore();
    getline(cin, list_anime[jumlah_anime].studio_anime);
    cout<<"Masukkan sinopsis anime: ";
    cin.ignore();
    getline(cin, list_anime[jumlah_anime].sinopsis_anime);
    cout<<"data berhasil ditambahkan\n"<<endl;
    jumlah_anime++;
}

void melihat(anime* list_anime, int &jumlah_anime){
    for(int i = 0; i< jumlah_anime; ++i){
        cout<<"\n"<<endl;
        cout<<i + 1<<". nama anime: "<<list_anime[i].nama_anime<<endl;
        cout<<"Jumlah Episode: "<<list_anime[i].jumlah_episode<<endl;
        cout<<"Tipe anime: "<<list_anime[i].tipe_anime<<endl;
        cout<<"Genre anime: "<<list_anime[i].genre_anime<<endl;
        cout<<"Studio anime: "<<list_anime[i].studio_anime<<endl;
        cout<<"sinopsis anime: "<<list_anime[i].sinopsis_anime<<endl;
    }
    cout<<"\n"<<endl;
}

void merubah(anime* list_anime, int &jumlah_anime){
    int pilih_indeks_data;
    int pilih_yang_ingin_diubah;
    do{
        cout<<"masukkan indek data anime yang ingin diubah: ";
        if (cin >> pilih_indeks_data) {
            if (pilih_indeks_data > 0 && pilih_indeks_data <= jumlah_anime) {
                break;
            } else {
                cout << "Indeks yang anda input tidak ada\n" << endl;
                return;
            }
        } else{
            cout<<"inputan tidak valid, silahkan masukkan angka"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
    do{
    cout<<"\n";
    cout<<"1. Nama anime"<<endl;
    cout<<"2. Jumlah episode"<<endl;
    cout<<"3. Tipe anime"<<endl;
    cout<<"4. Genre anime "<<endl;
    cout<<"5. Studio anime"<<endl;
    cout<<"6. sinopsis anime"<<endl;
    cout<<"7. keluar"<<endl;
    cout<<"Pilih yang ingin diubah: ";
    if (!(cin>>pilih_yang_ingin_diubah)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        switch(pilih_yang_ingin_diubah){
            case 1:{
                cout<<"Masukkan nama anime baru: ";
                cin.ignore();
                getline(cin, list_anime[pilih_indeks_data - 1].nama_anime);
                break;
            }
            case 2:{
                cout<<"Masukkan jumlah episode baru: ";
                while(!(cin>>list_anime[pilih_indeks_data - 1].jumlah_episode)){
                     cout<<"inputan tidak valid, silahkan masukkan angka"<<endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 3:{
                cout<<"TV/ONA/OVA/MOVIE/SPECIAL"<<endl;
                cout<<"Masukkan tipe baru: ";
                cin>>list_anime[pilih_indeks_data - 1].tipe_anime;
                break;
            }
            case 4:{
                cout<<"Action/Comedy/Romance/Fantasy/Adventure"<<endl;
                cout<<"Masukkan genre baru: ";
                cin.ignore();
                getline(cin, list_anime[pilih_indeks_data - 1].genre_anime);
                break;
            }
            case 5:{
                 cout<<"Toei Animation/MAPPA/SILVER LINK/Kyoto Animation/Aniplex/Ufotable/Madhouse/Bones"<<endl;
                cout<<"Masukkan studio baru: ";
                cin.ignore();
                getline(cin, list_anime[pilih_indeks_data - 1].studio_anime);
                break;
            }
            case 6:{
                cout<<"Masukkan sinopsis: ";
                cin.ignore();
                getline(cin, list_anime[pilih_indeks_data - 1].sinopsis_anime);
                break;
            }
            case 7:{
                cout<<"data yang ingin diubah di batalkan"<<endl;
                return;
            }
            default:{
                cout<<"pilihan tidak valid\n"<<endl;
                break;
            }
        }
    } while (pilih_yang_ingin_diubah != 3);
    cout<<"data berhasil diubah\n"<<endl;
}

void menghapus(anime* list_anime, int &jumlah_anime){
    int pilih_data_hapus;
    do{
        cout<<"masukkan indek data anime yang ingin diubah: ";
        if (cin >> pilih_data_hapus) {
            for (int i = pilih_data_hapus - 1; i < jumlah_anime - 1; ++i) {
                        list_anime[i] = list_anime[i + 1];
            }
            jumlah_anime--;
            break;
        } else{
            cout<<"inputan tidak valid, silahkan masukkan angka"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
    cout<<"Data berhasil dihapus\n"<<endl;
}

int main(){
    const int maksimal_anime = 100;
    anime list_anime[maksimal_anime]{
        {"BNHA", 24, "TV", "Action", "Bones", "Kemunculan quirk, kekuatan super yang baru ditemukan, terus meningkat selama bertahun-tahun, dengan 80 persen umat manusia memiliki berbagai kemampuan mulai dari memanipulasi elemen hingga mengubah bentuk. Hal ini membuat seluruh dunia sama sekali tidak berdaya, dan Izuku Midoriya adalah salah satunya. Sejak kecil, siswa sekolah menengah yang ambisius ini tidak menginginkan apa pun selain menjadi pahlawan. Nasib Izuku yang tidak adil membuatnya mengagumi para pahlawan dan mencatatnya kapan pun ia bisa. Namun tampaknya kegigihannya telah membuahkan hasil: Izuku bertemu dengan pahlawan nomor satu dan idola pribadinya, All Might. Quirk All Might adalah kemampuan unik yang dapat diwariskan, dan ia telah memilih Izuku untuk menjadi penerusnya! Setelah menjalani pelatihan yang melelahkan selama berbulan-bulan, Izuku mendaftar di UA High, sekolah menengah bergengsi yang terkenal dengan program pelatihan pahlawannya yang luar biasa, dan para siswa baru tahun ini tampak sangat menjanjikan. Dengan teman-teman sekelasnya yang aneh tetapi berbakat dan ancaman organisasi jahat yang membayangi, Izuku akan segera belajar apa artinya menjadi pahlawan."},
        {"JJK", 24, "TV", "Action", "MAPPA", "Terlibat dalam aktivitas paranormal yang tidak berdasar dengan Klub Ilmu Gaib, siswa SMA Yuuji Itadori menghabiskan hari-harinya di ruang klub atau rumah sakit, tempat ia mengunjungi kakeknya yang terbaring di tempat tidur. Namun, gaya hidup santai ini segera berubah menjadi aneh ketika ia tanpa sadar menemukan benda terkutuk. Memicu serangkaian kejadian supernatural, Yuuji mendapati dirinya tiba-tiba terlempar ke dunia Kutukan—makhluk mengerikan yang terbentuk dari kebencian dan kenegatifan manusia—setelah menelan benda tersebut, yang ternyata adalah jari milik iblis Sukuna Ryoumen, Raja Kutukan. Yuuji mengalami sendiri ancaman Kutukan ini terhadap masyarakat saat ia menemukan kekuatan barunya sendiri. Diperkenalkan ke Sekolah Menengah Jujutsu Prefektur Tokyo, ia mulai berjalan di jalan yang tidak dapat ia lalui kembali—jalan seorang penyihir Jujutsu."},
    };
    int jumlah_anime = 2;
    int pilihan;
    do{
        cout<<"==Menu utama==="<<endl;
        cout<<"1. Menambahkan Anime"<<endl;
        cout<<"2. Melihat Data Anime"<<endl;
        cout<<"3. Mengubah Data Anime"<<endl;
        cout<<"4. Menghapus Data Anime"<<endl;
        cout<<"5. program berhenti"<<endl;
        cout<<"silahkan pilih: ";
        if (!(cin>>pilihan)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (pilihan){
            case 1:{
                if (jumlah_anime < maksimal_anime){  
                menambahkan(&list_anime[0], jumlah_anime);
                } else {
                    cout<<"jumlah anime sudah maksimum"<<endl;
                }
                break;
            }
            case 2:{
                if (jumlah_anime < maksimal_anime){    
                melihat(&list_anime[0], jumlah_anime);
                } else{
                     cout<<"jumlah anime sudah maksimum"<<endl;
                }
                break;
            }
            case 3:{
                if (jumlah_anime < maksimal_anime){    
                merubah(&list_anime[0], jumlah_anime);
                } else{
                     cout<<"jumlah anime sudah maksimum"<<endl;
                }
                break;
            }
            case 4:{
                if (jumlah_anime < maksimal_anime){    
                menghapus(&list_anime[0], jumlah_anime);
                } else{
                     cout<<"jumlah anime sudah maksimum"<<endl;
                }
                break;
            }
            case 5:{
                break;
            }
            default:{
                cout<<"inputan tidak valid\n"<<endl;
            }
        }
    } while(pilihan != 5);
    
    return 0;
}
