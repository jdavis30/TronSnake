/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Game.h
 * Date: 4/26/2016
 * Objective: "Operator" of the entire system. updates variables, draws them, and ends the process.
 */
#include "Grid.h"
#include <vector>
<<<<<<< HEAD
#include <random>
=======
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
>>>>>>> ba54fc091809766e1f1aac1154c6e2d28aac9978


#ifndef GAME_H
#define GAME_H
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

#endif /*GAME_H */
