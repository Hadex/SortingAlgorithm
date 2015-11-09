#include "Include.h"

using namespace std;


Mountainsort::Mountainsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Mountainsort::~Mountainsort(){

}

void Mountainsort::mountainsort(vector<int>* list, int start, int end){

	time_t elapsed;
	elapsed = clock();
	int middle = (start + end) / 2;
	int index = start;
	while (index <= middle)
	{
		int min = index;
		for (int i = min; i <= middle; i++)
		{
			if (list->at(i) <= list->at(min))
			{
				min = i;
			}
		}
		swap(list->at(min), list->at(index));
		index++;
	}
	index = end;
	while (index > middle)
	{
		int min = middle + 1;
		for (int i = min; i <= index; i++)
		{
			if (list->at(i) <= list->at(min))
			{
				min = i;
			}
		}
		swap(list->at(min), list->at(index));		
		index--;
	}
	for (int i = start; i <= end; i++)
	{
		if (list->at(end) <= list->at(i))
		{
			int tmp = list->at(end);
			list->erase(list->end() - 1);
			list->insert(list->begin() + i, tmp);
		}
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Mountainsort::graphicMountainsort(vector<int>* list, int start, int end){

	int middle = (start + end) / 2;
	int index = start;
	while (index <= middle)
	{
		int min = index;
		for (int i = min; i <= middle; i++)
		{
			if (list->at(i) <= list->at(min))
			{
				min = i;
			}
		}
		swap(list->at(min), list->at(index));
		graphics->redraw(index);
		index++;
	}
	index = end;
	while (index > middle)
	{
		int min = middle + 1;
		for (int i = min; i <= index; i++)
		{
			if (list->at(i) <= list->at(min))
			{
				min = i;
			}
		}
		swap(list->at(min), list->at(index));
		graphics->redraw(index);
		index--;
	}
	for (int i = start; i <= end; i++)
	{
		if (list->at(end) <= list->at(i))
		{
			int tmp = list->at(end);
			list->erase(list->end() - 1);
			list->insert(list->begin() + i, tmp);
			graphics->redraw(i);
		}
	}

}