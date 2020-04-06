#include<iostream>
#include"Constants.h"
#include"Random.h"
#include"Messages.h"

using std::cin;
using std::vector;
using std::runtime_error;
using std::cerr;

vector<bool> init_match_bools()
{
	vector<bool> answers;
	for (int i = 0; i < max_ints; i++)
		answers.push_back(false);
	return answers;
}

void quit_game()
{
	display_quit_message();
	exit(0);
}

vector<int> get_master_vector()
{
	vector<int> master_vector;
	int seed;

	ask_for_random_number();

	cin >> seed;

	if (!cin) throw runtime_error("bad input for seed. ");
	if (seed == quit) quit_game();

	seed_randint(seed);

	for (int i = 0; i < max_digits; i++)
		master_vector.push_back(randint(9));
	return master_vector;
}

vector<int> get_guess_vector()
{
	vector<int> guess_vector;
	int guess = -1;

	ask_for_numbers();

	for (int i = 0; i < max_digits; i++) {
		cin >> guess;

		if (!cin) throw runtime_error("bad input");
		if (guess == quit) quit_game();
		if (guess < 0 || guess > 10) throw runtime_error("bad input");

		guess_vector.push_back(guess);
	}
	return guess_vector;
}

vector<bool> get_master_match_bools(vector<int> master_vector, vector<int> guess_vector)
{
	vector<bool> master_match_bools;

	master_match_bools = init_match_bools();

	for (int i = 0; i < max_digits; i++) 
		if (guess_vector[i] == master_vector[i])
			master_match_bools[i] = true;
	return master_match_bools;
}

int count_bulls(vector<bool> master_match_bools)
{
	int bulls = 0;
	for (int i = 0; i < max_digits; i++)
		if (master_match_bools[i])
			bulls += 1;
	return bulls;
}

int count_cows(vector<int> master_vector, vector<int> guess_vector, vector<bool> master_match_bools)
{
	int cows = 0;
	vector<bool> guess_match_bools = master_match_bools;

	for (int i = 0; i < max_digits; i++) {
		for (int j = 0; j < max_digits; j++) {
			if (guess_vector[j] == master_vector[i] && !guess_match_bools[j] && !master_match_bools[i]) {
				cows += 1;
				guess_match_bools[j] = true;
				master_match_bools[i] = true;
				break;
			}
		}
	}
	return cows;
}

bool check_for_end_of_game(vector<bool> bull_vector)
{
	if (bull_vector[slot_one] && bull_vector[slot_two] && bull_vector[slot_three] && bull_vector[slot_four])
		return true;
	else
		return false;
}