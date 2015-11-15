#ifndef _DRAWGRAPHICS_H_
#define _DRAWGRAPHICS_H_

#include "Include.h"


class DrawGraphics
{

	private:

		std::vector<int>* list;
		GLFWwindow* window;
		int CHOSEN_MODE;
		int ARRAY_SIZE;
		float POINT_COL_RED;
		float POINT_COL_GREEN;
		float POINT_COL_BLUE;
		float BACK_COL_RED;
		float BACK_COL_GREEN;
		float BACK_COL_BLUE;
		int DRAW_DELAY;

	public:

		void redraw(int);
		void redraw(int*, int);

		DrawGraphics(GLFWwindow*, std::vector<int>*, float, float, float, float, float, float, int, int, int);
		~DrawGraphics();

};

#endif