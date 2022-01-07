#include "event.h"
#include <ctime>

int main() {
	list List;
	srand(time(0));
	int selectMenu = 0;

	createList(List);
	showDataEventAll(List);

	while (selectMenu != -1) {
		cout << "\n1. Masukkan Event" << endl;
		cout << "2. Tampilkan semua Event Beserta peserta" << endl;
		cout << "3. Registrasi Event" << endl;
		cout << "4. delete first Event" << endl;
		cout << "5. Cari Event yang tersedia" << endl;
		cout << "Input : "; selectMenu = menu(List);		
	}

	return 0;
}