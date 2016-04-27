/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Game.h
 * Date: 4/26/2016
 * Objective: "Operator" of the entire system. updates variables, draws them, and ends the process.
 */
#ifndef GAME_H
#define GAME_H
#include "Grid.h"
#include <vector>

class Game {
	public:
		Game(int sizeX = 10, int sizeY = 10);

		void update();

		void draw();

	private:
		int x;
		int y;
		Grid grid;
		Head head;
		vector<Tail> tail;

};

#endif GAME_H