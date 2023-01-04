#include "kampus.h"

// Dosen
void createListDosen(listDosen &LD){
    firstDosen(LD) = nil;
}
adrDosen newElmDosen(dosen infoD){
    adrDosen P;
    P = new elmDosen;

    infoDosen(P) = infoD;
    nextDosen(P) = nil;
    matkul(P) = nil;

    return P;
}
void insertLastDosen(listDosen &LD, adrDosen D){
    adrDosen P;

    P = firstDosen(LD);
    if (firstDosen(LD) == nil) {
        firstDosen(LD) = D;
    }else {
        while(nextDosen(P) != nil) {
        P = nextDosen(P);
    }
    nextDosen(P) = D;
    }

}
void deleteFirstDosen(listDosen &LD, adrDosen &D){
    if(firstDosen(LD) == nil){
        cout<<"List Kosong"<<endl;
    } else if (nextDosen(firstDosen(LD)) == nil) {
        D = firstDosen(LD);
        firstDosen(LD) = nil;
    }else{
        D = firstDosen(LD);
        firstDosen(LD) = nextDosen(firstDosen(LD));
        nextDosen(D)= nil;
    }

}

void deleteLastDosen(listDosen &LD, adrDosen &D) {
    adrDosen E;
    if(firstDosen(LD) == nil) {
        cout << "List Kosong" << endl;
    }else if (nextDosen(firstDosen(LD)) == nil) {
        D = firstDosen(LD);
        firstDosen(LD) = nil;
    }else {
        E = firstDosen(LD);
        while(nextDosen(nextDosen(E)) != nil) {
            E = nextDosen(E);
        }
        D = nextDosen(E);
        nextDosen(E) = nil;
        nextDosen(D) = nil;
    }

}

void deleteAfterDosen(listDosen &LD, adrDosen &D, adrDosen prec){
     if(firstDosen(LD) == nil) {
        cout << "List Kosong" << endl;
    }else if (nextDosen(firstDosen(LD)) == nil) {
        D = firstDosen(LD);
        firstDosen(LD) = nil;
    }else {
        D = nextDosen(prec);
        nextDosen(prec) = nextDosen(D);
        nextDosen(D) = nil;
    }

}

void deleteDosen(listDosen &LD, adrDosen &D, string kode){
    adrDosen P;
    adrDosen Q;

    P = nextDosen(firstDosen(LD));
    Q = firstDosen(LD);

    while(P != nil && infoDosen(Q).kode != kode && infoDosen(P).kode != kode) {
        P = nextDosen(P);
        Q = nextDosen(Q);
    }

    if(P == nil && firstDosen(LD) == nil) {
        cout << "Kode dosen tidak ditemukan"<<endl;
    }else if (infoDosen(firstDosen(LD)).kode == kode) {
        deleteFirstDosen(LD, D);
    }else if (nextDosen(P) == nil)  {
        deleteLastDosen(LD,D);
    }else{
        deleteAfterDosen(LD,D,Q);
    }
}



adrDosen searchDosen (listDosen LD, string kode){
    adrDosen P;
    P = firstDosen(LD);
    while(P != nil && infoDosen(P).kode != kode){
        P = nextDosen(P);
    }
    return P;
}


// Matkul

void createListMatkul(listMatkul &LM){
    firstMatkul(LM) = nil;
}
adrMatkul newElmMatkul(matkul infoM){
    adrMatkul P;
    P = new elmMatkul;

    infoMatkul(P) = infoM;
    nextMatkul(P) = nil;

    return P;
}
void insertLastMatkul(listMatkul &LM, adrMatkul M){
    adrMatkul P;

    P = firstMatkul(LM);
    if (firstMatkul(LM) == nil) {
        firstMatkul(LM) = M;
    }else {
        while(nextMatkul(P) != nil) {
        P = nextMatkul(P);
    }
    nextMatkul(P) = M;
    }

}

void deleteFirstMatkul(listMatkul &LM, adrMatkul &M){
    if(firstMatkul(LM) == nil){
        cout<<"List Kosong"<<endl;
    } else if (nextMatkul(firstMatkul(LM)) == nil) {
        M = firstMatkul(LM);
        firstMatkul(LM) = nil;
    }else{
        M = firstMatkul(LM);
        firstMatkul(LM) = nextMatkul(firstMatkul(LM));
        nextMatkul(M)= nil;
    }

}


adrMatkul searchMatkul(listMatkul LM, string nama){
    adrMatkul P;
    P = firstMatkul(LM);
    while(P != nil && infoMatkul(P).nama != nama){
        P = nextMatkul(P);
    }
    return P;
}



// relasi

void createListRelasi(listRelasi &LR){

    firstRelasi(LR) = nil;
}
adrRelasi newElmRelasi(adrMatkul M){
    adrRelasi R;

    R = new elmRelasi;
    nextRelasi(R) = nil;
    relasiMatkul(R) = M;

    return R;
}



void deleteRelasi(listDosen &LD, listRelasi &LR , adrRelasi &R, string kode, string nama){
    adrDosen P;
    P = searchDosen(LD,kode);

    if (P == nil){
        cout<<"Kode dosen tidak ditemukan"<<endl;
    }else{
        adrRelasi Q;
        adrRelasi S;
        S = matkul(P);
        Q = nextRelasi(S);

        while (matkul(P) != nil && Q != nil && infoMatkul(relasiMatkul(Q)).nama != nama && infoMatkul(relasiMatkul(S)).nama != nama){
            Q = nextRelasi(Q);
            S = nextRelasi(S);
        }
        if (S == nil && firstRelasi(LR) == nil){
            cout<<"Dosen ini tidak mengajar Mata Kuliah tersebut"<<endl;

        }else if (infoMatkul(relasiMatkul(S)).nama == nama){
            R = S;
            matkul(P) = nextRelasi(R);
            nextRelasi(R) = nil;
        }else if (nextRelasi(Q) == nil){
            R = Q;
            nextRelasi(S) = nil;
        }else{
            R = Q;
            nextRelasi(S) = nextRelasi(R);
            nextRelasi(R) = nil;


        }

    }
}


void findMax(listDosen LD){
    adrDosen P;
    adrDosen Q;
    adrRelasi J;
    adrMatkul X;
    int Total;
    int Max;

    Max = 0;
    Q = firstDosen(LD);
    P = firstDosen(LD);
    while (P != nil ) {
        J = matkul(P);
        if(matkul(P) != nil) {
            Total = 0;
            while(J != nil) {
                X = relasiMatkul(J);
                Total = Total + 1;
                J = nextRelasi(J);
            }
        }
        if (Max <= Total) {
            Max = Total;
            Q = P;


        }
        P = nextDosen(P);
    }

    P = firstDosen(LD);
    while (P != nil ) {
        J = matkul(P);
        if(matkul(P) != nil) {
            Total = 0;
            while(J != nil) {
                X = relasiMatkul(J);
                Total = Total + 1;
                J = nextRelasi(J);
            }
        }
        if (Max == Total) {
           cout << "Dosen yang paling banyak mengampu mata kuliah adalah " << infoDosen(P).nama;
            cout << " dengan jumlah " << Max << " Matkul" << endl;



        }
        P = nextDosen(P);
    }


}
void findMin(listDosen LD){
    adrDosen P;
    adrDosen Q;
    adrRelasi J;
    adrMatkul X;
    int Total;
    int Min;

    Min = 999;
    Q = firstDosen(LD);
    P = firstDosen(LD);
    while (P != nil ) {
        J = matkul(P);
        if(matkul(P) != nil) {
            Total = 0;
            while(J != nil) {
                X = relasiMatkul(J);
                Total = Total + 1;
                J = nextRelasi(J);
            }
        }
        if (Min >= Total) {
            Min = Total;
            Q = P;

        }
        P = nextDosen(P);
    }
    P = firstDosen(LD);
    while (P != nil ) {
        J = matkul(P);
        if(matkul(P) != nil) {
            Total = 0;
            while(J != nil) {
                X = relasiMatkul(J);
                Total = Total + 1;
                J = nextRelasi(J);
            }
        }
        if (Min == Total) {
           cout << "Dosen yang paling sedikit mengampu mata kuliah adalah " << infoDosen(P).nama;
            cout << " dengan jumlah " << Total << " Matkul" << endl;
        }
        P = nextDosen(P);
    }

}

void show(listDosen LD){
    adrDosen P;
    adrRelasi J;
    adrMatkul X;
    int jumlah;
    int Matkul;
    int k,l;

    jumlah = 0;
    l = 1;
    k = 1;
    P = firstDosen(LD);
    while (P != nil ) {
        cout << "Dosen ke-" << l << endl;
        cout << "Nama Dosen : " << infoDosen(P).nama << endl;
        cout << "Kode Dosen : " <<  infoDosen(P).kode << endl;
        cout << endl;
        l = l + 1;
        J = matkul(P);
        if(matkul(P) != nil) {
            while(J != nil) {
                X = relasiMatkul(J);
                cout << "Matkul yang diampu ke-" << k << endl;
                cout << "Nama Matkul : " << infoMatkul(X).nama << endl;
                cout << "Jumlah SKS Matkul : " << infoMatkul(X).sks << endl;
                jumlah = jumlah + 1;
                J = nextRelasi(J);
                k = k + 1;
            }
            k = 1;
            cout << "Total Matkul yang Diampu oleh dosen " << infoDosen(P).nama << " adalah sebanyak " << jumlah << endl;
            jumlah = 0;
            cout << endl;

        }
        P = nextDosen(P);
    }

}

void insertDosentoMatkul(listDosen &LD, listMatkul &LM, string kodeDosen, string namaMatkul){
    adrDosen D;
    adrMatkul M;
    adrRelasi R;
    adrRelasi J;
    D = searchDosen(LD, kodeDosen);
    M = searchMatkul(LM, namaMatkul);

    if(D != nil && M != nil) {
        R = new elmRelasi;
        nextRelasi(R) = nil;
        relasiMatkul(R) = M;
        if(matkul(D) == nil) {
            matkul(D) = R;
        }else {
            J = matkul(D);
            while (nextRelasi(J) != nil) {
                J = nextRelasi(J);
            }
            nextRelasi(J) = R;
        }
    }else {
        cout << "Gagal Menambahkan Mata Kuliah" << endl;
    }
}

int totalMatkulDosen(listDosen LD){
    adrDosen P;
    adrRelasi J;
    adrMatkul X;
    int Total;
    int Max;

    Total = 0;
    Max = 0;
    P = firstDosen(LD);
    J = matkul(P);
    while (P != nil ) {
        if(matkul(P) != nil) {
            while(J != nil) {
                X = relasiMatkul(J);
                Total = Total + 1;
                J = nextRelasi(J);
            }
        }
        if (Max <= Total) {
            Max = Total;
        }
        P = nextDosen(P);
    }
    return Max;
}

void showMatkul(listMatkul LM) {
    adrMatkul M;
    if (firstMatkul(LM) == nil) {
        cout << "List Matkul Kosong" << endl;
    } else {
        M = firstMatkul(LM);
        while (M != nil) {
            cout << "Nama Matkul : " << infoMatkul(M).nama << endl;
            cout << "Jumlah SKS Matkul : " << infoMatkul(M).sks << endl;
            cout << endl;
            M = nextMatkul(M);
        }
    }
}

void infoMatkulDosen(listDosen DL,string kode){
    adrDosen P;
    adrRelasi Q;
    int k;
    int jumlah;

    k = 1;
    jumlah = 0;
    P = searchDosen(DL,kode);
    if(P == nil){
        cout<<"Kode dosen tidak ditemukan"<<endl;
    }else{
        cout<<"Nama dosen : "<<infoDosen(P).nama<<endl;
        cout<<"Kode dosen : "<<infoDosen(P).kode<<endl;
        cout<<endl;

        Q = matkul(P);
        while(Q != nil){
            cout << "Matkul yang diampu ke-" << k << endl;
            cout<<"Nama Matkul : "<<infoMatkul(relasiMatkul(Q)).nama<<endl;
            cout<<"jumlah SKS matkul : "<<infoMatkul(relasiMatkul(Q)).sks<<endl;
            jumlah = jumlah + 1;
            Q = nextRelasi(Q);
            k = k + 1;
        }
        cout << "Total Matkul yang Diampu oleh dosen " << infoDosen(P).nama << " adalah sebanyak " << jumlah << endl;
        jumlah = 0;
    }

}

void searchDosenMatkul(listDosen LD,listMatkul LM, string namaMatkul){
    adrDosen P;
    adrRelasi Q;
    adrMatkul M;

    int l = 1;
    M = searchMatkul(LM,namaMatkul);

    if (M == nil){
        cout<<"Mata kuliah tidak ditemukan"<<endl;
    }else{

        P = firstDosen(LD);
        if(P != nil){
            while(P != nil){
                Q = matkul(P);
                while (Q != nil){
                    if (infoMatkul(relasiMatkul(Q)).nama == namaMatkul){
                        cout << "Dosen ke-" << l << endl;
                        cout<<"Nama dosen : "<<infoDosen(P).nama<<endl;
                        cout<<"Kode dosen : "<<infoDosen(P).kode<<endl;
                        l = l + 1;
                    }
                    Q = nextRelasi(Q);
                }
                P = nextDosen(P);
            }
        }

    }

}

int selectMenu(){
    int input;
    cout << "========================================== DAFTAR MENU ==========================================" << endl;
    cout << "1. Menampilkan Mata kuliah yang diampu oleh masing-masing dosen / Menampilkan daftar mata kuliah" << endl;
    cout << "2. Menambah daftar dosen" << endl;
    cout << "3. Menambah daftar mata kuliah" << endl;
    cout << "4. Menambahkan relasi dosen ke mata kuliah" << endl;
    cout << "5. Menampilkan dosen yang paling banyak mengampu mata kuliah" << endl;
    cout << "6. Menampilkan dosen yang paling sedikit mengampu mata kuliah" << endl;
    cout << "7. Menghapus satu mata kuliah yang diampu oleh dosen tertentu" << endl;
    cout << "8. Menghapus satu dosen yang sudah pensiun" << endl;
    cout << "9. Menampilkan dosen tertentu beserta mata kuliah yang diampu" << endl;
    cout << "10. Menampilkan mata kuliah tertentu beserta dosen yang mengampunya" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan menu: ";

    input = 0;
    cin >> input;

    return input;
}



