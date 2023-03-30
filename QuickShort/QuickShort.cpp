// QuickShort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

int arr[20];				//array of integers to hold velues
int cmp_count = 0;		 	//number of comparasion
int mov_count = 0; 
int n;

void input() {
	while (true)
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah: " << endl;
	}
	cout << "\n=====================" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n=====================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i]; 
	}
}

//swaps the element st index x with the element at index y
void swap(int x, int y)  
{
	int temp;
	
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high) 
{
	int pivot, i, j; 
	if (low > high)				//Langkah ALgoritma No. 1
		return;


		//partion the list into two parts:
		//one containing elements less that or equal to pivot
		//Outher conntainning elements greather than pivot

		pivot = arr[low];			//langkah Algoritma No. 2

		i = low + 1;				//Langkah Algoritma No. 3
		j = high;					//Langkah Algoritma No. 4

	while (i <= j)				//Langkah Algoritma No. 10
	{
		// search for an element greather than pivot
		while ((arr[i] <= pivot) && (i <= high)) 	//Langkah Algoritma No. 5
		{
			i++;									//Langkah Algoritma No. 6
			cmp_count++;
		}
		cmp_count++;

		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low)) 		//Langkah Algoritma No.7
		{
			j--;									//Langkah Algoritma No.8
			cmp_count++;
		}
		cmp_count++;

		// if the greater element is on the left of the element
		if (i < j)									//Langkah Algoritma No. 9
		{
			//swap the element at index i whit the element at index j
			swap(i, j);
			mov_count++; 
		}
	}
	
	// j now containt the indexx of the last element in the sorted list
	if (low < j)								//langkah algortima no 11
	{
		//move the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
		}
	// sort the list on the left of pivot using quick sort
	q_short(low, j - 1);						//langkah Algoritma No 12

	//Sort the list on the right of pivot using quick sort
	q_short(j + 1, high);						//Langkah Algoritma No 13

}

void display() {
	cout << "\n===========================" << endl;
	cout << "Sorted Array" << endl;
	cout << "============================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;

}

int main() 
{
	input();
	q_short(0, n - 1);			//sort the array using quick sort
	display();
	system("pause");

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
