/*
 * CS100 Final Project: Tron Snake
 * Author: Jasper Davis
 * File: Game.h
 * Date: 4/26/2016
 * Objective: "Operator" of the entire system. updates variables, draws them, and ends the process.
 */
#include "Grid.h"
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#ifndef TRONSNAKE_GAME_H
#define TRONSNAKE_GAME_H
class Game {
	public:
		Game(int sizeX = 10, int sizeY = 10, int wSizeX = 800, int wSizeY = 800);

		bool update();

		void setDirection(char c);

		void draw();

		void endGame();

		void reset();

	private:
		bool firstRun;
		int SIZE_X;
		int SIZE_Y;
		int W_SIZE_X;
		int W_SIZE_Y;
		Head head;
		vector<Tail> tail;
		EmptyCell emptyCell;
		vector<sf::RectangleShape> rects;
		sf::RenderWindow* window;
		sf::RectangleShape* headShape;
		sf::RectangleShape* foodShape;
		Grid grid;

};

#endif /*TRONSNAKE_GAME_H */