#include "UserInteraction.h"

UserInteraction::UserInteraction()
{
  player1 = new Board();
  player2 = new Board();
  numShips = 0;
}


UserInteraction::~UserInteraction()
{
  delete player1;
  delete player2;
}


void UserInteraction::playGame()
{
  // main code goes here
  int choice;
  p1Turn = true;
  cout << "Hi! Welcome to Battleship!\n";
  cout << "1. Start" << endl; // start the game
  cout << "2. Quit" << endl; //quit the game
  cout << "Option: ";
  cin >> choice;
  if(choice == 1)
  {
    cout << "***************************\n";
    cout << "Game is starting...\n";
    cout << "***************************\n";


    cout << "input your number of ships (enter a value between 1-6): ";
    cin >> numShips;

    while(numShips > 6 || numShips <=0)
    {
      cout << "Sorry, the value entered was not between the allowed value. Please try again.";
      cout << "input your number of ships (enter a value between 1-6): ";
      cin >> numShips;
    }

    system("clear");
    cout << "Player 1 set your ships\n";
    player1->shipPlacement(numShips);

    system("clear");
    cout << "Player 2 set your ships\n";
    player2->shipPlacement(numShips);

    while(1)
    {
      int choose;
      do
      {
        cout << "1. Attack opponent\n";
        cout << "2. View my board\n";
        cout << "3. View opponent board\n";
        cout << "4. Quit\n";
        cout << "What would you like to do: ";
        cin >> choose;

        if (choose <= 0 || choose > 4)
        {
          cout << "Sorry, the value entered was not between the allowed value. Please try again.\n";
        }
      } while(choose <= 0 || choose > 4);


      if(choose == 1)
      {
        // fireAt();
        cout << "fireAt()...\n";
        system("clear");
        p1Turn = !p1Turn;
        if(p1Turn == true)
        {
          player2.fireAt();
        }
        else
        {
          player1.fireAt();
        }
      }

      if(choose == 2)
      {
        if(p1Turn)
        {
          player1->viewBoard();
        }
        else
        {
          player2->viewBoard();
        }
      }

      if(choose == 3)
      {
        if(p1Turn)
        {
          // player1->viewOBoard();
          cout << "under development\n\n";
        }

        else
        {
          // player2->viewOBoard();
          cout << "under development\n\n";
        }
      }

      if(choose == 4)
      {
        cout << "Quitting...";
        break;
      }

    }

  }

  if(choice == 2) // if quit
  {
    cout << "Goodbye!\n\n";
  }

  if(choice<1 || choice>2)
  {
    cout << "Please enter the correct number to start a game or quit!"<< endl;
  }

}


void UserInteraction::run()
{
  playGame();
}
