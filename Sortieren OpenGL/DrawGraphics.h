#ifndef _DRAWGRAPHICS_H_
#define _DRAWGRAPHICS_H_

#include "Include.h"


class DrawGraphics
{

	private:

		GLFWwindow* window;
		std::vector<int>* list;
		int CHOSEN_MODE;
		int ARRAY_SIZE;
		float COL_RED;
		float COL_GREEN;
		float COL_BLUE;
		int DRAW_DELAY;

	public:

		void redraw(int);

		DrawGraphics(GLFWwindow*, std::vector<int>*, float, float, float, int, int, int);
		~DrawGraphics();

};

#endif