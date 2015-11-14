#ifndef _PIGEONHOLESORT_H_
#define _PIGEONHOLESORT_H_

#include "Include.h"


class Pigeonholesort
{

	private:

		DrawGraphics* graphics;

	public:

		void pigeonholesort(std::vector<int>*, int);
		void graphicPigeonholesort(std::vector<int>*, int);

		Pigeonholesort::Pigeonholesort(DrawGraphics*);
		Pigeonholesort::~Pigeonholesort();
	
};

#endif