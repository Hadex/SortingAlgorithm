#include "Include.h"

using namespace std;


Shellsort::Shellsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Shellsort::~Shellsort(){

}

void Shellsort::shellsort(vector<int>* list, int length){
	
	time_t elapsed;
	elapsed = clock();
	int i, j, k, h, t;
	int spalten[] = { 2147483647, 1131376761, 410151271, 157840433,
		58548857, 21521774, 8810089, 3501671, 1355339, 543749, 213331,
		84801, 27901, 11969, 4711, 1968, 815, 271, 111, 41, 13, 4, 1 };

	for (k = 0; k < 23; k++)
	{
		h = spalten[k];
		for (i = h; i < length; i++)
		{
			t = list->at(i);
			j = i;
			while (j >= h && list->at(j - h) > t)
			{
				list->at(j) = list->at(j - h);
				j = j - h;
			}
			list->at(j) = t;
		}
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Shellsort::graphicShellsort(vector<int>* list, int length){

	int i, j, k, h, t;

	int spalten[] = { 2147483647, 1131376761, 410151271, 157840433,
		58548857, 21521774, 8810089, 3501671, 1355339, 543749, 213331,
		84801, 27901, 11969, 4711, 1968, 815, 271, 111, 41, 13, 4, 1 };

	for (k = 0; k < 23; k++)
	{
		h = spalten[k];
		for (i = h; i < length; i++)
		{
			t = list->at(i);
			j = i;
			while (j >= h && list->at(j - h) > t)
			{
				list->at(j) = list->at(j - h);
				graphics->redraw(j);
				j = j - h;
			}
			list->at(j) = t;
		}
	}

}