#ifndef _GNOMESORT_H_
#define _GNOMESORT_H_

#include "Include.h"


class Gnomesort
{

	private:

		DrawGraphics* graphics;

	public:

		void gnomesort(std::vector<int>*, int);
		void graphicGnomesort(std::vector<int>*, int);

		Gnomesort::Gnomesort(DrawGraphics*);
		Gnomesort::~Gnomesort();

};

#endif