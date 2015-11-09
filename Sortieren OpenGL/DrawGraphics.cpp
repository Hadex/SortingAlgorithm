#include "Include.h"

using namespace std;

void drawIndicator(vector<int>*, int, int);


DrawGraphics::DrawGraphics(GLFWwindow* window, std::vector<int>* list, float COL_RED, float COL_GREEN, float COL_BLUE, int ARRAY_SIZE, int CHOSEN_MODE, int DRAW_DELAY){

	this->window = window;
	this->list = list;
	this->COL_RED = COL_RED;
	this->COL_GREEN = COL_GREEN;
	this->COL_BLUE = COL_BLUE;
	this->ARRAY_SIZE = ARRAY_SIZE;
	this->CHOSEN_MODE = CHOSEN_MODE;
	this->DRAW_DELAY = DRAW_DELAY;

}

DrawGraphics::~DrawGraphics(){



}

void DrawGraphics::redraw(int index){
	
	glClear(GL_COLOR_BUFFER_BIT);

	switch (CHOSEN_MODE)
	{
	case GL_POINTS:
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i == index)
			{
				glColor3f(1, 1, 1);
				glBegin(CHOSEN_MODE);
					glVertex2i(i, list->at(i));
				glEnd();
			}
			else
			{
				glColor3f(COL_RED, COL_GREEN, COL_BLUE);
				glBegin(CHOSEN_MODE);
					glVertex2i(i, list->at(i));
				glEnd();
			}
		}
		break;
	case GL_LINES:
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i == index)
			{
				glColor3f(1, 1, 1);
				glBegin(CHOSEN_MODE);
					glVertex2i(i, 0);
					glVertex2i(i, list->at(i));
				glEnd();
			}
			else
			{
				glColor3f(COL_RED, COL_GREEN, COL_BLUE);
				glBegin(CHOSEN_MODE);
					glVertex2i(i, 0);
					glVertex2i(i, list->at(i));
				glEnd();
			}
		}
		break;
	case GL_QUADS:

		break;
	default:
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i == index)
			{
				glColor3f(1, 1, 1);
				glBegin(CHOSEN_MODE);
					glVertex2i(i, list->at(i));
				glEnd();
			}
			else
			{
				glColor3f(COL_RED, COL_GREEN, COL_BLUE);
				glBegin(CHOSEN_MODE);
					glVertex2i(i, list->at(i));
				glEnd();
			}
		}
		break;
	}
	glfwSwapBuffers(window);
	this_thread::sleep_for(chrono::microseconds(DRAW_DELAY));

}