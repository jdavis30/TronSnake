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
#include <random>


class Game {
	public:
		Game(int sizeX = 10, int sizeY = 10);
		bool update();
		friend Grid;
		void draw();

	private:
		int SIZE_X;
		int SIZE_Y;
		Head head;
		vector<Tail> tail;
		EmptyCell emptyCell;
		Grid grid;

};

#endif GAME_H