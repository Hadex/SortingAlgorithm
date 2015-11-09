#ifndef _CROSSXSORT_H_
#define _CROSSXSORT_H_

#include "Include.h"


class CrossXSort
{

private:

	DrawGraphics* graphics;

public:

	void crossxsort(std::vector<int>*, int);
	void partition(std::vector<int>*, int, int);
	void graphicCrossxsort(std::vector<int>*, int);
	void graphicPartition(std::vector<int>*, int, int);

	CrossXSort(DrawGraphics*);
	~CrossXSort();

};

#endif