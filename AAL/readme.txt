Autor: Pawe� Walczak, 270825
Prowadz�cy: dr in�. Tomasz Trzczi�ski

1. --Kr�tka specyfikacja problemu--
Mamy zestaw S nie�amalnych patyk�w o d�ugo�ci Si , gdzie i = {1,2,3,4,5....,S}. Zaproponuj algorytm wyliczaj�cy
na ile sposob�w mo�na zbudowa� kwadrat przy u�yciu 6 z tych patyk�w i wyznaczy,
kt�re patyki nale�y u�y�.

2. --Uruchamianie--
Otworzy� projekt, i uruchomi� plik main.cpp / ewentualnie AAL.exe. 

3. --Opis konwencji wej�ciowych--

Istniej� 3 tryby wykonania zadania:
*Pierwszy z nich to r�czne wpisanie w konsoli danych wej�ciowych. S�u�y do tego opcja nr 3
 Program dzia�a dla patyk�w o d�ugo�ciach Li = <1;100000>. 
*Drugi tryb to wczytanie danych z pliku. S�u�y do tego opcja nr 2.
 Pierwsza linijka w pliku to liczba danych do wczytania. Nast�pne linijki
 to d�ugo�ci patyk�w.
*Trzeci tryb to automatyczna generacja danych. S�u�y do tego opcja nr 
 6. U�ytkownik jest proszony o wpisanie maksymalnego rozmiaru problemu
 oraz o liczb� test�w do wykonania.
 
4. --Kr�tki opis metod rozwi�zania (szczeg�y w dokumentacji) -- 
Klas� zajmuj�c� si� g��wnymi obliczeniami jest OptimalAlgorithm.h/OptimalAlgorithm.cpp.
Metoda calculateSimple, wylicza liczb� kombinacji. Sprawdza ona dwie g��wne mo�liwo�ci kombinacji.

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

Algorytm korzysta z sortowania, tablicy liczb wyst�pie� poszczeg�nych d�ugo�ci patyk�w, tablicy 
liczb wyst�pie� par patyk�w sumuj�cych si� do danych d�ugo�ci.

Metoda showCombinations(), wypisuje unikalne kombinacje na ekran i dzia�a bardzo podobnie
do metody calculateSimple(). Korzysta on jeszcze z tablic (r�wnie� dwuwymiarowej), do
przetrzymywania par patyk�w sumuj�cych si� do szczeg�lnych d�ugo�ci. 


5. --Listing klas i plik�w--
	Bruteforce.h /Bruteforce.cpp - zawiera klas� i implementacj� metod, kt�rej g��wnym zadaniem jest obliczanie ilo�ci rozwi�za� oraz przechowywanie mo�liwych kombinacji patyk�w ( kt�re z nich u�y� ) w wektorze klas Combinations.
	Combinations.h/Combinations.cpp � prosta klasa, kt�ra przechowuje d�ugo�ci ( b�d� indeksy)  patyk�w dla wszystkich kombinacji.  
	FileOperations.h/FileOperations.cpp � zawiera klas�, kt�rej zadaniem jest wykonywanie operacji na plikach ( odczyt, zapis, modyfikacja). 
	Menu.h/Menu.cpp � zawiera klas� i implementacj� metod, kt�rej zadaniem jest wy�wietlanie Menu oraz interpretacj� ��da� u�ytkownika.
	OptimalAlgorithm.h/OptimalAlgorithm.cpp � zawiera klas� i implementacj� metod, kt�rej zadaniem jest obliczanie ilo�ci rozwi�za� oraz wypisanie mo�liwych kombinacji patyk�w. 
	QuickSorter.h/QuickSorter.cpp � zawiera klas� i implementacj� metod, kt�rej zadaniem jest posortowanie zbioru patyk�w metod� QuickSort. 
	BruteforceTests.cpp � testy poprawno�ci algorytmu Bruteforce
	OptimalAlgorithmTests.cpp � testy poprawno�ci algorytmu optymalnego
	QuicksorterTests.cpp � testy poprawno�ci algorytmu sortowania
	dataInput.txt � domy�lnie plik zawieraj�cy zbi�r patyk�w kt�re chcemy wczyta� do programu ( Uwaga: pierwsza linijka pliku to rozmiar danych, nast�pne to d�ugo�ci patyk�w ). 
	optimalAlgorithmTime.txt -  czasy wykonania zadania dla poszczeg�lnych rozmiar�w zbior�w dla algorytmu optymalnego
	bruteforceTime.txt -  czasy wykonania zadania dla poszczeg�lnych rozmiar�w zbior�w dla algorytmu bruteforce
	rawRunningTimeData.txt � dane o czasach wykonania w postaci do analizy dla Matlaba
	main.cpp � uruchamia program
	AnalysisOfAlgorithm.m � skrypt napisany w Matlab, do przeprowadzenia analizy z�o�ono�ci. 

