#include "Include.h"

using namespace std;


Insertionsort::Insertionsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Insertionsort::~Insertionsort(){
	
}

void Insertionsort::insertionsort(vector<int>* list, int length){

	time_t elapsed;
	elapsed = clock();
	int count = 0;
	int a = 1;
	while (count < length)
	{
		int i = a;
		for (int j = i - 1; j >= 0; j--)
		{
			if (list->at(i) < list->at(j))
			{
				swap(list->at(i), list->at(j));
				i--;
			}
		}
		a++;
		count++;
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Insertionsort::graphicInsertionsort(vector<int>* list, int length){

	int count = 0;
	int a = 1;
	while (count < length)
	{
		graphics->redraw(a);
		int i = a;
		for (int j = i - 1; j >= 0; j--)
		{
			if (list->at(i) < list->at(j))
			{
				swap(list->at(i), list->at(j));
				graphics->redraw(a);
				i--;
			}
		}
		count++;
		a++;
		
	}

}