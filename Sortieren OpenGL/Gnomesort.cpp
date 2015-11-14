#include "Include.h"

using namespace std;


Gnomesort::Gnomesort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Gnomesort::~Gnomesort(){

}

void Gnomesort::gnomesort(vector<int>* list, int length){
	
	time_t elapsed;
	elapsed = clock();
	for (int i = 1; i < length;)
	{
		if (list->at(i - 1) <= list->at(i))
		{
			i++;
		}
		else
		{
			swap(list->at(i - 1), list->at(i));
			i--;
			if (i == 0)
			{
				i = 1;
			}
		}
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Gnomesort::graphicGnomesort(vector<int>* list, int length){

	for (int i = 1; i < length; )
	{
		if (list->at(i - 1) <= list->at(i)) 
		{
			i++;
		}
		else 
		{
			swap(list->at(i - 1), list->at(i));
			graphics->redraw(i);
			i--;
			if (i == 0) 
			{
				i = 1;
			}
		}
	}

}