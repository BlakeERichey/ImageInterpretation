//Take tuple of RBG colors (255, 0, 255) and classifies that as 1 of 11 colors:
//black, red, green, yellow, blue, cyan, magenta, white, orange, brown, grey
#include "brichey.h"

using namespace std;

string classifyColor(int r, int g, int b);
double distanceArr(int arr[], int arr2[], int arrSize);

int main() {
	int RGB[3];
	initArray(RGB, 3, 0);

	RGB[0] = getInt("Enter R value: ");
	RGB[1] = getInt("Enter G value: ");
	RGB[2] = getInt("Enter B value: ");
	cout << "Classifying the following color: ";
	printArr(RGB, 3);
	cout << classifyColor(RGB[0], RGB[1], RGB[2]) << endl;

	system("pause");
	return 0;
}

string classifyColor(int r, int g, int b) {
	int currentArr[] = { r, g, b };	//color passed to function
	string classes[] = { 
    "red", 
    "cyan", 
    "blue",
    "grey",
    "black", 
    "green", 
    "white",
    "brown",
    "orange", 
    "yellow", 
    "magenta" 
  };

	int red[]     = { 255,   0,   0};
	int cyan[]    = {   0, 255, 255};
	int blue[]    = {   0,   0, 255};
	int grey[]    = { 128, 128, 128};
	int black[]   = {   0,   0,   0};
	int green[]   = {   0, 255,   0};
	int white[]   = { 255, 255, 255};
	int brown[]   = { 101,  67,  33};
	int orange[]  = { 255, 165,   0};
	int yellow[]  = { 255, 255,   0};
	int magenta[] = { 255,   0, 255};


	struct distance //distance from color array
	{
		int rd;
		int cd;
		int bd;
		int grd;
		int bkd;
		int gd;
		int wd;
		int brd;
		int od;
		int yd;
		int md;
	};

	distance deltas = {	//distances from rgb to each vertex of RGB cube
		distanceArr(currentArr, red,     3), 
		distanceArr(currentArr, cyan,    3),
		distanceArr(currentArr, blue,    3),
		distanceArr(currentArr, grey,    3),
		distanceArr(currentArr, black,   3),
		distanceArr(currentArr, green,   3),
		distanceArr(currentArr, white,   3),
		distanceArr(currentArr, brown,   3),
		distanceArr(currentArr, orange,  3),
		distanceArr(currentArr, yellow,  3),
		distanceArr(currentArr, magenta, 3),
	};


	//----------Find minimum distance----------
	double dArr[] = { 
    deltas.rd, 
    deltas.cd, 
    deltas.bd,
    deltas.grd, 
    deltas.bkd, 
    deltas.gd, 
    deltas.wd,
    deltas.brd,
    deltas.od, 
    deltas.yd, 
    deltas.md 
  };

  // cout << "Display Distance Array" << endl;
  // for(int index = 0; index < 11; index++){
  //   cout << dArr[index] << " ";
  // }
  // cout << endl;

	int classIndex = 0;	//index of closest color for classifier
	double min = dArr[0];
	for (int i = 0; i < 11; i++) {
		if (dArr[i] < min) {
			min = dArr[i];
			classIndex = i;
		}
	}

	return classes[classIndex];
}
