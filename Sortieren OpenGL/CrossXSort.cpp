#include "Include.h"

using namespace std;


CrossXSort::CrossXSort(DrawGraphics* graphics){

	this->graphics = graphics;

}

CrossXSort::~CrossXSort(){

}

void CrossXSort::crossxsort(vector<int>* list, int length){

	

}

void CrossXSort::partition(vector<int>* list, int start, int end){
	
	

}

/*void CrossXSort::graphicBogosort(vector<int>* list, vector<int>* ordered){

	bool done = false;
	while (!done)
	{
		random_shuffle(list->begin(), list->end());
		graphics->redraw(rand() % list->size() + 1);
		if (equal(list->begin(), list->end(), ordered->begin()))
		{
			done = true;
		}
	}
	this_thread::sleep_for(chrono::milliseconds(300));

}*/