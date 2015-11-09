#ifndef _SELECTIONSORT_H
#define _SELECTIONSORT_H

#include "Include.h"


class Selectionsort
{

	private:

		DrawGraphics* graphics;

	public:

		void selectionsort(std::vector<int>*, int);
		void graphicSelectionsort(std::vector<int>*, int);

		Selectionsort(DrawGraphics*);
		~Selectionsort();

};

#endif