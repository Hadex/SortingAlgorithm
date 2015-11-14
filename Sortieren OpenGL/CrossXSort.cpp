#include "Include.h"

using namespace std;


CrossXSort::CrossXSort(DrawGraphics* graphics){

	this->graphics = graphics;

}

CrossXSort::~CrossXSort(){

}

void CrossXSort::start(vector<int>* list, int start, int end){

	time_t elapsed;
	elapsed = clock();
	crossxsort(list, start, end);
	elapsed = clock() - elapsed;
	cout << "Das sortieren dauerte: " << (float)elapsed / CLOCKS_PER_SEC << " Sekunden.";

}

void CrossXSort::crossxsort(vector<int>* list, int start, int end){

	if (start < end)
	{
		int l = partition(list, start, end);
		crossxsort(list, start, l - 1);
		crossxsort(list, l, end - 1);
	}

}

int CrossXSort::partition(vector<int>* list, int start, int end){
	
	int max = 0;
	int min = 0;
	int mid = 0;
	for (int i = 0; i < end; i++)
	{
		if (list->at(i) > list->at(max))
		{
			max = i;
		}
		if (list->at(i) < list->at(min))
		{
			min = i;
		}
	}
	mid = (list->at(max) + list->at(min)) / 2;
	for (int i = 1; i < end / 2; i++)
	{
		if (list->at(i) < mid)
		{
			swap(list->at(i), list->at(i));
		}
		if (list->at(i) > mid)
		{
			swap(list->at(i), list->at(end - i));
		}
	}
	return end / 2;

}

void CrossXSort::graphicCrossxsort(vector<int>* list, int start, int end){

	if (start < end)
	{
		int l = graphicPartition(list, start, end);
		graphicCrossxsort(list, start, l - 1);
		graphicCrossxsort(list, l, end - 1);
	}

}

int CrossXSort::graphicPartition(vector<int>* list, int start, int end){

	int max = 0;
	int min = 0;
	int mid = 0;
	for (int i = 0; i < end; i++)
	{
		if (list->at(i) > list->at(max))
		{
			max = i;
		}
		if (list->at(i) < list->at(min))
		{
			min = i;
		}
	}
	swap(list->at(max), list->at(end));
	swap(list->at(min), list->at(0));
	mid = (list->at(max) + list->at(min)) / 2;
	for (int i = 1; i < end / 2; i++)
	{
		if (list->at(i) < mid)
		{
			swap(list->at(i), list->at(i));
			graphics->redraw(i);
		}
		if (list->at(i) > mid)
		{
			swap(list->at(i), list->at(end - i));
			graphics->redraw(i);
		}
	}
	return end / 2;

}