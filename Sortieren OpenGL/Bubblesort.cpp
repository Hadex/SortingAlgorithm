#include "Include.h"

using namespace std;


Bubblesort::Bubblesort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Bubblesort::~Bubblesort(){
	
}

void Bubblesort::bubblesort(vector<int>* list, int length){

	time_t elapsed;
	elapsed = clock();
	int count = 0;
	int i = 0;
	int j = 1;
	while (count < length)
	{
		if (i == length)
		{
			count++;
			i = 0;
			j = 1;
		}
		if (list->at(j) < list->at(i))
		{
			swap(list->at(i), list->at(j));
			i++;
			j++;
		}
		else 
		{
			i++;
			j++;
		}
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Bubblesort::grahpicBubblesort(vector<int>* list, int length){

	int count = 0;
	int i = 0;
	int j = 1;
	while (count < length)
	{
		if (i == length)
		{
			count++;
			i = 0;
			j = 1;
		}
		if (list->at(j) < list->at(i))
		{
			swap(list->at(i), list->at(j));
			graphics->redraw((length + 1) - count);
			i++;
			j++;
		}
		else
		{
			i++;
			j++;
		}
		graphics->redraw((length + 1) - count);
	}

}