#include "event.h"

int main() {
	list List;
	// event Event;
	// tanggal Tanggal;
	// addressEvent eventAddress;
	int selectMenu = 0;


	createList(List);
	showDataEvent(List);

	// Event.namaEvent = "Event A";
	// Event.jenisEvent = "Indoor";
	// Event.tanggalEvent.tgl = 3;
	// Event.tanggalEvent.bulan = "Januari";
	// Event.tanggalEvent.tahun = 2022;
	// Event.quota = 1000;

	// eventAddress = newElementEvent(Event);
	// insertLastEvent(List, eventAddress);
	// inputEvent(List, Event, eventAddress);

	// showDataEvent(List);

	while (selectMenu != -1) {
		cout << "\n1. Masukkan Event" << endl;
		cout << "2. Tampilkan Event" << endl;
		cout << "3. Cari Event" << endl;
		cout << "Input : "; selectMenu = menu(List);		
	}

	return 0;
}