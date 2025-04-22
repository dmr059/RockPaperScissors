#include <iostream>
//Holds the ability to seed random with time
#include <ctime>
//Holds Random Function
#include <cstdlib>

using namespace std;

//Validates who won the game
int GameWinner(int player_choice, int computer_choice){
	
	if (player_choice == computer_choice){
		
		cout << "It's a tie!\n";
		
		//Returns "0" value
		return 0;			
		
	}
	
	else if (player_choice == 1 && computer_choice == 3 ||
			  player_choice == 2 && computer_choice == 1 ||
			  player_choice == 3 && computer_choice == 2){
						  
				cout << "You won!\n";
				
				//Returns "1" value
				return 1;
	
	}
	
	else {
		
		cout << "Computer won!\n";
		
		//Returns "-1" value
		return -1;
		
	}

}

//Generates Computer's Choice
int ComputerChoice(){	
			
	//A number between 1 - 3
	return 1 + rand() % 3;
			
}

//Asks for player's choice/weapon of choice
int PlayerChoice(){
	
	int choice;
	
	cout << endl;
	cout << "Choose your weapon! \n";
	cout << "(1) for Rock \n";
	cout << "(2) for Paper \n";
	cout << "(3) for Scissors \n";
	
	cout << "Weapon choice: ";
	cin >> choice;
	
	
	//Validates "player_choice
	while (true) {
						
		//Validates "player_choice" is an integer		
		if (cin.fail()){
		
		cout << endl;
    	cout << "Error: Please enter a number.\n";
        cin.clear(); // Clears error flag
        cin.ignore(10000, '\n'); 
        cout << "Try again: ";
	
		}
		
		//validates "player_choice" is within range
		else if (choice < 1 || choice > 3){
		
		cout << endl;
		cout << "Error: Weapon choice is not available.\n";
		cout << "Try again: ";
		cin >> choice;			
		
		}
		
		else {
			
			//Input was valid
			break;
			
		}
				
	}
		
	return choice;	
	
}

int main() {
	
	//Seeds random num generator
	srand(time(0));
	
	//Holds the RETURNED VALUE from the PlayerChoice() & ComputerChoice() Functions
	int player_choice, computer_choice;
	
	//Holds the result of the round
	int game_result;
	
	//Keeps track of rounds won/lost/tied
	int round_won = 0;
	int round_tied = 0;
	int round_lost = 0;
	
	//Holds player's name
	string player_name;
	
	string choices[] = {"Rock", "Paper", "Scissors"};
	
	//Greets Player
	cout << "Welcome to the Rock, Paper, Scissors Dojo!\n\n";
	cout << "What is your name, challenger? ";
	cin >> player_name;	
	cout << endl;
	cout << "Alright, challenger " << player_name << ", time to get down to business!";
	
	//Runs the game 5 times
	for (int i = 0; i < 5; i++){
		
		//Assignes player_choice to returned value of PlayerChoice() function
		player_choice = PlayerChoice();
	
		//Assigns computer_choice to returned value of ComputerChoice() function
		computer_choice = ComputerChoice();	
		
		//Displays what each person played
		cout << endl;
		cout << "You played " << choices[player_choice - 1] << ".\n";
		cout << "Computer played " << choices[computer_choice - 1] << ".\n";
				
		game_result = GameWinner(player_choice, computer_choice);
		
		if (game_result == 1){
			
			round_won++;
			
		}
		
		else if (game_result == 0) {
			
			round_tied++;
			
		}
		
		else if (game_result == -1){
			
			round_lost++;	
			
		}
		
	}
	
	//Displays player score	
	cout << endl;
	cout << "That's the game!\n";
	cout << "You won " << round_won << "/5 games.\n";
	cout << "Tied " << round_tied << "/5 games.\n";
	cout << "Lost " << round_lost << "/5 games.\n";
	cout << "\nThanks for playing!\n";
	
	return 0;	
	
}
