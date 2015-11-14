#ifndef _MINMAXSORT_H
#define _MINMAXSORT_H

#include "Include.h"


class Minmaxsort
{

	private:

		DrawGraphics* graphics;

	public:

		void minmaxsort(std::vector<int>*, int, int);
		void graphicMinmaxsort(std::vector<int>*, int, int);

		Minmaxsort::Minmaxsort(DrawGraphics*);
		Minmaxsort::~Minmaxsort();

};

#endif