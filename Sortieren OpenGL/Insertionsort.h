#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_

#include "Include.h"


class Insertionsort
{

	private:

		DrawGraphics* graphics;

	public:

		void insertionsort(std::vector<int>*, int);
		void graphicInsertionsort(std::vector<int>*, int);

		Insertionsort(DrawGraphics*);
		~Insertionsort();

};

#endif