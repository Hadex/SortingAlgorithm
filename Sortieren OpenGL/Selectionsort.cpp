#include "Include.h"

using namespace std;


Selectionsort::Selectionsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Selectionsort::~Selectionsort(){

}

void Selectionsort::selectionsort(vector<int>* list, int length){

	time_t elapsed;
	elapsed = clock();
	int count = 0;
	int i = 0;
	int min = 0;
	while (count < length)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (list->at(j) < list->at(min))
			{
				min = j;
			}
		}
		swap(list->at(i), list->at(min));
		i++;
		count++;
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Selectionsort::graphicSelectionsort(vector<int>* list, int length){

	int count = 0;
	int i = 0;
	int min = 0;
	while (count < length)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (list->at(j) < list->at(min))
			{
				min = j;
			}
		}
		graphics->redraw(count);
		swap(list->at(i), list->at(min));
		graphics->redraw(count);
		i++;
		count++;
	}

}