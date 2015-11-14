#include "Include.h"

using namespace std;


Pigeonholesort::Pigeonholesort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Pigeonholesort::~Pigeonholesort(){

}

void Pigeonholesort::pigeonholesort(vector<int>* list, int length){

	time_t elapsed;
	elapsed = clock();
	int min = list->at(0);
	int max = list->at(0);
	for (int i = 0; i < length; i++)
	{
		if (list->at(i) < min)
		{
			min = list->at(i);
		}
		if (list->at(i) > max)
		{
			max = list->at(i);
		}
	}
	int* a = list->data();
	int size, count = 0, i;
	int *current;
	current = a;
	size = max - min + 1;
	int *holes = new int[size];
	for (i = 0; i < size; i++)
	{
		holes[i] = 0;
	}
	for (i = 0; i < size; i++, current++)
	{
		holes[*current - min] += 1;
	}
	for (count = 0, current = &a[0]; count < size; count++)
	{
		while (holes[count]--> 0)
		{
			*current++ = count + min;
		}
	}
	delete holes;
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Pigeonholesort::graphicPigeonholesort(vector<int>* list, int length){

	int min = list->at(0);
	int max = list->at(0);
	for (int i = 0; i < length; i++)
	{
		if (list->at(i) < min)
		{
			min = list->at(i);
		}
		if (list->at(i) > max)
		{
			max = list->at(i);
		}
	}
	int* a = list->data();
	int size, count = 0, i;
	int *current;
	current = a;
	size = max - min + 1;
	int *holes = new int[size];
	for (i = 0; i < size; i++)
	{
		holes[i] = 0;
	}
	for (i = 0; i < size; i++, current++)
	{
		holes[*current - min] += 1;
	}
	for (count = 0, current = &a[0]; count < size; count++)
	{
		while (holes[count]--> 0)
		{
			*current++ = count + min;
			graphics->redraw(*current);
		}
	}
	delete holes;

}