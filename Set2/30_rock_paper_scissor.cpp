#include <iostream>
#include <cctype>
#include <ctime>

using namespace std;

char getUserChoice30(){

	char player;

	do{
		cout << endl << endl << "Rock(R) - Paper(P) - Scissors (S)" << endl << "Choose:  ";
		cin >> player;
		player = toupper(player);

	}while(player != 'R' && player != 'P' && player != 'S');

	return player;
}

char getCompChoice30(){

	srand(time(0));
	int number = rand() % 3;

	char choice;

	if(number == 0){
		choice = 'R';
	}
	else if(number == 1){
		choice = 'P';
	}
	else{
		choice = 'S';
	}

	return choice;
}

void showChoice30(char choice, int mover){
	switch(choice){
	case 'P':
		if(mover == 0){
			cout << "You chose paper. ";
			break;
		}
		else{
			cout << "Computer chose paper.";
			break;
		}

	case 'R':
		if(mover == 0){
			cout << "You chose rock. ";
			break;
		}
		else{
			cout << "Computer chose rock.";
			break;
		}

	case 'S':
		if(mover == 0){
			cout << "You chose scissors. ";
			break;
		}
		else{
			cout << "Computer chose scissors.";
			break;
		}
	}
}

void chooseWinner30(char player, char comp){

	cout << endl;

	switch(player){
	case 'R':
		if(comp == 'R'){
			cout << "It's a tie.";
		}
		else if(comp == 'P'){
			cout << "Computer won.";
		}
		else if(comp == 'S'){
			cout << "You won.";
		}
		break;

	case 'P':
		if(comp == 'P'){
			cout << "It's a tie.";
		}
		else if(comp == 'S'){
			cout << "Computer won.";
		}
		else if(comp == 'R'){
			cout << "You won.";
		}
		break;

	case 'S':
		if(comp == 'S'){
			cout << "It's a tie.";
		}
		else if(comp == 'R'){
			cout << "Computer won.";
		}
		else if(comp == 'P'){
			cout << "You won.";}
		break;
	}
}

int main30(){

	int player = 0;
	int comp = 1;
	char player_choice;
	char comp_choice;
	bool game_end = false;

	while(!game_end){

		player_choice = getUserChoice30();
		comp_choice = getCompChoice30();

		showChoice30(player_choice, player);
		showChoice30(comp_choice, comp);
		chooseWinner30(player_choice, comp_choice);
	}

	return 0;
}
