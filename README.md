Gra2048-VisualStudio-bez-ncurses

Jest to gra konsolowa.

Celem gry jest uzyskanie wyniku 2048. Gracz może przemieszczać kwadratowe klocki w pionie i w poziomie, każdy ruch przesuwa je o jedno pole w wybranym kierunku, a po jego wykonaniu na planszy odkryte zostaje jedno pole z cyfrą 2 lub 4. Klocki zatrzymują się, gdy natrafią na koniec planszy lub klocek o innej wartości. Kiedy klocki mają tą samą wartość to sumują się w jeden klocek o większej (zsumowanej) wartości.

Grę można uruchomić w Visual Studio na Windowsie.
Nie posiada ona biblioteki ncurses, więc jest również mniej rozwinięta niż ta sama aplikacja na Linuxa. Sterowanie nią następuje przy użyciu liter w, a, s, d, lecz przy każdym wpisaniu litery, należy kliknąć enter, aby zatwierdzić ruch. Również te same liczby nie są kolorowane. Za każdym razem, gdy wykonamy ruch rysowana jest nowa tablica z kolejną wylosowaną liczbą i przesuwając konsolę do góry można zobaczyć wszystkie tablice narysowane po każdym wykonanym ruchu, gdyż poprzednie tablice nie są usuwane. Plusem tej wersji gry jest to, że można ją uruchamić w Visual Studio na windowsie, kiedy nie posiada się Linuxa Ubuntu.
