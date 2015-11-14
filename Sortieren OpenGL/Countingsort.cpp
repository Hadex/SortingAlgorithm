#include "Include.h"

using namespace std;


Countingsort::Countingsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Countingsort::~Countingsort(){

}

void Countingsort::countingsort(vector<int>* list, int length){
	
	time_t elapsed;
	elapsed = clock();
	int mi, mx, z = 0;
	findMinMax(list, length, mi, mx);
	int nlen = (mx - mi) + 1;
	int* temp = new int[nlen];
	memset(temp, 0, nlen * sizeof(int));
	for (int i = 0; i < length; i++)
	{
		temp[list->at(i) - mi]++;
	}
	for (int i = mi; i <= mx; i++)
	{
		while (temp[i - mi])
		{
			list->at(z++) = i;
			temp[i - mi]--;
		}
	}
	delete[] temp;
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Countingsort::graphicCountingsort(vector<int>* list, int length){

	int mi, mx, z = 0; 
	findMinMax(list, length, mi, mx);
	int nlen = (mx - mi) + 1; 
	int* temp = new int[nlen];
	memset(temp, 0, nlen * sizeof(int));
	for (int i = 0; i < length; i++)
	{
		temp[list->at(i) - mi]++;
	}
	for (int i = mi; i <= mx; i++)
	{
		while (temp[i - mi])
		{
			list->at(z++) = i;
			graphics->redraw(i);
			temp[i - mi]--;
		}
	}
	delete[] temp;

}

void Countingsort::findMinMax(vector<int>* list, int length, int& mi, int& mx){

	mi = INT_MAX; 
	mx = 0;
	for (int i = 0; i < length; i++)
	{
		if (list->at(i) > mx) 
			mx = list->at(i);
		if (list->at(i) < mi) 
			mi = list->at(i);
	}

}