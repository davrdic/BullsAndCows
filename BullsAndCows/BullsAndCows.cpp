#include"Game_Functions.h"

using std::vector;
using std::runtime_error;
using std::cerr;

int main()
try{
	vector<int> master_vector(max_digits);
	vector<int> guess_vector(max_digits);
	vector<bool> master_match_bools(max_digits);

	bool end_of_game = false;

	int bulls = 0;
	int cows = 0;
	int attempts = 0;

	display_welcome_message();

	master_vector = get_master_vector();

	while (!end_of_game)
	{
		attempts += 1;
		guess_vector = get_guess_vector();
		master_match_bools = get_master_match_bools(master_vector, guess_vector);
		bulls = count_bulls(master_match_bools);
		cows = count_cows(master_vector, guess_vector, master_match_bools);
		display_results(bulls, cows);
		end_of_game = check_for_end_of_game(master_match_bools);
		if (end_of_game)
			display_exit_message(attempts);
	}
	return 0;
}
catch (runtime_error& e) {
	cerr << "RUNTIME ERROR: " << e.what() << '\n';
}