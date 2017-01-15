Autor: Pawe³ Walczak, 270825
Prowadz¹cy: dr in¿. Tomasz Trzcziñski

1. --Krótka specyfikacja problemu--
Mamy zestaw S nie³amalnych patyków o d³ugoœci Si , gdzie i = {1,2,3,4,5....,S}. Zaproponuj algorytm wyliczaj¹cy
na ile sposobów mo¿na zbudowaæ kwadrat przy u¿yciu 6 z tych patyków i wyznaczy,
które patyki nale¿y u¿yæ.

2. --Uruchamianie--
Otworzyæ projekt, i uruchomiæ plik main.cpp / ewentualnie AAL.exe. 

3. --Opis konwencji wejœciowych--

Istniej¹ 3 tryby wykonania zadania:
*Pierwszy z nich to rêczne wpisanie w konsoli danych wejœciowych. S³u¿y do tego opcja nr 3
 Program dzia³a dla patyków o d³ugoœciach Li = <1;100000>. 
*Drugi tryb to wczytanie danych z pliku. S³u¿y do tego opcja nr 2.
 Pierwsza linijka w pliku to liczba danych do wczytania. Nastêpne linijki
 to d³ugoœci patyków.
*Trzeci tryb to automatyczna generacja danych. S³u¿y do tego opcja nr 
 6. U¿ytkownik jest proszony o wpisanie maksymalnego rozmiaru problemu
 oraz o liczbê testów do wykonania.
 
4. --Krótki opis metod rozwi¹zania (szczegó³y w dokumentacji) -- 
Klas¹ zajmuj¹c¹ siê g³ównymi obliczeniami jest OptimalAlgorithm.h/OptimalAlgorithm.cpp.
Metoda calculateSimple, wylicza liczbê kombinacji. Sprawdza ona dwie g³ówne mo¿liwoœci kombinacji.

 ______________________
 |	 lengthA			|
 |						|
 |						|
 |						|
 |lengthA				|lengthA
 |						|
 |						|
 |						|
 |_____________________	|
 lengthB+ LengthC + lengthD = lengthA
 
 

 ______________________
 |	 lengthA			|
 |						|
 |						|
 |						|
 |lengthA				|lengthB+lengthC=lengthA
 |						|
 |						|
 |						|
 |_____________________	|
lengthD + lengthE = lengthA 

Algorytm korzysta z sortowania, tablicy liczb wyst¹pieñ poszczegó³nych d³ugoœci patyków, tablicy 
liczb wyst¹pieñ par patyków sumuj¹cych siê do danych d³ugoœci.

Metoda showCombinations(), wypisuje unikalne kombinacje na ekran i dzia³a bardzo podobnie
do metody calculateSimple(). Korzysta on jeszcze z tablic (równie¿ dwuwymiarowej), do
przetrzymywania par patyków sumuj¹cych siê do szczególnych d³ugoœci. 


5. --Listing klas i plików--
	Bruteforce.h /Bruteforce.cpp - zawiera klasê i implementacjê metod, której g³ównym zadaniem jest obliczanie iloœci rozwi¹zañ oraz przechowywanie mo¿liwych kombinacji patyków ( które z nich u¿yæ ) w wektorze klas Combinations.
	Combinations.h/Combinations.cpp – prosta klasa, która przechowuje d³ugoœci ( b¹dŸ indeksy)  patyków dla wszystkich kombinacji.  
	FileOperations.h/FileOperations.cpp – zawiera klasê, której zadaniem jest wykonywanie operacji na plikach ( odczyt, zapis, modyfikacja). 
	Menu.h/Menu.cpp – zawiera klasê i implementacjê metod, której zadaniem jest wyœwietlanie Menu oraz interpretacjê ¿¹dañ u¿ytkownika.
	OptimalAlgorithm.h/OptimalAlgorithm.cpp – zawiera klasê i implementacjê metod, której zadaniem jest obliczanie iloœci rozwi¹zañ oraz wypisanie mo¿liwych kombinacji patyków. 
	QuickSorter.h/QuickSorter.cpp – zawiera klasê i implementacjê metod, której zadaniem jest posortowanie zbioru patyków metod¹ QuickSort. 
	BruteforceTests.cpp – testy poprawnoœci algorytmu Bruteforce
	OptimalAlgorithmTests.cpp – testy poprawnoœci algorytmu optymalnego
	QuicksorterTests.cpp – testy poprawnoœci algorytmu sortowania
	dataInput.txt – domyœlnie plik zawieraj¹cy zbiór patyków które chcemy wczytaæ do programu ( Uwaga: pierwsza linijka pliku to rozmiar danych, nastêpne to d³ugoœci patyków ). 
	optimalAlgorithmTime.txt -  czasy wykonania zadania dla poszczególnych rozmiarów zbiorów dla algorytmu optymalnego
	bruteforceTime.txt -  czasy wykonania zadania dla poszczególnych rozmiarów zbiorów dla algorytmu bruteforce
	rawRunningTimeData.txt – dane o czasach wykonania w postaci do analizy dla Matlaba
	main.cpp – uruchamia program
	AnalysisOfAlgorithm.m – skrypt napisany w Matlab, do przeprowadzenia analizy z³o¿onoœci. 

