#include <iostream>
#include "kampus.h"
#include "kampus.cpp"

using namespace std;

int main()
{
    listDosen LD;
    listMatkul LM;
    listRelasi LR;
    matkul Q, C;
    dosen R, Z;
    adrDosen S;
    adrMatkul P;
    int n, m, o, v, O, V;
    int pilihan, w, e;
    string input;
    string gg;
    adrDosen D;
    adrRelasi Re;
    int ii;


// Membuat List Kosong
    createListDosen(LD);
    createListMatkul(LM);
    createListRelasi(LR);

// Menambah data
    R.nama = "Pramudya Widiakso";
    R.kode = "PRM";
    S = newElmDosen(R);
    insertLastDosen(LD, S);


    Q.nama = "AKA";
    Q.sks = 2;
    P = newElmMatkul(Q);
    insertLastMatkul(LM, P);

    R.nama = "Imran Zulkarnaen";
    R.kode = "IRZ";
    S = newElmDosen(R);
    insertLastDosen(LD, S);


    Q.nama = "STD";
    Q.sks = 4;
    P = newElmMatkul(Q);
    insertLastMatkul(LM, P);

// Merelasikan antara dosen dan matkul
    insertDosentoMatkul(LD,LM,"PRM", "STD");
    insertDosentoMatkul(LD,LM,"PRM", "AKA");
    insertDosentoMatkul(LD,LM,"IRZ", "AKA");

    pilihan = 0;
    pilihan = selectMenu();
    while (pilihan != 0) {
            switch(pilihan) {
            case 1:
            {
                cout << endl;
                cout << "Pilih '1' Menampilkan Mata kuliah yang diampu oleh masing-masing dosen" << endl;
                cout << "Pilih '2' untuk menampilkan daftar matkul" << endl;
                cout << "Pilihan : ";
                cin >> gg;
                if (gg == "1") {
                    show(LD);
                } else if(gg == "2") {
                    showMatkul(LM);
                } else {
                    cout << "pilihan tidak tersedia" << endl;

                }
                break;
            }

            case 2:
            {
                cout << "Jumlah data dosen yang akan ditambahkan : ";
                cin >> o;
                v = 1;
                while (v <= o) {
                    cout << "data ke-" << v << endl;
                    cout << "Masukkan Nama dosen : ";
                    cin.ignore();
                    getline(cin, R.nama);

                    cout << "Masukkan Kode dosen : ";
                    cin >> R.kode;
                    S = newElmDosen(R);
                    insertLastDosen(LD, S);
                    v = v + 1;
                    cout << endl;
                    }
                break;
            }

            case 3:
            {
                cout << "Jumlah data matkul yang akan ditambahkan : ";
                cin >> O;
                V = 1;
                while (V <= O) {
                    cout << "data ke-" << V << endl;
                    cout << "Masukkan Nama matkul : ";
                    cin.ignore();
                    getline(cin, Q.nama);

                    cout << "Masukkan Jumlah SKS : ";
                    cin >> Q.sks;
                    P = newElmMatkul(Q);
                    insertLastMatkul(LM, P);
                    V = V + 1;
                    cout << endl;
                    }
                break;
            }

            case 4:
            {
                cout << "Jumlah relasi yang akan ditambahkan : ";
                cin >> w;
                e = 1;
                while (e <= w) {
                    cout << "data ke-" << e << endl;
                    cout << "Masukkan Kode Dosen : ";
                    cin >> Z.kode;

                    cout << "Masukkan Nama Matkul : ";
                    cin.ignore();
                    getline(cin, C.nama);
                    insertDosentoMatkul(LD, LM, Z.kode, C.nama);
                    e = e + 1;
                    cout << endl;
                    }
                break;
            }

            case 5:
            {
                findMax(LD);
                cout << endl;
                break;
            }

            case 6:
            {
                findMin(LD);
                cout << endl;
                break;
            }

            case 7:
            {
                cout << "Masukkan Kode dosen yang matkulnya akan dihapus : ";
                cin >> Z.kode;
                cout << "Masukkan nama matkul yang akan dihapus : ";
                cin.ignore();
                getline(cin, C.nama);
                deleteRelasi(LD,LR,Re, Z.kode, C.nama);
                break;
            }

            case 8:
            {
                cout << "Masukkan Kode dosen yang akan dihapus : ";
                cin >> Z.kode;
                deleteDosen(LD, D, Z.kode);
                break;
            }

            case 9:
            {
                cout << "Masukkan kode dosen yang ingin ditampilkan : ";
                cin >> Z.kode;
                cout << endl;
                infoMatkulDosen(LD,Z.kode);
                cout << endl;
                break;
            }

            case 10:
            {
                cout << "Masukkan nama mata kuliah yang akan dicari dosen pengampunya : ";
                cin >> C.nama;
                cout << endl;
                searchDosenMatkul(LD,LM, C.nama);
                cout << endl;
                ;
                break;
            }

            }
        cout << "Kembali ke menu utama? (y/n) : " << endl;
        cin >> input;
        if (input == "y") {
            cout << endl;
            pilihan = selectMenu();
        } else if (input == "n"){
            pilihan = 0;
        } else {
            cout << "Maaf pilihan anda tidak sesuai :)" << endl;
            pilihan = 0;
        }

    }
    cout << "======================================== PROGRAM SELESAI ========================================" << endl;


}
