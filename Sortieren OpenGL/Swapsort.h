#ifndef _SWAPSORT_H
#define _SWAPSORT_H

#include "Include.h"


class Swapsort
{

	private:

		DrawGraphics* graphics;

	public:

		void graphicSwapsort(std::vector<int>*, int);

		Swapsort::Swapsort(DrawGraphics*);
		Swapsort::~Swapsort();

};

#endif