#ifndef _MERGESORT_H
#define _MERGESORT_H

#include "Include.h"


class Mergesort
{

	private:

		DrawGraphics* graphics;

	public:

		void start(std::vector<int>*, int, int, int, int);
		void mergesort(std::vector<int>*, int, int, int);
		void merge(std::vector<int>*, int, int, int, int);
		void graphicMergesort(std::vector<int>*, int, int, int);
		void graphicMerge(std::vector<int>*, int, int, int, int);

		Mergesort(DrawGraphics*);
		~Mergesort();

};

#endif