#ifndef _MOUNTAINSORT_H_
#define _MOUNTAINSORT_H_

#include "Include.h"


class Mountainsort
{

	private:

		DrawGraphics* graphics;

	public:

		void mountainsort(std::vector<int>*, int, int);
		void graphicMountainsort(std::vector<int>*, int, int);

		Mountainsort(DrawGraphics*);
		~Mountainsort();
	
};

#endif