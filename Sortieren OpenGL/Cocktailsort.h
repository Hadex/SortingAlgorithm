#ifndef _COCKTAILSORT_H_
#define _COCKTAILSORT_H_

#include "Include.h"


class Cocktailsort
{

	private:

		DrawGraphics* graphics;

	public:

		void cocktailsort(std::vector<int>*, int);
		void graphicCocktailsort(std::vector<int>*, int);

		Cocktailsort::Cocktailsort(DrawGraphics*);
		Cocktailsort::~Cocktailsort();

};

#endif