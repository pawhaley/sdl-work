/*
main.cpp
Parker Whaley + group
5/7
the main function for the game
*/
//all of the assorted classes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "print.h"
#include "input.h"
#include <iostream>
#include <random>
#include <ctime>


using std::cout;
using std::endl;


int main(int argc,char **argv){
	//initialize SDL and the classes
	SDL_Init(SDL_INIT_EVERYTHING);
	srand(time(0));
	print printer;
	printer.printAsBack(printer.Obj("back.png"));
	printer.printOut();
	bool a[26];
	input in;
	in.letterKeys(a);
	a[0]=false;
	double ang=3.14/2;
	double n=1;
	double dn=.04;
	while(!a[0]){
		ang-=.7;
		n+=dn;
		if(n>10){
			dn=-dn;
		}
		in.letterKeys(a);
		printer.printAsBack(printer.Obj("back.png"));
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				printer.printRotC(printer.Obj("one.png"), ang, 1*i/n, .3*2*j/n, .8/n, .5, .5);
			}
		}
		printer.printOut();
	}
}
