#include "Include.h"

using namespace std;


Bogosort::Bogosort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Bogosort::~Bogosort(){

}

void Bogosort::bogosort(vector<int>* list, vector<int>* ordered){

	bool done = false;
	time_t elapsed;
	elapsed = clock();
	while (!done)
	{
		random_shuffle(list->begin(), list->end());
		if (equal(list->begin(), list->end(), ordered->begin()))
		{
			done = true;
		}
	}
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void Bogosort::graphicBogosort(vector<int>* list, vector<int>* ordered){

	bool done = false;
	while (!done)
	{
		random_shuffle(list->begin(), list->end());
		graphics->redraw(rand() % list->size() + 1);
		if (equal(list->begin(), list->end(), ordered->begin()))
		{
			done = true;
		}
		this_thread::sleep_for(chrono::milliseconds(200));
	}

}