#include "Include.h"

using namespace std;

void drawIndicator(vector<int>*, int, int);


DrawGraphics::DrawGraphics(GLFWwindow* window, std::vector<int>* list, float POINT_COL_RED, float POINT_COL_GREEN, float POINT_COL_BLUE, float BACK_COL_RED, float BACK_COL_GREEN, float BACK_COL_BLUE, int ARRAY_SIZE, int CHOSEN_MODE, int DRAW_DELAY){

	this->window = window;
	this->list = list;
	this->POINT_COL_RED = POINT_COL_RED;
	this->POINT_COL_GREEN = POINT_COL_GREEN;
	this->POINT_COL_BLUE = POINT_COL_BLUE;
	this->BACK_COL_RED = BACK_COL_RED;
	this->BACK_COL_GREEN = BACK_COL_GREEN;
	this->BACK_COL_BLUE = BACK_COL_BLUE;
	this->ARRAY_SIZE = ARRAY_SIZE;
	this->CHOSEN_MODE = CHOSEN_MODE;
	this->DRAW_DELAY = DRAW_DELAY;

}

DrawGraphics::~DrawGraphics(){



}

void DrawGraphics::redraw(int index){
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(BACK_COL_RED, BACK_COL_GREEN, BACK_COL_BLUE, 1);

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
				glColor3f(POINT_COL_RED, POINT_COL_GREEN, POINT_COL_BLUE);
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
				glColor3f(POINT_COL_RED, POINT_COL_GREEN, POINT_COL_BLUE);
				glBegin(CHOSEN_MODE);
					glVertex2i(i, 0);
					glVertex2i(i, list->at(i));
				glEnd();
			}
		}
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
				glColor3f(POINT_COL_RED, POINT_COL_GREEN, POINT_COL_BLUE);
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

void DrawGraphics::redraw(int* list, int index){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(BACK_COL_RED, BACK_COL_GREEN, BACK_COL_BLUE, 1);

	switch (CHOSEN_MODE)
	{
	case GL_POINTS:
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i == index)
			{
				glColor3f(1, 1, 1);
				glBegin(CHOSEN_MODE);
				glVertex2i(i, list[i]);
				glEnd();
			}
			else
			{
				glColor3f(POINT_COL_RED, POINT_COL_GREEN, POINT_COL_BLUE);
				glBegin(CHOSEN_MODE);
				glVertex2i(i, list[i]);
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
				glVertex2i(i, list[i]);
				glEnd();
			}
			else
			{
				glColor3f(POINT_COL_RED, POINT_COL_GREEN, POINT_COL_BLUE);
				glBegin(CHOSEN_MODE);
				glVertex2i(i, 0);
				glVertex2i(i, list[i]);
				glEnd();
			}
		}
		break;
	default:
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i == index)
			{
				glColor3f(1, 1, 1);
				glBegin(CHOSEN_MODE);
				glVertex2i(i, list[i]);
				glEnd();
			}
			else
			{
				glColor3f(POINT_COL_RED, POINT_COL_GREEN, POINT_COL_BLUE);
				glBegin(CHOSEN_MODE);
				glVertex2i(i, list[i]);
				glEnd();
			}
		}
		break;
	}
	glfwSwapBuffers(window);
	this_thread::sleep_for(chrono::microseconds(DRAW_DELAY));

}