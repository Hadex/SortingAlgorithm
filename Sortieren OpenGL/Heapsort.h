#ifndef _HEAPSORT_H
#define _HEAPSORT_H

#include "Include.h"


class Heapsort
{

	private:

		DrawGraphics* graphics;

	public:

		void start(std::vector<int>*, int);
		void heapsort(std::vector<int>*, int);
		void max_heapify(std::vector<int>*, int, int);
		void build_heap(std::vector<int>*, int);
		void graphicHeapsort(std::vector<int>*, int);
		void graphicMax_heapify(std::vector<int>*, int, int);
		void graphicBuild_heap(std::vector<int>*, int);

		Heapsort::Heapsort(DrawGraphics*);
		Heapsort::~Heapsort();

};

#endif