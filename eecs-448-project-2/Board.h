#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <limits>
#include <stdlib.h>
#include <tuple>
#include <vector>

#include "Ship.h"

#define ROWS 9
#define COLS 10

#define HORIZONTAL 'H'
#define VERTICAL 'V'

#define EASY 1
#define MEDIUM 2
#define HARD 3

using namespace std;

class Board
{
private:
  // 2D array of type Ship
  Ship m_grid[ROWS][COLS];

  // Current row location
  int m_row;

  // Current col location
  int m_col;

  // Number of ships
  int m_numShips;

  // Number of ships that have been sunk
  int m_shipsSunk;

  //used by medium difficulty to track status
  int m_aiRow;
  int m_aiCol;

  // Stores how many radar charges left
  int m_radarCharges;

  // String to store user input
  string userInput;

  // True if valid
  bool validInput;

  // Stores error message
  string invalidCoordMessage;

public:
  /*
   * Initializes a 9x10 board
   * @param None
   * @return none
   */
  Board();

  /*
   * deallocates the board object
   * @param None
   * @return none
   */
  ~Board();

  /*
   * Allows players to view their board as well as the opponents board with
   * their hits and misses
   * @param asOpponent whether to view as opponent
   * @return none
   */
  void viewThisBoard();

  //Displays score
  void viewScores();

  /*
   * Ship is placed on the board
   * @param number of ships
   * @return none
   */
  void shipPlacement(int numShips);

  /*
   * Randomly place ships on the board
   * @param number of ships
   * @return none
   */
  void randomShipPlacement(int numShips);

  /*
   * Converts string input to int, checks for out of bounds
   * @param none
   * @return none
   */
  void promptForCoordinate();

  /*
   * Checks if ship placement is valid
   * @param int number for for loops and a bool for orientation
   * @return none
   */
  bool checkValidShipPlacement(int shipSize, bool horizontal);

  /*
   * User chooses coordinates to shoot at
   * @param None
   * @returns none
   */
  void fireAt();
  
  /*
   * User chooses coordinates to shoot a 3x3 shot
   * @param None
   * @returns none
   */
  void fireAtThree();

  /*
   * Board is being shot at by an AI
   * @param None
   * @returns none
   */
  void firedAtByAi(int difficulty);

  //Checks to see if a coordinate is on the board
  bool isOnGrid(int row, int col);

  /*
   * Checks to see if the opponents ship sunk
   * @param int for row and col location
   * @return boolean value for ship status
   */
  bool isSunk(int row, int col);

  /*
   * Checks to see if all ships have been sunk
   * @param None
   * @return boolean value for win status
   */
  bool hasLost();

  /**
   * Prompts user to use a radar charge, and outputs a random tile with a ship on it. 
   */
  void promptRadar();

  //Returns the number of ships
  int getNumShips(){ return m_numShips; };

  //Returns the number of ships sunk
  int getSunkShips() { return m_shipsSunk; };

  //Gets the char of a given tile
  char getShipGridChar(int x, int y);


  bool hasSpecialShot1 = true;
  bool hasSpecialShot2 = true;
};

#endif
