/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Game.h
 * Date: 4/26/2016
 * Objective: "Operator" of the entire system. updates variables, draws them, and ends the process.
 */
#include "Grid.h"
#include <vector>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>


#ifndef GAME_H
#define GAME_H
class Game {
	public:
		Game(int sizeX = 10, int sizeY = 10);

		bool update();

		void setDirection(char c);

		void draw();

	private:
		int SIZE_X;
		int SIZE_Y;
		Head head;
		vector<Tail> tail;
		EmptyCell emptyCell;
		Grid grid;

};

#endif /*GAME_H */