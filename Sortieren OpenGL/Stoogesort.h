#ifndef _STOOGESORT_H_
#define _STOOGESORT_H_

#include "Include.h"


class Stoogesort
{

	private:

		DrawGraphics* graphics;

	public:

		void start(std::vector<int>*, int, int);
		void stoogesort(std::vector<int>*, int, int);
		void graphicStoogesort(std::vector<int>*, int, int);

		Stoogesort::Stoogesort(DrawGraphics*);
		Stoogesort::~Stoogesort();

};

#endif