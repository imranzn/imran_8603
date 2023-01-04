#ifndef KAMPUS_H_INCLUDED
#define KAMPUS_H_INCLUDED


#include <iostream>

using namespace std;

#define infoDosen(P) (P)->infoDosen
#define infoMatkul(P) (P)->infoMatkul
#define nextDosen(P) (P)->nextDosen
#define nextMatkul(P) (P)->nextMatkul
#define nextRelasi(P) (P)->nextRelasi
#define relasiMatkul(P) (P)->relasiMatkul
#define matkul(P) (P)->matkul
#define firstDosen(L) ((L).firstDosen)
#define firstMatkul(L) ((L).firstMatkul)
#define firstRelasi(L) ((L).firstRelasi)
#define nil NULL



struct dosen{
    string nama;
    string kode;
};

struct matkul {
    string nama;
    int sks;
};

typedef struct elmDosen *adrDosen;
typedef struct elmMatkul *adrMatkul;
typedef struct elmRelasi *adrRelasi;

struct elmDosen {
    dosen infoDosen;
    adrDosen nextDosen;
    adrRelasi matkul;
};

struct elmMatkul {
    matkul infoMatkul;
    adrMatkul nextMatkul;
};

struct elmRelasi {
    adrRelasi nextRelasi;
    adrMatkul relasiMatkul;
};

struct listDosen {
    adrDosen firstDosen;
};

struct listRelasi {
    adrRelasi firstRelasi;
};

struct listMatkul{
    adrMatkul firstMatkul;
};

// Dosen

void createListDosen(listDosen &LD);
adrDosen newElmDosen(dosen infoD);
void insertLastDosen(listDosen &LD, adrDosen D);
void deleteFirstDosen(listDosen &LD, adrDosen &D);
void deleteLastDosen(listDosen &LD, adrDosen &D);
void deleteAfterDosen(listDosen &LD, adrDosen &D, adrDosen prec);
adrDosen searchDosen (listDosen LD, string kode);


// Matkul

void createListMatkul(listMatkul &LM);
adrMatkul newElmMatkul(matkul infoM);
void insertLastMatkul(listMatkul &LM, adrMatkul M);
void deleteFirstMatkul(listMatkul &LM, adrMatkul &M);
adrMatkul searchMatkul(listMatkul LM, string nama);

// relasi

void createListRelasi(listRelasi &LR);
adrRelasi newElmRelasi(adrMatkul M);
void insertDosentoMatkul(listDosen &LD, listMatkul &LM, string kodeDosen, string namaMatkul);
void deleteLastRelasi(listRelasi &LR, adrRelasi &R);
void deleteFirstRelasi(listRelasi &LR, adrRelasi &R);
void deleteAfterRelasi(listRelasi &LR, adrRelasi &R, adrRelasi S);
void deleteRelasi(listDosen &LD, listRelasi &LR , adrRelasi &R, string kode, string nama);


//fungsi tambahan
void findMax(listDosen LD);
void findMin(listDosen LD);
void show(listDosen LD);
int totalMatkulDosen(listDosen LD);
int selectMenu();
void showMatkul(listMatkul LM);
void deleteDosen(listDosen &LD, adrDosen &D, string kode);
void infoMatkulDosen(listDosen LD,string kode);
void searchDosenMatkul(listDosen LD,listMatkul LM, string namaMatkul);



#endif // KAMPUS_H_INCLUDED
