/*
print.h
Parker Whaley + group
5/7
the class responsiable for handeling the screen
*/
#ifndef def_for_print
#define def_for_print

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
using std::ifstream;
using std::cout;
using std::string;
using std::to_string;
using std::vector;

class print{
public:
	print();
	//this returns the location of the object with the specified adress
	int Obj(string loc);
	//the size of the screen in meeters
	double xMeter();
	double yMeter();
	double scale();

	//prints a image as the background
	void printAsBack(int pos);
	//pos is the vector the other two are in meeters
	//the first one prints a image scaled to a size
	void printToScale(int pos,double posx,double posy,double scale);
	//this one prints it to the exact dementions
	void printAtSize(int pos, double posx, double posy, double width, double height);

	//rotates the object about portionw and portionh then prints that point on the image to x,y 
	void printRotC(int pos, double angle, double x, double y, double w, double portionW, double portionH);
	//same only with a flip
	void printRotCFlip(int pos, double angle, double x, double y, double w, double portionW, double portionH);
	//prints a hp bar above the tank
	void printHP(double posx,double posy, double width,double proportion);
	//puts what is in the renderer to the screen
	void printOut();
private:
	ifstream in;
	SDL_Texture* loadT(const string &file);
	void RenderText(int pos, double x, double y, double w, double h);
	void RenderTextScale(int pos, int x, int y, int s);
	double xdst_;
	double ydst_;
	int pixX_;
	int pixY_;
	double scale_;
	vector<string> names_;
	vector<SDL_Texture *> textures_;
	SDL_Renderer * render_;
};





#endif
