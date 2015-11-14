#include "Include.h"

using namespace std;


Stoogesort::Stoogesort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Stoogesort::~Stoogesort(){

}

void Stoogesort::start(vector<int>* list, int start, int end){

	time_t elapsed;
	elapsed = clock();
	stoogesort(list, start, end);
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Stoogesort::stoogesort(vector<int>* list, int start, int end){

	if (list->at(end - 1) < list->at(start))
	{
		swap(list->at(start), list->at(end - 1));
	}
	int len = end - start;
	if (len > 2)
	{
		int third = len / 3;  
		stoogesort(list, start, end - third);
		stoogesort(list, start + third, end);
		stoogesort(list, start, end - third);
	}

}

void Stoogesort::graphicStoogesort(vector<int>* list, int start, int end){

	if (list->at(end - 1) < list->at(start))
	{
		swap(list->at(start), list->at(end - 1));
		graphics->redraw(start);
	}
	int len = end - start;
	if (len > 2)
	{
		int third = len / 3;
		graphicStoogesort(list, start, end - third);
		graphicStoogesort(list, start + third, end);
		graphicStoogesort(list, start, end - third);
	}

}