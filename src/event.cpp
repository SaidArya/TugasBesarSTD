#include "event.h"
#include "conio.h"

void createList(list &List) {
    List.first = NULL;
}

void showDataEvent(list List) {
    addressEvent P = List.first;
    if (P == NULL) {
        cout << "Kosong \n";
    } else {
        while (P != NULL) {
            cout << P->info.namaEvent << endl;
            cout << P->info.jenisEvent << endl;
            cout << P->info.tanggalEvent.tgl << " " << P->info.tanggalEvent.bulan << " " << P->info.tanggalEvent.tahun << endl;
            cout << P->info.quota << endl;
            cout << P->info.nPeserta << endl;
            P = P->next;
        }
    }
}

addressEvent newElementEvent(event info) {
    addressEvent E = new elementEvent;
    E->info = info;
    E->next = NULL;
    E->nextPeserta = NULL;
    return E;
}

void insertLastEvent(list &List, addressEvent E) {
    if (List.first == NULL) {
        List.first = E;
    } else {
        addressEvent P = List.first;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = E;
        E->prev = P;
    }
}

void inputEvent(list &List, event &Event, addressEvent &E) {
    string namaEvent, bulanEvent, tempatEvent, jenisEvent;
    char ulang = 'n';
    int quotaEvent, tglEvent, tahunEvent;
    // bool inputUlang = false;
    while (tolower(ulang) != 'y') {
        // cin.ignore();
        cout << "Nama Event    : "; getline(cin, Event.namaEvent);
        cout << "Jenis Event   : "; getline(cin, Event.jenisEvent);
        cout << "Tempat Event  : "; getline(cin, Event.tempatEvent);
        cout << "Tanggal Event : "; cin >> Event.tanggalEvent.tgl;
        cout << "Bulan Event   : "; cin >> Event.tanggalEvent.bulan;
        cout << "Tahun Event   : "; cin >> Event.tanggalEvent.tahun;
        cout << "Quota Event   : "; cin >> Event.quota;
        
        cout << "\n Data sudah benar (Y/N) : "; ulang = getche();
        if (ulang == 'y') {
            E = newElementEvent(Event);
            insertLastEvent(List, E);
        }
    }     
}