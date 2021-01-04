#include <iostream>
#include <iomanip>

class ticTacToe {
private:
	char positions[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int player = 1, attempts = 0;
	bool nextPlayer = true;

public:
	char showArray(int arg_index) {
		return positions[arg_index];
	}

	void replaceWithX_O(int arg_index, char arg_X_O) {
		if (positions[arg_index - 1] == 'X' || positions[arg_index - 1] == 'O') {
			nextPlayer = false;
		}
		else {
			nextPlayer = true;
			positions[arg_index - 1] = arg_X_O;
		}
	}

	bool nextPlayerBool() {
		return nextPlayer;
	}

	int currentPlayer(bool arg_checkPlayer) {
		if (arg_checkPlayer == true && nextPlayer == true) {
			player++;

			if (player == 3) {
				player = 1;
			}
			else {
				player = 2;
			}
		}
		else {
			return player;
		}
	}

	void draw() {
		if (positions[0] == '1' || positions[1] == '2' || positions[2] == '3'
			|| positions[3] == '4' || positions[4] == '5' || positions[5] == '6'
			|| positions[6] == '7' || positions[7] == '8' || positions[8] == '9') {}
		else {
			std::cout << "\n\DRAW!\n\n";
			exit(0);
		}
	}
};

void showInfo();
void board();
void replaceNumbers();
void checkValidPosition();
bool win();

ticTacToe tTT;

int main() {
	board();

	return 0;
}

void showInfo() {
	std::cout << std::setw(20) << "Tic Tac Toe\n\n";

	std::cout << "Player 1 (X) - Player 2 (O)\n\n";
}

void board() {
	system("CLS");

	showInfo();

	std::cout << "     |     |     \n";
	std::cout << "  " << tTT.showArray(0) << "  |  " << tTT.showArray(1) << "  |  " << tTT.showArray(2) << "\n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << tTT.showArray(3) << "  |  " << tTT.showArray(4) << "  |  " << tTT.showArray(5) << "\n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |     |     \n";
	std::cout << "  " << tTT.showArray(6) << "  |  " << tTT.showArray(7) << "  |  " << tTT.showArray(8) << "\n";
	std::cout << "     |     |     \n";

	tTT.draw();

	if (win() == true) {
		exit(0);
	}
	else {
		replaceNumbers();
	}
}

void replaceNumbers() {
	int move;

	while (true) {
		std::cout << "\nPlayer " << tTT.currentPlayer(false) << ", enter a number: ";
		std::cin >> move;

		switch (tTT.currentPlayer(false)) {
		case 1:
			tTT.replaceWithX_O(move, 'X');
			break;
		case 2:
			tTT.replaceWithX_O(move, 'O');
			break;
		default:
			break;
		}

		tTT.currentPlayer(true);

		checkValidPosition();
	}
}

void checkValidPosition() {
	if (tTT.nextPlayerBool() == true) {
		board();
	}
	else {
		replaceNumbers();
	}
}

bool win() {
	if (tTT.showArray(0) == 'X' && tTT.showArray(1) == 'X' && tTT.showArray(2) == 'X' || tTT.showArray(3) == 'X' && tTT.showArray(4) == 'X' && tTT.showArray(5) == 'X' ||
		tTT.showArray(6) == 'X' && tTT.showArray(7) == 'X' && tTT.showArray(8) == 'X' || tTT.showArray(0) == 'X' && tTT.showArray(4) == 'X' && tTT.showArray(8) == 'X' ||
		tTT.showArray(2) == 'X' && tTT.showArray(4) == 'X' && tTT.showArray(6) == 'X' || tTT.showArray(0) == 'X' && tTT.showArray(3) == 'X' && tTT.showArray(6) == 'X' ||
		tTT.showArray(2) == 'X' && tTT.showArray(5) == 'X' && tTT.showArray(8) == 'X' || tTT.showArray(1) == 'X' && tTT.showArray(4) == 'X' && tTT.showArray(7) == 'X') {
		std::cout << "\nPlayer 1 - WIN!\n\n";
		return true;
	}
	else if((tTT.showArray(0) == 'O' && tTT.showArray(1) == 'O' && tTT.showArray(2) == 'O' || tTT.showArray(3) == 'O' && tTT.showArray(4) == 'O' && tTT.showArray(5) == 'O' ||
		tTT.showArray(6) == 'O' && tTT.showArray(7) == 'O' && tTT.showArray(8) == 'O' || tTT.showArray(0) == 'O' && tTT.showArray(4) == 'O' && tTT.showArray(8) == 'O' ||
		tTT.showArray(2) == 'O' && tTT.showArray(4) == 'O' && tTT.showArray(6) == 'O' || tTT.showArray(0) == 'O' && tTT.showArray(3) == 'O' && tTT.showArray(6) == 'O' ||
		tTT.showArray(2) == 'O' && tTT.showArray(5) == 'O' && tTT.showArray(8) == 'O') || tTT.showArray(1) == 'O' && tTT.showArray(4) == 'O' && tTT.showArray(7) == 'O') {
		std::cout << "\nPlayer 2 - WIN!\n\n";
		return true;
	}
	else {
		return false;
	}
}