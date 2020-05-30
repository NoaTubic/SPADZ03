#include <iostream>
#include <Windows.h>
using namespace std;

struct pixel {
	int x;
	int y;
	int w;

	pixel(int x, int y, int w) {
		this->x = x;
		this->y = y;
		this->w = w;
	}
};

int main() {
	char twoDimArray[20][40];
	pixel pStart(0, 0, 0), pDest(0, 0, 0), pCount(0, 0, 0);

	cout << "A(x): ";
	cin >> pStart.x;
	cout << "A(y): ";
	cin >> pStart.y;
	cout << "B(x): ";
	cin >> pDest.x;
	cout << "B(y): ";
	cin >> pDest.y;

	cout << "Points overview: " << endl;

	for (unsigned int i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 40; j++)
		{
			if (j == pStart.x && i == pStart.y)
			{
				cout << "A";
				twoDimArray[i][j] = 'A';
			}

			else if (j == pDest.x && i == pDest.y)
			{
				cout << "B";
				twoDimArray[i][j] = 'B';
			}
			else
			{
				cout << "-";
			}

		}
		cout << endl;
	}
	/*calculate complexity for every pixel and save coordinates in struct*/
	unsigned short int sum = 0;
	for (unsigned i = pStart.x; i <= pDest.x; i++) {
		for (unsigned j = pStart.y; j <= pDest.y; j++) {
			sum = 0;
			sum += (i - pStart.x); sum += (j - pStart.y);
			pCount.x = i;
			pCount.y = j;
			pCount.w = sum;
		}
	}

	/*Steps needed*/
	pCount.x = pDest.x - pStart.x;
	pCount.y = pDest.y - pStart.y;
	cout << "Steps on X axis: " << pCount.x << endl;
	cout << "Steps on Y axis: " << pCount.y << endl;
	cout << "\n\n" << endl;
	cout << "\t\tPrint path\t\t" << endl;
	cout << "===================================================" << endl;
	/*Drawing the fastest route*/

	/*
	A
		B
	*/
	if (pCount.x > 0 && pCount.y > 0) {
		//row
		for (int i = pStart.x; i < pDest.x; i++) {
			twoDimArray[pDest.y][i] = 'X';
		}

		//column
		for (int i = pStart.y + 1; i <= pDest.y; i++) {
			twoDimArray[i][pStart.x] = 'X';
		}
	}

	/*
		B
	A
	*/
	else if (pCount.x > 0 && pCount.y < 0) {
		//row
		for (int i = pStart.x; i < pDest.x; i++) {
			twoDimArray[pDest.y][i] = 'X';
		}

		//column
		for (int i = pStart.y - 1; i >= pDest.y; i--) {
			twoDimArray[i][pStart.x] = 'X';
		}
	}

	/*
	B
		A
	*/

	else if (pCount.x < 0 && pCount.y < 0) {
		//row
		for (int i = pDest.x + 1; i <= pStart.x; i++) {
			twoDimArray[pDest.y][i] = 'X';
		}

		//column
		for (int i = pDest.y + 1; i < pStart.y; i++) {
			twoDimArray[i][pStart.x] = 'X';
		}
	}

	/*
		B
	A
	*/
	else if (pCount.x < 0 && pCount.y > 0) {
		//row
		for (int i = pDest.x; i < pStart.x; i++) {
			twoDimArray[pStart.y][i] = 'X';
		}
		//column
		for (int i = pStart.y; i < pDest.y; i++) {
			twoDimArray[i][pDest.x] = 'X';
		}
	}

	/*
	A	B
	*/
	else if (pCount.y == 0 && pCount.x > 0) {
		//row
		for (int i = pStart.x + 1; i < pDest.x; i++) {
			twoDimArray[pStart.y][i] = 'X';
		}
	}

	/*
	B	A
	*/
	else if (pCount.y == 0 && pCount.x < 0) {
		//row
		for (int i = pDest.x + 1; i < pStart.x; i++) {
			twoDimArray[pDest.y][i] = 'X';
		}
	}

	/*
	A
	B
	*/
	else if (pCount.x == 0 && pCount.y > 0) {
		for (int i = pStart.y + 1; i < pDest.y; i++) {
			twoDimArray[i][pStart.x] = 'X';
		}
	}

	/*
	B
	A
	*/
	else {
		for (int i = pDest.y + 1; i < pStart.y; i++) {
			twoDimArray[i][pStart.x] = 'X';
		}
	}

	for (unsigned short int i = 0; i < 20; i++) {
		for (unsigned short int j = 0; j < 40; j++) {
			cout << twoDimArray[i][j];
		}
		cout << endl;
	}



	return 0;
}