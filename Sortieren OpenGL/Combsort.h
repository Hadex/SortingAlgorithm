#ifndef _COMBSORT_H
#define _COMBSORT_H

#include "Include.h"


class Combsort
{

	private:

		DrawGraphics* graphics;

	public:

		void combsort(std::vector<int>*, int);
		void graphicCombsort(std::vector<int>*, int);

		Combsort::Combsort(DrawGraphics*);
		Combsort::~Combsort();

};

#endif