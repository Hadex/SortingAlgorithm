#ifndef _CROSSXSORT_H_
#define _CROSSXSORT_H_

#include "Include.h"


class CrossXSort
{

private:

	DrawGraphics* graphics;

public:

	void start(std::vector<int>*, int, int);
	void crossxsort(std::vector<int>*, int, int);
	int partition(std::vector<int>*, int, int);
	void graphicCrossxsort(std::vector<int>*, int, int);
	int graphicPartition(std::vector<int>*, int, int);

	CrossXSort(DrawGraphics*);
	~CrossXSort();

};

#endif