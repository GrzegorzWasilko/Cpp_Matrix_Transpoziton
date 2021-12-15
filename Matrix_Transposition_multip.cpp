/*  Dana jest prostokątna macierz X, zawierająca liczby całkowite, składająca się z m wierszy i n kolumn.
Liczba wierszy i kolumn jest nie większa niż 100.

Należy napisać program, który znajdzie iloczyn macierzy XTX.

Wejście
W pierwszej linii wejścia znajduje się liczba całkowita m ∈ [1;100] określająca liczbę wierszy macierzy X.
W drugiej linii wejścia znajduje się liczba całkowita n ∈ [1;100] określająca liczbę kolumn macierzy X. W
kolejnych m liniach znajduje się po n liczb całkowitych, z przedziału [-100;100],
oddzielonych spacją określających elementy macierzy X.

Wyjście
Na wyjściu należy wypisać macierz wynikową XTX. */
/*
Przykład
Wejście:

5
3
1 0 1
3 0 4
2 1 -1
4 3 2
-4 3 3
Wyjście:

46 2 7
2 19 14
7 14 31 */

#include <iostream>

using namespace std;
int main() {
	int m, n, z, p; //m - wiersze, n - kolumny
	cin >> m >> n;
	int** tab = new int* [m];

	for (int i = 0; i < m; i++) {
		tab[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tab[i][j];
		}
	}

	int** tabT = new int* [n];
	for (int i = 0; i < n; i++) {
		tabT[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tabT[j][i] = tab[i][j];
		}
	}

	int** Matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		Matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Matrix[i][j] = 0;
		}
	}
	//====== Mulltip Matrix_T * Matrix =======
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = 0;
			for (int p = 0; p < m; p++) {
				x += tabT[i][p] * tab[p][j];
				Matrix[i][j] = x;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Matrix[i][j];
		}
		cout << endl;
	}

	//======= D E L E T E ===========
	for (int i = 0; i < m; i++) {
		delete[] tab[i];
	}
	delete[] tab;

	for (int i = 0; i < n; i++) {
		delete[] tabT[i];
	}
	delete[] tabT;

	for (int i = 0; i < n; i++) {
		delete[] Matrix[i];
	}
	delete[] Matrix;
	return 0;
}


