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
Minmaxsort* minmaxsort;
Heapsort* heapsort;
Combsort* combsort;
Swapsort* swapsort;
Shellsort* shellsort;
Cocktailsort* cocktailsort;
Pigeonholesort* pigeonholesort;
Gnomesort* gnomesort;
Stoogesort* stoogesort;
Countingsort* countingsort;

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
float POINT_COL_RED = 0;
float POINT_COL_GREEN = 0;
float POINT_COL_BLUE = 0; 
float BACK_COL_RED = 0;
float BACK_COL_GREEN = 0;
float BACK_COL_BLUE = 0;
int POINT_COLOR = 0xFF0000;
int BACK_COLOR = 0x000000;
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

	random_shuffle(list1->begin(), list1->end());
	copy(list1->begin(), list1->end(), list2->begin());
	copy(list1->begin(), list1->end(), list3->begin());

	DrawGraphics* graphics = new DrawGraphics(window, list2, POINT_COL_RED, POINT_COL_GREEN, POINT_COL_BLUE, BACK_COL_RED, BACK_COL_GREEN, BACK_COL_BLUE, ARRAY_SIZE, DRAW_MODE, DRAW_DELAY);

	quicksort = new Quicksort(graphics);
	bubblesort = new Bubblesort(graphics);
	insertionsort = new Insertionsort(graphics);
	selectionsort = new Selectionsort(graphics);
	mergesort = new Mergesort(graphics);
	bogosort = new Bogosort(graphics);
	mountainsort = new Mountainsort(graphics);
	crossxsort = new CrossXSort(graphics);
	minmaxsort = new Minmaxsort(graphics);
	heapsort = new Heapsort(graphics);
	combsort = new Combsort(graphics);
	swapsort = new Swapsort(graphics);
	shellsort = new Shellsort(graphics);
	cocktailsort = new Cocktailsort(graphics);
	pigeonholesort = new Pigeonholesort(graphics);
	gnomesort = new Gnomesort(graphics);
	stoogesort = new Stoogesort(graphics);
	countingsort = new Countingsort(graphics);

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
				crossxsort->graphicCrossxsort(list2, 0, ARRAY_SIZE - 1);
				break;
			case 9:
				minmaxsort->graphicMinmaxsort(list2, 0, ARRAY_SIZE - 1);
				break;
			case 10:
				heapsort->graphicBuild_heap(list2, ARRAY_SIZE - 1);
				heapsort->graphicHeapsort(list2, ARRAY_SIZE - 1);
				break;
			case 11:
				combsort->graphicCombsort(list2, ARRAY_SIZE - 1);
				break;
			case 12: //!! Nur wenn |n| +- 0 ist !!//
				swapsort->graphicSwapsort(list2, ARRAY_SIZE - 1);
				break;
			case 13:
				shellsort->graphicShellsort(list2, ARRAY_SIZE - 1);
				break;
			case 14:
				cocktailsort->graphicCocktailsort(list2, ARRAY_SIZE - 1);
				break;
			case 15:
				pigeonholesort->graphicPigeonholesort(list2, ARRAY_SIZE - 1);
				break;
			case 16:
				gnomesort->graphicGnomesort(list2, ARRAY_SIZE - 1);
				break;
			case 17:
				stoogesort->graphicStoogesort(list2, 0, ARRAY_SIZE - 1);
				break;
			case 18:
				countingsort->graphicCountingsort(list2, ARRAY_SIZE - 1);
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
			delete minmaxsort;
			delete heapsort;
			delete combsort;
			delete swapsort;
			delete shellsort;
			delete cocktailsort;
			delete pigeonholesort;
			delete gnomesort;
			delete stoogesort;
			delete countingsort;
			deleted = true;

		}
		glfwPollEvents();

	}
	glfwTerminate();
	return 0;

}

void start(){

	srand(time(NULL));

	cout << "W\x84hle ein Sortierverfahren:\n" << 
		"1: Quicksort" << setw(30) << "10: Heapsort\n" << "2: Bubblesort" << setw(29) << "11: Combsort\n" << 
		"3: Insertionsort" << setw(26) << "12: Swapsort\n"<< "4: Selectionsort" << setw(27) << "13: Shellsort\n"<<
		"5: Mergesort" << setw(34) << "14: Cocktailsort\n" << "6: Bogosort" << setw(38) << "15: Pigeonhole-sort\n" << 
		"7: Mountainsort" << setw(28) << "16: Gnomesort\n" << "8: CrossXSort" << setw(31) << "17: Stoogesort\n" << 
		"9: Min-Max-sort" << setw(31) << "18: Countingsort\n";
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
	cout << "Skalierung f\x81r ein Element: ";
	cin >> WIDTH_SCALE;
	cout << "Farbe f\x81r die Elemente (Hex-Wert als 0xRRGGBB): ";
	cin >> hex >> POINT_COLOR;
	cout << "Farbe f\x81r den Hintergrund (Hex-Wert als 0xRRGGBB): ";
	cin >> hex >> BACK_COLOR;
	cout << "Zeichenverz\x94gerung in \xE6s: ";
	cin >> DRAW_DELAY;

	POINT_COL_RED = ((POINT_COLOR >> 16) & 0xFF) / 255.0f;
	POINT_COL_GREEN = ((POINT_COLOR >> 8) & 0xFF) / 255.0f;
	POINT_COL_BLUE = ((POINT_COLOR)& 0xFF) / 255.0f;

	BACK_COL_RED = ((BACK_COLOR >> 16) & 0xFF) / 255.0f;
	BACK_COL_GREEN = ((BACK_COLOR >> 8) & 0xFF) / 255.0f;
	BACK_COL_BLUE = ((BACK_COLOR)& 0xFF) / 255.0f;

	cout << "\n\nArray Gr" << "\x94" << "\xE1" << "e: " << ARRAY_SIZE << "\n"
		<< "Maximalwert: " << MAX_VALUE << "\n"
		<< "Elementfarbe: R - " << POINT_COL_RED << " G - " << POINT_COL_GREEN << " B - " << POINT_COL_BLUE << "\n"
		<< "Hintergrundfarbe: R - " << BACK_COL_RED << " G - " << BACK_COL_GREEN << " B - " << BACK_COL_BLUE << "\n"
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
	case 8:
		crossxsort->start(list1, 0, ARRAY_SIZE - 1);
		break;
	case 9:
		minmaxsort->minmaxsort(list1, 0, ARRAY_SIZE - 1);
		break;
	case 10:
		heapsort->start(list1, ARRAY_SIZE - 1);
		break;
	case 11:
		combsort->combsort(list1, ARRAY_SIZE - 1);
		break;
	case 13:
		shellsort->shellsort(list1, ARRAY_SIZE - 1);
		break;
	case 14:
		cocktailsort->cocktailsort(list1, ARRAY_SIZE - 1);
		break;
	case 15:
		pigeonholesort->pigeonholesort(list1, ARRAY_SIZE - 1);
		break;
	case 16:
		gnomesort->gnomesort(list1, ARRAY_SIZE - 1);
		break;
	case 17:
		stoogesort->start(list1, 0, ARRAY_SIZE - 1);
		break;
	case 18:
		countingsort->countingsort(list1, ARRAY_SIZE - 1);
		break;
	default:
		break;
	}

}