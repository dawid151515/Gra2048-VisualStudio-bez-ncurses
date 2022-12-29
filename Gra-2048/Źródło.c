#include "gra2048.h"



int main() {
	char znak;


	inicjalizacja();
	testowe_dane();
	narysuj_ekran();
	while (1) {

		znak = getchar();

		if (znak == ENTER)
			continue;

		if (znak == LEWO) {
			lewo();
		}
		if (znak == PRAWO) {
			prawo();
		}
		if (znak == GORA) {
			gora();
		}
		if (znak == DOL) {
			dol();
		}
		//dodaj dol i gore//

		if (znak == NOWA_GRA) {
			puts("Czy napewno chcesz zagrac od nowa?");
			if (Potwierdz()) {
				inicjalizacja();
			}
		}
		if (znak == WYJSCIE && czy_zamknac() == 1) {
			break;
		}


		if (czy_przegrales() == 1 && czy_grasz_jeszcze_raz() == 0) {
			break;
		}

		if (czy_wygrales()) {
			wygrales();
			if (gracz_kontynuuje == 0) {
				break;
			}

		}
		narysuj_ekran();
	}


	return 0;
}