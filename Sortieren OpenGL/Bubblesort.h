#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include "Include.h"


class Bubblesort
{

	private:

		DrawGraphics* graphics;

	public:

		void bubblesort(std::vector<int>*, int);
		void grahpicBubblesort(std::vector<int>*, int);

		Bubblesort(DrawGraphics*);
		~Bubblesort();

};

#endif