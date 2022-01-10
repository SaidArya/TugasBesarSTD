#include "event.h"
#include "conio.h"


void createList(list &List) {
    List.first = NULL;
}

void showDataEventAll(list List) {
    addressEvent P = List.first;
    if (P == NULL) {
        cout << "Kosong \n";
    } else {
        while (P != NULL) {
            cout << P->info.namaEvent << endl;
            cout << P->info.jenisEvent << endl;
            cout << P->info.tanggalEvent.tgl << " " << P->info.tanggalEvent.bulan << " " << P->info.tanggalEvent.tahun << endl;
            cout << P->info.quota << endl;
            cout << jumlahPeserta(P) << endl << endl;
            showDataPeserta(P);

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

addressEvent findEvent(list List, string namaEvent) {
    addressEvent P = List.first;
    while (P != NULL) {
        if (P->info.namaEvent == namaEvent) {
            break;
        }
        P = P->next;
    }
    return P;
}

void inputEvent(list &List) {
    event Event;
    addressEvent E;
    int maxTgl = 0;
    char ulang = 'n';
    while (tolower(ulang) != 'y') {
        cin.ignore(1000, '\n');
        cout << "\nNama Event    : "; getline(cin, Event.namaEvent);
        cout << "Jenis Event   : "; getline(cin, Event.jenisEvent);
        cout << "Tempat Event  : "; getline(cin, Event.tempatEvent);
        cout << "Tahun Event   : "; cin >> Event.tanggalEvent.tahun;
        cout << "Bulan Event   : "; cin >> Event.tanggalEvent.bulan;

        while (Event.tanggalEvent.bulan < 1 || Event.tanggalEvent.bulan > 12) {
            cout << "Input tidak valid" << endl;
            cout << "Bulan Event   : "; cin >> Event.tanggalEvent.bulan;
        }

        if (Event.tanggalEvent.bulan == 1 || Event.tanggalEvent.bulan == 3 || Event.tanggalEvent.bulan == 5|| Event.tanggalEvent.bulan == 7
        || Event.tanggalEvent.bulan == 8 || Event.tanggalEvent.bulan == 10 || Event.tanggalEvent.bulan == 12) {
            maxTgl = 31;
        } else if (Event.tanggalEvent.bulan == 4 || Event.tanggalEvent.bulan == 6 || Event.tanggalEvent.bulan == 9 || Event.tanggalEvent.bulan == 11) {
            maxTgl = 30;
        } else {
            if ((Event.tanggalEvent.tahun % 4) == 0) {
                maxTgl = 29;
            } else {
                maxTgl = 28;
            }
        }

        cout << "Tanggal Event : "; cin >> Event.tanggalEvent.tgl;

        while (Event.tanggalEvent.tgl < 1 ||Event.tanggalEvent.tgl > maxTgl) {
            cout << "Input tidak valid" << endl;
            cout << "Tanggal Event : "; cin >> Event.tanggalEvent.tgl;
        }
        
        cout << "Quota Event   : "; cin >> Event.quota;
        
        cout << "\n Data sudah benar (Y/N) : "; ulang = getche();
        if (ulang == 'y') {
            E = newElementEvent(Event);
            insertLastEvent(List, E);
        }
        
    }
    cout << endl;     
}

int jumlahPeserta(addressEvent &E) {
    int nPeserta = 0;
    addressPeserta Q = E->nextPeserta;
    while (Q != NULL) {
        nPeserta++;
        Q = Q->next;
    }
    return nPeserta;
}

void registrasiEvent(addressEvent &E) {
    peserta Peserta;
    addressPeserta P;
    char ulang = 'n';
    while (tolower(ulang) != 'y') {
        
        cout << "Nama  : "; getline(cin, Peserta.namaPeserta);
        cout << "Email : "; cin >> Peserta.emailPeserta;
        cout << "No. HP: "; cin >> Peserta.noTelepon;
        cout << "Jenis : "; cin >> Peserta.jenisPeserta;

        cout << "\n Data sudah benar (Y/N) : "; ulang = getche();

        if (ulang == 'y') {
            Peserta.noPeserta = (rand() % 10000) + 1;
            Peserta.noTempatDuduk = (rand() % E->info.quota) + 1;
            P = newElementPeserta(Peserta);
            insertLastEvent(E, P);
        }
        cin.ignore(1000, '\n');
    }
}

void insertLastEvent(addressEvent &E, addressPeserta &P) {
    if (E->nextPeserta == NULL) {
        E->nextPeserta = P;
    } else {
        addressPeserta Q = E->nextPeserta;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void deleteFirstEvent(list &List) {
    addressEvent E = List.first;
    if (E->next == NULL) {
        List.first = NULL;
    } else {
        List.first = E->next;
        E->next->prev = NULL;
        E->next = NULL;
    }
}

void cariEventQuota(list List) {
    int i = 0;
    addressEvent E = List.first;
    while (E != NULL) {
        if (jumlahPeserta(E) < E->info.quota) {
            cout << "Nama Event" << E->info.namaEvent << endl;
            i++;
        }
        E = E->next;
    }
    if (i == 0) {
        cout << "Kosong" << endl;
    }
}

addressPeserta newElementPeserta(peserta info) {
    addressPeserta P = new elementPeserta;
    P->info = info;
    P->next = NULL;
    return P;
}

void showDataPeserta(addressEvent E) {
    addressPeserta P = E->nextPeserta;
    if (P == NULL) {
        cout << "Kosong" << endl;
    } else {
        while (P != NULL) {
            cout << "Nama : " << P->info.namaPeserta << endl;
            cout << "NoDuduk : " << P->info.noTempatDuduk << endl;
            cout << "NoPeserta : " << P->info.noPeserta << endl;
            P = P->next;
        }
    }
}

void hapusFirstPeserta(addressEvent &E) {
    if (E->nextPeserta->next == NULL) {
        E->nextPeserta = NULL;
    } else {
        E->nextPeserta = E->nextPeserta->next;
        E->prev = NULL;
    }
}

void hapusLastPeserta(addressEvent &E) {
    addressPeserta P = E->nextPeserta;
    while (P->next != NULL) {
        P = P->next;
    }
    if (P->next == NULL) {
        P = P->prev;
        P->next = NULL;
    } else {
        E->nextPeserta = NULL;
    }
}

void hapusAfterPeserta(addressEvent &E, addressPeserta prec, addressPeserta P) {
    prec->next = P->next;
    P->next->prev = prec;
    P->next = NULL;
    P->prev = NULL;
}

void hapusPeserta(addressEvent &E, string nama) {
    addressPeserta P = E->nextPeserta;
    while (P != NULL) {
        if (P->info.namaPeserta == nama) {
            break;
        }
        P = P->next;
    }
    if (P == NULL) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        if (P == E->nextPeserta) {
            hapusFirstPeserta(E);
        } else if (P->next == NULL) {
            hapusLastPeserta(E);
        } else {
            addressPeserta prec = P->prev;
            hapusAfterPeserta(E, prec, P);
        }
    }
}

int menu(list &List) {
    string namaEvent, namaPeserta;
    addressEvent E;
    int iMenu = 0;
    cin >> iMenu;
    
    switch (iMenu) {
        case 1:
            inputEvent(List);
            break;
        case 2:
            showDataEventAll(List);
            break;
        case 3:
            if (List.first == NULL) {
                cout << "Kosong" << endl;
            } else {
                cin.ignore(1000, '\n');
                cout << "Nama Event : "; getline(cin, namaEvent);
                E = findEvent(List, namaEvent);
                if (E != NULL) {
                    registrasiEvent(E);
                } else {
                    cout << "Event tidak ditemukan" << endl;
                }  
            }
            break;
        case 4:
            deleteFirstEvent(List);
            break;
        case 5:
            cariEventQuota(List);
            break;
        case 6:
            cin.ignore(1000, '\n');
            if (List.first == NULL) {
                cout << "Kosong" << endl;
            } else {
                cout << "Nama Event : "; getline(cin, namaEvent);
                E = findEvent(List, namaEvent);
                if (E != NULL) {
                    cout << "Nama Peserta : "; getline(cin, namaPeserta);
                    hapusPeserta(E, namaPeserta);
                } else {
                    cout << "Event tidak ditemukan" << endl;
                } 
            }  
            break;
    }
    return iMenu;
}