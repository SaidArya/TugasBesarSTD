#include "event.h"

int main() {
	list List;
	event Event;
	tanggal Tanggal;
	addressEvent eventAddress;


	createList(List);
	showDataEvent(List);

	Event.namaEvent = "Event A";
	Event.jenisEvent = "Indoor";
	Event.tanggalEvent.hari = 3;
	Event.tanggalEvent.bulan = "Januari";
	Event.tanggalEvent.tahun = 2022;
	Event.quota = 1000;

	eventAddress = newElementEvent(Event);
	insertLastEvent(List, eventAddress);

	showDataEvent(List);

	return 0;
}