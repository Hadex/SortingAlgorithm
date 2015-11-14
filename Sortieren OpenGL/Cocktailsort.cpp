#include "Include.h"

using namespace std;


Cocktailsort::Cocktailsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Cocktailsort::~Cocktailsort(){

}

void Cocktailsort::cocktailsort(vector<int>* list, int length){

	time_t elapsed;
	elapsed = clock();
	int i = 0;
	int j = length;
	while (i < j)
	{
		for (int k = i; k < j; k++)
		{
			if (list->at(k) > list->at(k + 1))
			{
				swap(list->at(k), list->at(k + 1));
			}
		}
		j--;
		for (int k = j; k > i; k--)
		{
			if (list->at(k) < list->at(k - 1))
			{
				swap(list->at(k), list->at(k - 1));
			}
		}
		i++;
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Cocktailsort::graphicCocktailsort(vector<int>* list, int length){

	int i = 0;
	int j = length;
	while (i < j)
	{
		for (int k = i; k < j; k++)
		{
			if (list->at(k) > list->at(k + 1))
			{
				swap(list->at(k), list->at(k + 1));
				graphics->redraw(k);
			}
		}
		j--;
		for (int k = j; k > i; k--)
		{
			if (list->at(k) < list->at(k - 1))
			{
				swap(list->at(k), list->at(k - 1));
				graphics->redraw(k);
			}
		}
		i++;
	}

}