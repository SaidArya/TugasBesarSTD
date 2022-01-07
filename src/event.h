#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;

typedef struct elementEvent *addressEvent;
typedef struct elementPeserta *addressPeserta;

struct event {
    string namaEvent, jenisEvent;
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
struct tanggal {
    int hari, tahun;
    string bulan;
};
struct list {
    addressEvent first;
};

void createList(list &L);

#endif /* EVENT_H */
