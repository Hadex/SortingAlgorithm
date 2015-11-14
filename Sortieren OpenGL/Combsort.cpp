#include "Include.h"

using namespace std;


Combsort::Combsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Combsort::~Combsort(){

}

void Combsort::combsort(vector<int>* list, int length){

	time_t elapsed;
	elapsed = clock();
	int j = length;
	bool changed = false;
	do
	{
		changed = false;
		if (j > 1)
		{
			j = floor(j / 1.3);
		}
		for (int i = 0; i < length - j; i++)
		{
			if (list->at(i) > list->at(i + j))
			{
				swap(list->at(i), list->at(i + j));
				changed = true;
			}
		}
	} while (changed == true || j > 1);
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Combsort::graphicCombsort(vector<int>* list, int length){

	int j = length;
	bool changed = false;
	do
	{
		changed = false;
		if (j > 1)
		{
			j = floor(j / 1.3);
		}
		for (int i = 0; i < length - j; i++)
		{
			if (list->at(i) > list->at(i + j))
			{
				swap(list->at(i), list->at(i + j));
				graphics->redraw(i);
				changed = true;
			}
		}
	} while (changed == true || j > 1);

}