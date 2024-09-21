//<-------------------->
// 
// 
//"Hanoi tower task" solved recurcively
// 
// 
//<-------------------->

#define ERROR_MESSAGE "ERROR! Something went wrong"
#define SUM_OF_ROD_NUMBERS 6
const int NUMBER_OF_POLES = 3;//the maximum amount of poles in this task is 3 according to the task

#include <iostream>
using namespace std;

void Hanoi(int AmountOfDisks, int StartRode, int AuxiliaryRod, int DestRod);


void main()
{
	int Amount_of_disks;
	cout << "Enter the number of disks: ";
	cin >> Amount_of_disks;

	if (Amount_of_disks <= 0) {
		cout << endl << endl;
		cout << ERROR_MESSAGE << endl << endl;
		exit(1);
	}

	int StartRod;
	cout << "Enter the number of the start pole: ";
	cin >> StartRod;

	if (StartRod <= 0||StartRod > NUMBER_OF_POLES) {
		cout << endl << endl;
		cout << ERROR_MESSAGE << endl << endl;
		exit(1);
	}

	int DestRod;
	cout << "Enter the number of the end pole: ";
	cin >> DestRod;

	if (DestRod <= 0 || DestRod > NUMBER_OF_POLES) {
		cout << endl << endl;
		cout << ERROR_MESSAGE << endl << endl;
		exit(1);
	}
	//Count an auxiliary rod based on the knowledge of the sum of the numbsers of remaining rods
	int AuxiliaryRod = SUM_OF_ROD_NUMBERS-StartRod-DestRod;
	//cout << AuxiliaryRod;
	
	cout << "Salvation: " << endl << endl;
	Hanoi(Amount_of_disks, StartRod,DestRod,AuxiliaryRod);


}

void Hanoi(int AmountOfDisks,int StartRode, int DestRod,int AuxiliaryRod)
{
	if (AmountOfDisks == 1) {
		cout << "Move disk " << AmountOfDisks << " from rod " << StartRode << " to rode " << DestRod << endl;
		return;
	}

	Hanoi(AmountOfDisks - 1, StartRode, AuxiliaryRod, DestRod);
	cout << "Move disk " << AmountOfDisks << " from rode " << StartRode << " to rode " << DestRod << endl;

	Hanoi(AmountOfDisks - 1, AuxiliaryRod, DestRod, StartRode);
}