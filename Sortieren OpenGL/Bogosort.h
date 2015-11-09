#ifndef _BOGOSORT_H_
#define _BOGOSORT_H_

#include "Include.h"


class Bogosort
{

	private:

		DrawGraphics* graphics;

	public:

		void bogosort(std::vector<int>*, std::vector<int>*);
		void graphicBogosort(std::vector<int>*, std::vector<int>*);

		Bogosort(DrawGraphics*);
		~Bogosort();

};

#endif