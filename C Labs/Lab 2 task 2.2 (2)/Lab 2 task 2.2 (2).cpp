#include <cstdlib>
#include <string.h>
#include <cstdio>
using namespace std;

int firstNum, firstDen, secondNum, secondDen;
int numAddition, denAddition;

void enter(int& firstNum, int& firstDen, int& secondNum, int& secondDen);
void output(int& firstNum, int& firstDen, int& secondNum, int& secondDen);
void addition(int& firstNum, int& firstDen, int& secondNum, int& secondDen);
void subtraction(int firstNum, int firstDen, int secondNum, int secondDen)

void cancellation();

int main()
{
	int menuPoint;

	do
	{
		printf("\n*****Menu*****\n");
		printf("\n1 - Enter two rational number\n2 - Output rational numbers\n3 - Addition\n4 - Subtraction\n5 - Multiplication\n6 - Division\n7 - Harmonic value\n8 - Information\n9 - Exit\n\n");
		scanf_s("%d", &menuPoint);
		switch (menuPoint)
		{
		case 1:enter(firstNum, firstDen, secondNum, secondDen);
			break;
		case 2:output(firstNum, firstDen, secondNum, secondDen);
			break;
		case 3:addition(firstNum, firstDen, secondNum, secondDen);
			break;
		case 4:subtraction(firstNum, firstDen, secondNum, secondDen);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:exit(0);
		default:printf("\nError\n\n\n");
			break;
		}
	} while (menuPoint);

	printf("\nfirstNum == %d\n", firstNum);
	printf("firstDen == %d\n", firstDen);
	printf("secondNum == %d\n", secondNum);
	printf("secondDen == %d\n", secondDen);

	//sum(n, m);
}

void enter(int& firstNum, int& firstDen, int& secondNum, int& secondDen)
{
	printf("Enter numerator of first rational number: ");
	scanf_s("%d", &firstNum);

	printf("Enter denomerator of first rational number: ");
	scanf_s("%d", &firstDen);


	printf("Enter numerator of second rational number: ");
	scanf_s("%d", &secondNum);

	printf("Enter denomerator of second rational number: ");
	scanf_s("%d", &secondDen);

	printf("\n\n");
}

void output(int& firstNum, int& firstDen, int& secondNum, int& secondDen)
{
	printf("\nFirst rational number: %d / %d\n", firstNum, firstDen); 
	printf("\nSecond rational number: %d / %d\n", secondNum, secondDen);
}

void addition(int& firstNum, int& firstDen, int& secondNum, int& secondDen)
{
	numAddition = firstNum * secondDen + firstDen * secondNum;
	denAddition = firstDen * secondDen;

	cancellation();

	printf("\nCancellation = %d / %d\n", numAddition, denAddition);
}

void subtraction(int firstNum, int firstDen, int secondNum, int secondDen)
{
	
}



void cancellation()//Сокращение дроби
{
	int zn = 1;
	if (numAddition < 0)
		zn = -1;
	for (int i = 2; i <= zn * numAddition; i++)
		if (!(numAddition % i) && !(denAddition % i))
		{
			numAddition /= i;
			denAddition /= i;
		}
}