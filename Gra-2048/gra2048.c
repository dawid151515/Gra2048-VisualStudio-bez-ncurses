#include "gra2048.h"


void inicjalizacja() {
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			tablica[i][j] = PUSTE_POLE;
		}
	}
	wstaw_nowa_liczbe();
	wstaw_nowa_liczbe();
	punkty = 0;
	gracz_kontynuuje = 0;
	liczba_ruchow = 0;
}

void wstaw_nowa_liczbe() {
	// wylosuj liczbe i wstaw ja do tablicy;
	//wylosuj 2 lub 4 i wpisz w wylosowane miejsce
	int zarodek;
	time_t tt;
	zarodek = time(&tt);
	srand(zarodek);
	int wartosc_do_wstawienia = 2 + 2 * (rand() % 2); // bedziesz mial 2 albo 4
	printf("wylosowalismy %d\n", wartosc_do_wstawienia);

	int liczba_pustych_pol = 0;

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (tablica[i][j] == PUSTE_POLE) {
				liczba_pustych_pol++;
			}
		}
	}

	int pole_do_wpisania = 1 + (rand() % liczba_pustych_pol);
	printf("wylosowalismy pole numer %d\n", pole_do_wpisania);

	int licznik_pol = 0;
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (tablica[i][j] == PUSTE_POLE) {
				licznik_pol++;
			}
			if (licznik_pol == pole_do_wpisania) {
				tablica[i][j] = wartosc_do_wstawienia;
				return;
			}
		}
	}
}

int czy_wygrales() {

	if (gracz_kontynuuje == 1) {
		return 0;
	}

	for (int i = 0; i < ROZMIAR; i++)
	{
		for (int j = 0; j < ROZMIAR; j++)
		{
			if (tablica[i][j] == WYGRANA) {
				return 1;
			}
		}
	}
	return 0;
}

void wygrales() {
	puts("Wygrales");
	puts("Czy chcesz kontynuowac?");
	Potwierdz();
	if (Potwierdz() == 1) {
		gracz_kontynuuje = 1;

	}

}
void testowe_dane() {
	tablica[0][0] = PUSTE_POLE;
	tablica[0][1] = PUSTE_POLE;
	tablica[0][2] = PUSTE_POLE;
	tablica[0][3] = PUSTE_POLE;

	tablica[1][0] = PUSTE_POLE;
	tablica[1][1] = PUSTE_POLE;
	tablica[1][2] = PUSTE_POLE;
	tablica[1][3] = PUSTE_POLE;

	tablica[2][0] = PUSTE_POLE;
	tablica[2][1] = PUSTE_POLE;
	tablica[2][2] = PUSTE_POLE;
	tablica[2][3] = PUSTE_POLE;

	tablica[3][0] = PUSTE_POLE;
	tablica[3][1] = PUSTE_POLE;
	tablica[3][2] = PUSTE_POLE;
	tablica[3][3] = PUSTE_POLE;
}
void narysuj_ekran() {

	int dlugosc_kreski = 1 + 7 * ROZMIAR;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	printf("   Punkty: %d \n", punkty);
	printf("   Liczba ruchow: %d\n", liczba_ruchow);

	rysuj_pozioma_kreska("   ", dlugosc_kreski);
	for (int i = 0; i < ROZMIAR; i++) {
		printf("   |");
		for (int j = 0; j < ROZMIAR; j++) {
			if (tablica[i][j] == PUSTE_POLE) {
				printf(" %4s |", " ");
			}
			else {
				printf(" %4d |", tablica[i][j]);
			}
		}
		printf("\n");
		rysuj_pozioma_kreska("   ", dlugosc_kreski);
	}
}
void rysuj_pozioma_kreska(char* prefix, int dlugosc) {
	printf("%s", prefix);
	for (int i = 0; i < dlugosc; i++) {
		printf("-");
	}
	printf("\n");
}
void lewo() {
	liczba_ruchow = liczba_ruchow + 1;
	for (int i = 0; i < ROZMIAR; i++)
	{
		for (int j = 1; j < ROZMIAR; j++)
		{
			if (tablica[i][j] == PUSTE_POLE) {
				continue;
			}

			for (int k = j - 1; k > -1; k--) {
				if (tablica[i][k] == PUSTE_POLE) {
					tablica[i][k] = tablica[i][k + 1];
					tablica[i][k + 1] = PUSTE_POLE;
					continue;
				}
				if (tablica[i][k] == tablica[i][k + 1]) {
					tablica[i][k] += tablica[i][k + 1];
					tablica[i][k + 1] = PUSTE_POLE;
					punkty += tablica[i][k];
					break;
				}
				if (tablica[i][k] != tablica[i][k + 1]) {
					break;
				}
			}

		}
	}

	puts("ruszylem w lewo\n");
	wstaw_nowa_liczbe();
}
void prawo() {
	liczba_ruchow = liczba_ruchow + 1;
	for (int i = 0; i < ROZMIAR; i++)
	{
		for (int j = ROZMIAR - 2; j > -1; j--)
		{
			if (tablica[i][j] == PUSTE_POLE) {
				continue;
			}

			for (int k = j + 1; k < ROZMIAR; k++) {
				if (tablica[i][k] == PUSTE_POLE) {
					tablica[i][k] = tablica[i][k - 1];
					tablica[i][k - 1] = PUSTE_POLE;
					continue;
				}
				if (tablica[i][k] == tablica[i][k - 1]) {
					tablica[i][k] += tablica[i][k - 1];
					tablica[i][k - 1] = PUSTE_POLE;
					punkty += tablica[i][k];
					break;
				}
				if (tablica[i][k] != tablica[i][k - 1]) {
					break;
				}
			}

		}
	}

	puts("ruszylem w prawo\n");
	wstaw_nowa_liczbe();
}
void gora() {
	liczba_ruchow = liczba_ruchow + 1;

	for (int j = 0; j < ROZMIAR; j++)
	{
		for (int i = 1; i < ROZMIAR; i++)
		{
			if (tablica[i][j] == PUSTE_POLE) {
				continue;
			}

			for (int k = i - 1; k > -1; k--) {
				if (tablica[k][j] == PUSTE_POLE) {
					tablica[k][j] = tablica[k + 1][j];
					tablica[k + 1][j] = PUSTE_POLE;
					continue;
				}
				if (tablica[k][j] == tablica[k + 1][j]) {
					tablica[k][j] += tablica[k + 1][j];
					tablica[k + 1][j] = PUSTE_POLE;
					punkty += tablica[k][j];
					break;
				}
				if (tablica[k][j] != tablica[k + 1][j]) {
					break;
				}
			}

		}
	}

	puts("ruszylem w gore\n");
	wstaw_nowa_liczbe();
}

void dol() {
	liczba_ruchow = liczba_ruchow + 1;
	for (int j = 0; j < ROZMIAR; j++)//j sie wolniej zmienia
	{
		for (int i = ROZMIAR - 2; i > -1; i--)
		{
			if (tablica[i][j] == PUSTE_POLE) {
				continue;
			}

			for (int k = i + 1; k < ROZMIAR; k++) {
				if (tablica[k][j] == PUSTE_POLE) {
					tablica[k][j] = tablica[k - 1][j];
					tablica[k - 1][j] = PUSTE_POLE;
					continue;
				}
				if (tablica[k][j] == tablica[k - 1][j]) {
					tablica[k][j] += tablica[k - 1][j];
					tablica[k - 1][j] = PUSTE_POLE;
					punkty += tablica[k][j];
					break;
				}
				if (tablica[k][j] != tablica[k - 1][j]) {
					break;
				}
			}

		}
	}

	puts("ruszylem w dol\n");
	wstaw_nowa_liczbe();
}
//dopisz//

int Potwierdz() {
	char c;

	do {

		puts("Wpisz t lub n");
		c = getchar();


	} while (c != PRAWDA && c != FALSZ);
	return c == PRAWDA ? 1 : 0;
}
int czy_zamknac() {
	puts("Czy napewno chcesz zakonczyc gre?");
	int potwierdzenie = Potwierdz();
	if (potwierdzenie) {//zdefiniyj t i n//
		puts("zanykam");
		return 1;
		//zamknij znajdz funkcje// 
	}
	return 0;

}
int czy_przegrales() {
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (tablica[i][j] == PUSTE_POLE) {
				return 0;
			}
		}
	}
	return 1;
}
int czy_grasz_jeszcze_raz() {

	puts("Koniec gry!");
	puts("Czy chcesz zagrac jeszcze raz?");

	int potwierdzenie = Potwierdz();

	if (potwierdzenie) {
		inicjalizacja();
		return 1;
	}
	else {
		return 0;
	}
}