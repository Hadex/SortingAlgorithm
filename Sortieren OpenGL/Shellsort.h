#ifndef _SHELLSORT_H
#define _SHELLSORT_H

#include "Include.h"


class Shellsort
{

	private:

		DrawGraphics* graphics;

	public:

		void shellsort(std::vector<int>*, int);
		void graphicShellsort(std::vector<int>*, int);

		Shellsort::Shellsort(DrawGraphics*);
		Shellsort::~Shellsort();

};

#endif