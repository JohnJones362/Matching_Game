
#include<iostream>

#include <cctype>
#include <ctime>


using namespace std;

//Class
class Matching_Game
{
  protected:

//Declare global variables
    
    
    char random_numbers;
    int column, row, row1Value, column1Value, row2Value, column2Value, matrix[5][5];
    int menu;
    bool again = true;
    bool matrix2[5][5];
 

  public:

    // Display the cards
    void display()
    {
	// Easy grid setup
	cout << "    1 2 3 4 5" << endl;
	cout << "  ";

	for (int i = 0; i <= 10; i++) {
	    cout << "-";
	}
	cout << endl;

	//More setup
	for (int row = 0; row < 5; row++) {
	    cout << row + 1 << " | ";

	    for (int column = 0; column < 5; column++) {
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

	// Select game

	
	//Main Menu
	while (again) {
	    
	    
	    cout << "Select 1 for a New Game and 2 to Exit Game" << endl;
	    cout << "1. New Game" << endl;
	    cout << "2. Exit Game" << endl;
	    
	    cin >> menu;

	    //Option to exit game and reasks the user to play again
	    if (menu == 2) {
		cout << endl;
		cout << "Would you like to play Matching Game again?" << endl;
		cout << "Type '1' to play again and '0' to leave" << endl;
		cin >> again;
		cout << endl;
	    }
	    // Option to start game and difficulty selection
	    else if (menu == 1) {
		// Game grid selection
		cout << "If you're ready, please press e" << endl;
		

		cin >> random_numbers;

		//Switch statement which determines the grid setup for
		//the chosen game
		switch (random_numbers) {
		    //Case easy
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

		    //End of case easy
		    break;
		}
	    }
	}
    }

    // game function
    void Loop()
    {
	while (again) {
	    //Prompt
	    cout << "Please enter a row value for first card: "
		 << endl;
	    cin >> row1Value;

	    cout << 
		"Please enter a column value for first card: " << endl;
	    cin >> column1Value;

	    cout <<
		"Please enter a row value for second card: " << endl;
	    cin >> row2Value;

	    cout <<
		"Please enter a column value for second card: " << endl;
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

	    // Initializes the function for matching results
	    Match();
	}

	
	system("cls");
	
    }

    //Match in  game function
    void Match()
    {
	//Check condition
	if (matrix[row1Value][column1Value] == matrix[row2Value][column2Value]) {	//If there is a match
	    // Leave them exposed
	    
	    
	    cout << "Congrats!" << endl;
	    cout << "TheCards Match" << endl << endl;
	    
	    
	} else {
	    
	    cout << "Sorry" << endl;
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

    Matching_Game Game;
    Game.start();

}

