
#include<iostream>
#include <string>
#include <ctime>


using namespace std;

//Class
class MemoryGame
{
  protected:

//Declare global variables
    int matching;
    
    char random_numbers;
    int column, row, row1Value, column1Value, row2Value, column2Value, matrix[5][5];
    int menu;
    bool again = true;
    bool matrix2[5][5];
   

  public:

    // Display the cards
    void display()
    {
	// Grid setup
	cout << "    1 2 3 4 5" << endl;
	cout << "  ";

	for (int i = 0; i <= 8; i++) 
{
	    cout << "-";
	}
	cout << endl;

	//More setup
	for (int row = 0; row < 4; row++) {
	    cout << row + 1 << " | ";

	    for (int column = 0; column < 4; column++) {
		// Print the value or '*' depending on wether the card
		// is exposed.
		if (matrix2[row][column]) {
		    cout << matrix[row][column];
		} else {
		    cout << '*';
		}
		cout << ' ';
	    }
	    cout << endl;
	}
	cout << endl;
    }
    
    void start()
    {
	// The first few lines are only printed once.

	cout << "Welcome to Matching Game" << endl << endl;

	//Main Menu
	while (again) 
  {
	    cout << "Select 1 for a New Game and 2 to Exit Game" << endl;
	    cout << "1. New Game" << endl;
	    cout << "2. Exit Game" << endl;
	   
	    cin >> menu;

	    //Option to exit game and reasks the user to play again
	    if (menu == 2) {
		cout << endl;
		cout << "Would you like to play the Matching Game again?" << endl;
		cout << "Type '1' to play again and '0' to leave" << endl;
		cin >> again;
		cout << endl;
	    }
	   // To make sure the cards are randomized
	    else if (menu == 1) 
      {
	
		cin >> random_numbers;

		switch (random_numbers) 
    {
		    
		case 'e':
		    srand((unsigned int) time(NULL));
		    //Dictates number of columns and rows
		    for (int row = 0; row < 5; row++) {
			for (int column = 0; column < 5; column++) {
			    //Initialize a random matrix
			    matrix[row][column] = rand() % 9 + 1;
			    matrix2[row][column] = false;
			}
			cout << endl;
		    }
		    
		    

		    // display the board
		    display();

		    //Initalize the  game function after setup
		    Loop();

		    //End of case
		    break;
		}
	    }
	}
    }

    // game function
    void Loop()
    {
	while (matching) 
  {
	    //Prompt
	    cout << "Enter a row value for first card: "
		 << endl;
	    cin >> row1Value;

	    cout<<
		"Enter a column value for first card: " << endl;
	    cin >> column1Value;

	    cout << 
		"Enter a row value for second card: " << endl;
	    cin >> row2Value;

	    cout << 
		"Enter a column value for second card: " << endl;
	    cin >> column2Value;
	    cout << endl;

	    //Decrease the number value as the rows and columns go down
	    row1Value--;
	    column1Value--;
	    row2Value--;
	    column2Value--;

	    // Temporarily expose the cards
	    matrix2[row1Value][column1Value] = true;
	    matrix2[row2Value][column2Value] = true;

	    // display the board
	    display();

	   
	}



    //Match in  game function
    void Match()
    {
	//Check condition
	if (matrix[row1Value][column1Value] == matrix[row2Value][column2Value]) {	//If there is a match
	  
	
	    
	    cout << "Congratulations!" << endl;
	    cout << "The Cards Match!" << endl << endl;
	    
	} else {
	    
	    cout << "Sorry!" << endl;
	    cout << "The Cards Don't Match!" << endl << endl;
	   
	

	    // Cover them up again
	    matrix2[row1Value][column1Value] = false;
	    matrix2[row2Value][column2Value] = false;
  }
    }
};

// Executable code for the whole program
int main()
{

    MemoryGame Game;
    Game.start();
 return 0;
}
