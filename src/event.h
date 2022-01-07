#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;


typedef struct elementEvent *addressEvent;
typedef struct elementPeserta *addressPeserta;

struct tanggal {
    int tgl, tahun;
    string bulan;
};
struct event {
    string namaEvent, jenisEvent, tempatEvent;
    tanggal tanggalEvent;
    int quota, nPeserta;
};
struct peserta {
    string namaPeserta, emailPeserta, jenisPeserta;
    int noPeserta, noTelepon, noTempatDuduk;
};
struct elementEvent {
    event info;
    addressEvent next, prev;
    addressPeserta nextPeserta;
};
struct elementPeserta {
    peserta info;
    addressPeserta next, prev;
};


struct list {
    addressEvent first;
};

void createList(list &List);
void showDataEvent(list List);
addressEvent newElementEvent(event info);
void insertLastEvent(list &List, addressEvent E);
void inputEvent(list &List, event &Event, addressEvent &E);


#endif /* EVENT_H */
