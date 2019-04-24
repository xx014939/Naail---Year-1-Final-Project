#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include"struct_enemy.h"
#include"struct_hero.h"

using namespace std;


// Create a function which outputs a random number

int random(int n) {
	return rand() % n;
}

int main(int argc, char** argv) {
	cout << "You must reach the exit which is marked by an X. Watch out for traps and enemies. " << endl;
	bool hero_win = false; // hero_win bool variable set to false. If the user escapes the maze it's set to true
	int l, m, o; // These int variables will be used to hold a random value later on. The random value changes the x,y coordinates of an enemy.

	srand(time(NULL));

	// Create the maze body using a 2d array

	unsigned char maze[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 3, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 3, 1},
		{1, 3, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 3, 0, 0, 1},
		{1, 0, 3, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 4, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	hero logan; // Create player character using previously defined struct
	logan.x = 1;
	logan.y = 1;

	enemy joe; // Enemy 1
	joe.x = 6;
	joe.y = 2;

	enemy brian; // Enemy 2
	brian.x = 2;
	brian.y = 5;

	enemy liam; // Enemy 3
	liam.x = 4;
	liam.y = 8;

	char key = 0;
	while (key != 'q') { // While the user does not want to quit
		if (hero_win = true) {
			for (int y = 0; y < 10; y++) {
				cout << endl;
				for (int x = 0; x < 10; x++) {
					if (x == logan.x && y == logan.y) {
						cout << (unsigned char)'P'; // output p to the screen, which represents the hero
					}
					else if (x == joe.x && y == joe.y) {
						cout << (unsigned char)'E'; // Ouput E which represents the enemy
					}
					else if (x == brian.x && y == brian.y) {
						cout << (unsigned char)'E';
					}
					else if (x == liam.x && y == liam.y) {
						cout << (unsigned char)'E';
					}
					else if (maze[y][x] == 1) {
						cout << (unsigned char)'#'; // # Are used as walls in maze
					}
					else if (maze[y][x] == 0) {
						cout << (unsigned char)'.'; // Full stops make up the body of the maze. Which ever space an enemy or the player occupy, they replace a full stop.
					}
					else if (maze[y][x] == 3) {
						cout << (unsigned char)','; // Output a comma to the screen, which is a "trap"
					}
					else if (maze[y][x] == 4) {
						cout << (unsigned char)'X'; // Output X to the screen which represents the exit
					}
					hero_win = false;
				}
			}
		}

		cout << endl;

		cout << "To move upwards press 'W', left 'A', down 'S', right 'D': "; // Output instruction to screen
		cin >> key; // Assign user input to key variable


		// Depending on user input, change x and y coordinates of the hero Logan
		if (key == 's' && logan.y < 9 && maze[logan.y + 1][logan.x] != 1) {
			logan.y++; system("cls");
		}
		if (key == 'S' && logan.y < 9 && maze[logan.y + 1][logan.x] != 1) {
			logan.y++; system("cls");
		}
		if (key == 'w' && logan.y > 0 && maze[logan.y - 1][logan.x] != 1) {
			logan.y--; system("cls");
		}
		if (key == 'W' && logan.y > 0 && maze[logan.y - 1][logan.x] != 1) {
			logan.y--; system("cls");
		}
		if (key == 'a' && logan.x > 0 && maze[logan.y][logan.x - 1] != 1) {
			logan.x--; system("cls");
		}
		if (key == 'A' && logan.x > 0 && maze[logan.y][logan.x - 1] != 1) {
			logan.x--; system("cls");
		}
		if (key == 'd' && logan.x < 9 && maze[logan.y][logan.x + 1] != 1) {
			logan.x++; system("cls");
		}
		if (key == 'D' && logan.x < 9 && maze[logan.y][logan.x + 1] != 1) {
			logan.x++; system("cls");
		}
		if (maze[logan.y][logan.x] == 3) {
			cout << "You have run into a trap. GAME OVER." << endl;
			system("PAUSE");
			exit(1);
		}

		//If coordinates of an enemy and the hero = each other then player dies
		if (maze[logan.y] == maze[joe.y] && maze[logan.x] == maze[joe.x]) {
			cout << "You have been defeated by an enemy. GAME OVER." << endl;
			system("PAUSE");
			exit(1);
		}
		if (maze[logan.y] == maze[brian.y] && maze[logan.x] == maze[brian.x]) {
			cout << "You have been defeated by an enemy. GAME OVER." << endl;
			system("PAUSE");
			exit(1);
		}
		if (maze[logan.y] == maze[liam.y] && maze[logan.x] == maze[liam.x]) {
			cout << "You have been defeated by an enemy. GAME OVER." << endl;
			system("PAUSE");
			exit(1);
		}
		// If user reaches the X then they win
		if (maze[logan.y][logan.x] == 4) {
			cout << "congratulations! " << endl;
			system("PAUSE");
			exit(1);
		}

		// Randomly move enemies arounf the screen using the previously defined function

		l = random(4) + 1;

		if (l == 1 && maze[joe.y + 1][joe.x] != 1 && maze[joe.y + 1][joe.x] != 3) {
			joe.y++; system("cls");
		}
		if (l == 2 && maze[joe.y - 1][joe.x] != 1 && maze[joe.y - 1][joe.x] != 3) {
			joe.y--; system("cls");
		}
		if (l == 3 && maze[joe.y][joe.x - 1] != 1 && maze[joe.y][joe.x - 1] != 3) {
			joe.x--; system("cls");
		}
		if (l == 4 && maze[joe.y][joe.x + 1] != 1 && maze[joe.y][joe.x + 1] != 3) {
			joe.x++; system("cls");
		}

		m = random(4) + 1;

		if (m == 1 && maze[brian.y + 1][brian.x] != 1 && maze[brian.y + 1][brian.x] != 3) {
			brian.y++; system("cls");
		}
		if (m == 2 && maze[brian.y - 1][brian.x] != 1 && maze[brian.y - 1][brian.x] != 3) {
			brian.y--; system("cls");
		}
		if (m == 3 && maze[brian.y][brian.x - 1] != 1 && maze[brian.y][brian.x - 1] != 3) {
			brian.x--; system("cls");
		}
		if (m == 4 && maze[brian.y][brian.x + 1] != 1 && maze[brian.y][brian.x + 1] != 3) {
			brian.x++; system("cls");
		}

		o = random(4) + 1;

		if (m == 1 && maze[liam.y + 1][liam.x] != 1 && maze[liam.y + 1][liam.x] != 3) {
			liam.y++; system("cls");
		}
		if (m == 2 && maze[liam.y - 1][liam.x] != 1 && maze[liam.y - 1][liam.x] != 3) {
			liam.y--; system("cls");
		}
		if (m == 3 && maze[liam.y][liam.x - 1] != 1 && maze[liam.y][liam.x - 1] != 3) {
			liam.x--; system("cls");
		}
		if (m == 4 && maze[liam.y][liam.x + 1] != 1 && maze[liam.y][liam.x + 1] != 3) {
			liam.x++; system("cls");
		}
	}


	return 0;
}
