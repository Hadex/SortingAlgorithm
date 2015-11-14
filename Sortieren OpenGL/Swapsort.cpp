#include "Include.h"

using namespace std;


Swapsort::Swapsort(DrawGraphics* graphics){

	this->graphics = graphics;

}

Swapsort::~Swapsort(){

}

void Swapsort::graphicSwapsort(vector<int>* list, int length){

	//=======================================
	//==  !Funktioniert nur bei |n| +- 0!  ==
	//=======================================
	int i = 0;
	while (i < length)
	{
		int j = 0;
		for (int a = i + 1; a < length; a++)
		{
			if (list->at(i) >= list->at(a))
			{
				j++;
			}
		}
		if (j > 0)
		{
			swap(list->at(i), list->at(i + j));
			graphics->redraw(i);
		}
		else
		{
			i++;
		}
	}
	
}