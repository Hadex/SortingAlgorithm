#ifndef _COUNTINGSORT_H_
#define _COUNTINGSORT_H_

#include "Include.h"


class Countingsort
{

	private:

		DrawGraphics* graphics;

	public:

		void countingsort(std::vector<int>*, int);
		void graphicCountingsort(std::vector<int>*, int);
		void findMinMax(std::vector<int>*, int, int&, int&);

		Countingsort::Countingsort(DrawGraphics*);
		Countingsort::~Countingsort();

};

#endif