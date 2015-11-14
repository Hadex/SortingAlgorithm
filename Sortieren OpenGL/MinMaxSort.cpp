#include "Include.h"

using namespace std;


Minmaxsort::Minmaxsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Minmaxsort::~Minmaxsort(){

}

void Minmaxsort::minmaxsort(vector<int>* list, int start, int end){

	time_t elapsed;
	elapsed = clock();
	while (start < end) 
	{
		int min = 0;
		int max = 0;
		bool started = false;
		for (int i = start; i <= end; ++i) 
		{
			if (!started) 
			{
				min = i;
				max = i;
				started = true;
			}
			else 
			{
				if (list->at(i) < list->at(min)) 
				{
					min = i;
				}
				else if (list->at(i) > list->at(max)) 
				{
					max = i;
				}
			}
		}
		if (max == start && min == end) 
		{
			swap(list->at(max), list->at(min));
		}
		else if (max == start) 
		{
			swap(list->at(max), list->at(end));
			swap(list->at(min), list->at(start));
		}
		else 
		{
			swap(list->at(min), list->at(start));
			swap(list->at(max), list->at(end));
		}
		++start;
		--end;
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Minmaxsort::graphicMinmaxsort(vector<int>* list, int start, int end){
	
	while (start < end) 
	{
		int min = 0;
		int max = 0;
		bool started = false;
		for (int i = start; i <= end; ++i) 
		{
			if (!started) 
			{
				min = i;
				max = i;
				started = true;
			}
			else 
			{
				if (list->at(i) < list->at(min)) 
				{
					min = i;
				}
				else if (list->at(i) > list->at(max)) 
				{
					max = i;
				}
			}
		}
		if (max == start && min == end) 
		{
			swap(list->at(max), list->at(min));
		}
		else if (max == start) 
		{
			swap(list->at(max), list->at(end));
			swap(list->at(min), list->at(start));
		}
		else 
		{
			swap(list->at(min), list->at(start));
			swap(list->at(max), list->at(end));
		}
		graphics->redraw(start);
		++start;
		--end;
	}

}