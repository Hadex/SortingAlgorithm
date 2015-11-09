#include "Include.h"

using namespace std;


Mergesort::Mergesort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Mergesort::~Mergesort(){

}

void Mergesort::start(vector<int>* list, int length, int start, int end, int mode){

	if (mode == 0)
	{
		time_t elapsed;
		elapsed = clock();
		mergesort(list, length, start, end);
		elapsed = clock() - elapsed;
		cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";
	}
	else
	{
		graphicMergesort(list, length, start, end);
	}

}

void Mergesort::mergesort(vector<int>* list, int length, int start, int end){

	if (start < end)
	{
		int middle = (start + end) / 2;
		mergesort(list, length, start, middle);
		mergesort(list, length, middle + 1, end);
		merge(list, length, start, middle, end);
	}

}

void Mergesort::merge(vector<int>* list, int length, int start, int middle, int end){

	vector<int>* tmp = new vector<int>(length + 1, 0);
	for (int i = start; i <= end; i++)
	{
		tmp->at(i) = list->at(i);
	}
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= end)
	{
		if (tmp->at(i) <= tmp->at(j))
		{
			list->at(k) = tmp->at(i);
			i++;
		}
		else
		{
			list->at(k) = tmp->at(j);
			j++;
		}
		k++;
	}
	while (i <= middle)
	{
		list->at(k) = tmp->at(i);
		k++;
		i++;
	}
	delete tmp;

}

void Mergesort::graphicMergesort(vector<int>* list, int length, int start, int end){

	if (start < end)
	{
		int middle = (start + end) / 2;
		graphicMergesort(list, length, start, middle);
		graphicMergesort(list, length, middle + 1, end);
		graphicMerge(list, length, start, middle, end);
	}

}

void Mergesort::graphicMerge(vector<int>* list, int length, int start, int middle, int end){

	vector<int>* tmp = new vector<int>(length + 1, 0);
	for (int i = start; i <= end; i++)
	{
		tmp->at(i) = list->at(i);
	}
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= end)
	{
		if (tmp->at(i) <= tmp->at(j))
		{
			list->at(k) = tmp->at(i);
			graphics->redraw(k);
			i++;
		}
		else
		{
			list->at(k) = tmp->at(j);
			graphics->redraw(k);
			j++;
		}
		k++;
	}
	while (i <= middle)
	{
		list->at(k) = tmp->at(i);
		graphics->redraw(k);
		k++;
		i++;
	}
	delete tmp;

}