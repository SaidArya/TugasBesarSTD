#ifndef EVENT_H
#define EVENT_H
#include <iostream>
using namespace std;


typedef struct elementEvent *addressEvent;
typedef struct elementPeserta *addressPeserta;

struct tanggal {
    int tgl, tahun, bulan;
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
void showDataEventAll(list List);
addressEvent newElementEvent(event info);
void insertLastEvent(list &List, addressEvent E);
void inputEvent(list &List, event &Event, addressEvent &E);
addressEvent findEvent(list List, string namaEvent);
int jumlahPeserta(addressEvent &E);
void registrasiEvent(addressEvent &E);
addressPeserta newElementPeserta(peserta info);
void insertLastEvent(addressEvent &E, addressPeserta &P);
void showDataPeserta(addressEvent E);
void deleteFirstEvent(list &List);
void cariEventQuota(list List);



int menu(list &List);

#endif /* EVENT_H */
