#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include "Include.h"


class Quicksort
{

	private:

		DrawGraphics* graphics;

	public:

		void start(std::vector<int>*, int, int, int);
		void quicksort(std::vector<int>*, int, int);
		void graphicQuicksort(std::vector<int>*, int, int);
		int partition(std::vector<int>*, int, int);
		int graphicPartition(std::vector<int>*, int, int);

		Quicksort(DrawGraphics*);
		~Quicksort();

};

#endif