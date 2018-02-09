#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main() {

	char hit;
	char question;
	bool goAgain = true;
	srand(time(NULL));

	int pCard1 = rand() % 10 + 1;
	int pCard2 = rand() % 10 + 1;
	int pCard3 = rand() % 10 + 1;
	int pCard4 = rand() % 10 + 1;
	int pCard5 = rand() % 10 + 1;
	int dCard1 = rand() % 10 + 1;
	int dCard2 = rand() % 10 + 1;
	int dCard3 = rand() % 10 + 1;
	int dCard4 = rand() % 10 + 1;
	int dCard5 = rand() % 10 + 1;
	int pTotal;
	int	dTotal;

	while (goAgain) {
		cout << "Welcome to Blackjack" << endl;
		cout << "Lets play" << endl;
		pTotal = pCard1 + pCard2;
		cout << "Your cards are " << pCard1 << " " << pCard2 << endl;
		cout << "Dealer is showing " << dCard1 << endl;
		cout << "Your total is " << pTotal << endl;
		cout << "Do you want to hit? y/n" << endl;
		cin >> hit;

		if (hit == 'y') {
			cout << "You drew a " << pCard3 << endl;
			pTotal = pCard1 + pCard2 + pCard3;
			cout << "Your total is " << pTotal << endl;
			cout << "Do you want to hit? y/n" << endl;
			cin >> hit;

			if (hit == 'y') {
				cout << "You drew a " << pCard4 << endl;
				pTotal = pCard1 + pCard2 + pCard3 + pCard4;
				cout << "Your total is " << pTotal << endl;

				cout << "Do you want to hit? y/n" << endl;
				cin >> hit;

				if (hit == 'y') {
					cout << "You drew a " << pCard5 << endl;
					pTotal = pCard1 + pCard2 + pCard3 + pCard4 + pCard5;
					cout << "Your total is " << pTotal << " ,you can not draw anymore cards." << endl;
					goto dTurn;

				}
				else (hit == 'n'); { goto dTurn; }
			}
			else (hit == 'n'); { goto dTurn; }
		}
		else (hit == 'n'); { goto dTurn; }


	dTurn:
		cout << "Dealers turn" << endl;

		cout << "Dealer flips a " << dCard2 << endl;
		dTotal = dCard1 + dCard2;
		cout << "Dealer has " << dTotal << endl;

		if (dTotal <= 16) {
			cout << "Dealer draws a " << dCard3 << endl;
			dTotal = dCard1 + dCard2 + dCard3;
			cout << "Dealer has " << dTotal << endl;

			if (dTotal <= 16) {
				cout << "Dealer draws a " << dCard4 << endl;
				dTotal = dCard1 + dCard2 + dCard3 + dCard4;
				cout << "Dealer has " << dTotal << endl;

				if (dTotal <= 16) {
					cout << "Dealer draws a " << dCard5 << endl;
					dTotal = dCard1 + dCard2 + dCard3 + dCard4 + dCard5;
					cout << "Dealer has " << dTotal << endl;
					goto endGame;
				}
			}
			else(dTotal >= 17); {cout << "Dealer stays" << endl; goto endGame; }
		}
		else(dTotal >= 17); {cout << "Dealer stays" << endl; goto endGame; }

	endGame:
		cout << "You have " << pTotal << " and dealer has " << dTotal << endl;
		if (pTotal > dTotal) {
			cout << "You win" << endl;
			goto playAgain;
		}
		else if (pTotal < dTotal) {
			cout << "You lose" << endl;
			goto playAgain;
		}
		else (pTotal == dTotal); {
			cout << "The bet is push, you tied" << endl;
			goto playAgain;
		}

	playAgain:
		cout << "Do you want to play again? y/n" << endl;
		cin >> question;
		if (question != 'y') { goAgain = false; }
	}
	return 0;
}
