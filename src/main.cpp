#include "event.h"
#include <ctime>

int main() {
	list List;
	int selectMenu = 0;
	srand(time(0));
	createList(List);
	showDataEventAll(List);

	while (selectMenu != -1) {
		cout << "\n1. Masukkan Event" << endl;
		cout << "2. Tampilkan semua Event Beserta peserta" << endl;
		cout << "3. Registrasi Event" << endl;
		cout << "4. delete first Event" << endl;
		cout << "5. Tampilkan event yang tersedia" << endl;
		cout << "6. Hapus peserta" << endl;
		cout << "Input : "; selectMenu = menu(List);		
	}
	return 0;
}