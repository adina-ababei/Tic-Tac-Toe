#include "Header.h"

char board[3][3];
int maxTurnsPlayer = 0;
int maxTurnsAI = 0;
char player;
char AI;
int line;
int column;
int AItype;
int setP, setL;
//welcome screen - rules..
void welcome()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = '_';

	}

	cout << "X si Zero este un joc la care participa doi jucatori: unul joaca cu semnul X si celalalt joaca cu 0. Ambii muta alternativ, incepand cu jucatorul X. Ei pot muta doar in patratelele libere. Initial, tabla este alcatuita din 9 patratele goale, aliniate intr-o tabla de 3x3. Scopul jocului este de a face 3 semne proprii pe o linie, coloana sau diagonala. Daca tabla este plina dar nici un jucator nu a reusit sa indeplineasca acest scop, atunci jocul se termina remiza.";
	cout << '\n'; cout << '\n';
}

//settings:  easy-1, medium-2; hard-3;
int settingLevel()
{
	cout << "Alegeti dificultatea jocului: \nEasy -> 1 \nMedium -> 2 \nHard -> 3 \n";
	int choice;
	cin >> choice;
	while (choice == 0 || choice >= 4)
	{
		cout << "Alegere incorecta! Introduceti alte date: ";
		cin >> choice;
	}

	return choice;

}

//setings: 1vs1-0; 1vsC-1;
bool settingPlayer()
{
	cout << "Alegeti tipul jocului: \nPlayer vs Player -> 0 \nPlayer vs Computer ->1 \n";

	int choice;
	cin >> choice;
	while (choice >=2)
	{
		cout << "Alegere incorecta! Introduceti alte date: ";
		cin >> choice;
	}

	return choice;
}

//first player
void firstPlayer()
{
	int r;
	srand(time(NULL));
	r = rand() % 2 + 1;

	if (r == 1)
	{
		player = 'X';
		AI = '0';
		cout << "Tu esti primul! " << '\n';
		cout << '\n';
	}
	else
	{
		player = '0';
		AI = 'X';
		cout << "Primul jucator este calculatorul!" << '\n';
		cout << '\n';
	}
}

//cout turn
void printTurn()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << board[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}

//human moves
void playerMove()
{
	cout << "Introduceti coordonatele: " << '\n';

	cout << "Introduceti linia: ";
	cin >> line;
	while (line >= 3)
	{
		cout << "Date incorecte. Introduceti o valoare valida: \n";
		cin >> line;
	}

	cout << "Introduceti coloana: ";
	cin >> column;
	while (column >= 3)
	{
		cout << "Date incorecte. Introduceti o valoare valida: \n";
		cin >> column;
	}
	board[line][column] = 'X';
	maxTurnsPlayer++;

}

//computer moves: easy AI
void AI1Move();

//computer moves: medium AI
void AI2Move();

//computer moves: hard AI
void AI3Move();

//end game - we have a winner
bool winner();

//end game - we don't have a winner
bool tieGame()
{
	if (maxTurnsPlayer == 8 || maxTurnsAI == 8)
		return 1;
	return 0;
}

void startGame()
{
	welcome();
	printTurn();
	setP = settingPlayer();
	if (setP == 1)
		setL = settingLevel();
	
	firstPlayer();
	//while (!winner() || !tieGame())
	{
		if (player == 'X')
		{
			playerMove();
			//AI1Move();
		}
		else
		{
			//AI1Move();
			//playerMove();
		}

	}
}