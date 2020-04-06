#include<iostream>

using std::cout;

void display_welcome_message()
{
	cout << "	Welcome to Bulls and Cows. The objective of this game is to guess " << '\n';
	cout << "the 4 digit number that the computer randomly generates. After each " << '\n';
	cout << "guess, the computer will give you the following 'hints' about each " << '\n';
	cout << "digit of your guess: " << '\n' << '\n';
	cout << "	1. If the number and digit of your guess and the answer match, " << '\n';
	cout << "	   it's a Bull, " << '\n';
	cout << "	2. If the number of your guess matches a number in another digit of " << '\n';
	cout << "	   the answer, it's a Cow, " << '\n' << '\n';
	cout << "Rules: " << '\n' << '\n';
	cout << "	1. Every Bull and Cow match must be unique. " << '\n';
	cout << "	2. Bull matches are counted first. " << '\n';
	cout << "	3. Bull and Cow matches are reset after every guess. " << '\n';
	cout << "	4. If you get 4 Bulls, you have guessed the number and won! " << '\n' << '\n';
	cout << "Enter '10' to give up like bitch." << '\n' << '\n';
}

void ask_for_random_number()
{
	cout << "To start the game, enter a random number: " << '\n';
}

void ask_for_numbers()
{
	cout << "Enter a 4 digit number with each digit(0-9) separated by a space. " << '\n';
}

void display_results(int bulls, int cows)
{
	cout << "Bulls: " << bulls << '\n';
	cout << "Cows: " << cows << '\n';
}

void display_quit_message()
{
	cout << "Better luck next time!" << '\n';
}

void display_exit_message(int attempts)
{
	cout << "Congradulations! You beat the game in only " << attempts << " tries!" << '\n';
}