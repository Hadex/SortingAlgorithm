#define GLFW_INCLUDE_GLU
#include "Include.h"

using namespace std;

void start();
void setupGL();
void startSort(int);

Quicksort* quicksort;
Bubblesort* bubblesort;
Insertionsort* insertionsort;
Selectionsort* selectionsort;
Mergesort* mergesort;
Bogosort* bogosort;
Mountainsort* mountainsort;
CrossXSort* crossxsort;

GLFWwindow* window;
vector<int>* list1;
vector<int>* list2;
vector<int>* list3;

bool done = false;
bool deleted = false;
int SORT_MODE = 1;
int DRAW_MODE = 1;
int ARRAY_SIZE = 1;
int MAX_VALUE = 0;
float DRAW_DELAY = 0;
float COL_RED = 0;
float COL_GREEN = 0;
float COL_BLUE = 0;
int POINT_COLOR = 0xFF0000;
float WIDTH_SCALE = 1.0f;

int main()
{

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(1024, 768, "Sortierverfahren", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	start();
	setupGL();
	
	list1 = new vector<int>(ARRAY_SIZE);
	list2 = new vector<int>(ARRAY_SIZE);
	list3 = new vector<int>(ARRAY_SIZE);

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		list1->at(i) = rand() % MAX_VALUE + 1;
	}
	copy(list1->begin(), list1->end(), list2->begin());
	copy(list1->begin(), list1->end(), list3->begin());

	DrawGraphics* graphics = new DrawGraphics(window, list2, COL_RED, COL_GREEN, COL_BLUE, ARRAY_SIZE, DRAW_MODE, DRAW_DELAY);

	quicksort = new Quicksort(graphics);
	bubblesort = new Bubblesort(graphics);
	insertionsort = new Insertionsort(graphics);
	selectionsort = new Selectionsort(graphics);
	mergesort = new Mergesort(graphics);
	bogosort = new Bogosort(graphics);
	mountainsort = new Mountainsort(graphics);
	crossxsort = new CrossXSort(graphics);

	glfwSwapInterval(60);

	while (!glfwWindowShouldClose(window))
	{
		if (!done)
		{
			thread t(startSort, SORT_MODE);
			switch (SORT_MODE)
			{
			case 1:
				quicksort->start(list2, 0, ARRAY_SIZE - 1, 1);
				break;
			case 2:
				bubblesort->grahpicBubblesort(list2, ARRAY_SIZE - 1);
				break;
			case 3:
				insertionsort->graphicInsertionsort(list2, ARRAY_SIZE - 1);
				break;
			case 4:
				selectionsort->graphicSelectionsort(list2, ARRAY_SIZE - 1);
				break;
			case 5:
				mergesort->start(list2, ARRAY_SIZE - 1, 0, ARRAY_SIZE - 1, 1);
				break;
			case 6:
				bogosort->graphicBogosort(list2, list1);
				break;
			case 7:
				mountainsort->graphicMountainsort(list2, 0, ARRAY_SIZE - 1);
				break;
			case 8:
				crossxsort->crossxsort(list2, ARRAY_SIZE - 1);
				break;
			default:
				break;
			}
			t.join();
			done = true;

		}
		if (done && !deleted){

			delete list1;
			delete list2;
			delete list3;
			delete graphics;
			delete quicksort;
			delete bubblesort;
			delete insertionsort;
			delete selectionsort;
			delete mergesort;
			delete bogosort;
			delete mountainsort;
			delete crossxsort;
			deleted = true;

		}
		glfwPollEvents();

	}
	glfwTerminate();
	return 0;

}

void start(){

	srand(time(NULL));

	cout << "W\x84hle ein Sortierverfahren:\n" << "1: Quicksort\n" << "2: Bubblesort\n" << "3: Insertionsort\n" << "4: Selectionsort\n" << "5: Mergesort\n" << "6: Bogosort\n" << "7: Mountainsort\n" << "8: CrossXSort\n";
	cin >> SORT_MODE;
	cout << "\nW\x84hle eine Darstellungsart:\n" << "1: GL_POINTS\n" << "2: GL_LINES\n";
	cin >> DRAW_MODE;
	switch (DRAW_MODE)
	{
	case 1:
		DRAW_MODE = GL_POINTS;
		break;
	case 2:
		DRAW_MODE = GL_LINES;
		break;
	default:
		DRAW_MODE = GL_POINTS;
		break;
	}
	cout << "\nGr" << "\x94" << "\xE1" << "e des Arrays: ";
	cin >> ARRAY_SIZE;
	cout << "Maximalwert eines Elements: ";
	cin >> MAX_VALUE;
	cout << "Skalierung f\x81r ein Element (Standard: 1): ";
	cin >> WIDTH_SCALE;
	cout << "Farbe f\x81r die Elemente (Hex-Wert als 0xRRGGBB): ";
	cin >> hex >> POINT_COLOR;
	cout << "Zeichenverz\x94gerung in \xE6s: ";
	cin >> DRAW_DELAY;

	COL_RED = ((POINT_COLOR >> 16) & 0xFF) / 255.0f;
	COL_GREEN = ((POINT_COLOR >> 8) & 0xFF) / 255.0f;
	COL_BLUE = ((POINT_COLOR) & 0xFF) / 255.0f;

	cout << "\n\nArray Gr" << "\x94" << "\xE1" << "e: " << ARRAY_SIZE << "\n"
		<< "Maximalwert: " << MAX_VALUE << "\n"
		<< "Farbe: R - " << COL_RED << " G - " << COL_GREEN << " B - " << COL_BLUE << "\n"
		<< "Zeichenverz\x94gerung: " << DRAW_DELAY << "\xE6s bei 60 fps\n\n\n";

}

void setupGL(){

	glfwMakeContextCurrent(window);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, ARRAY_SIZE, 0, MAX_VALUE, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);

	glPointSize(WIDTH_SCALE);
	glLineWidth(WIDTH_SCALE);

}

void startSort(int mode){

	switch (mode)
	{
	case 1:
		quicksort->start(list1, 0, ARRAY_SIZE - 1, 0);
		break;
	case 2:
		bubblesort->bubblesort(list1, ARRAY_SIZE - 1);
		break;
	case 3:
		insertionsort->insertionsort(list1, ARRAY_SIZE - 1);
		break;
	case 4:
		selectionsort->selectionsort(list1, ARRAY_SIZE - 1);
		break;
	case 5:
		mergesort->start(list1, ARRAY_SIZE - 1, 0, ARRAY_SIZE - 1, 0);
		break;
	case 6:
		quicksort->start(list1, 0, ARRAY_SIZE - 1, 2);
		bogosort->bogosort(list3, list1);
		break;
	case 7:
		mountainsort->mountainsort(list1, 0, ARRAY_SIZE - 1);
		break;
	/*case 8:
		crossxsort->crossxsort(list1, 0, ARRAY_SIZE - 1);
		break;*/
	default:
		break;
	}

}