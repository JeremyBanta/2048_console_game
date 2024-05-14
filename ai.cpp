#include"Core.h"
#include"AI.h"
#include<iostream>




random_mover::random_mover() {

	random_mover::avg_score = 0;
	random_mover::best_score_ever = 0;
	random_mover::board_size = 4;
	random_mover::board_state = get_initiaL_board_grid(4);
	random_mover::score = 0;
	random_mover::worst_score = 0;
	random_mover::number_of_games = 1e6;

}


std::vector<int> random_mover::get_random_directions(std::vector<std::vector<int>> grid,int board_size) {

	std::vector<int> output;

	for (int k = 0; k < board_size; k++) {

		std::vector<std::vector<int>> grid = random_mover::get_state();
		std::vector<std::vector<int>> temp;

		if (k == 0) {

			temp = arrow_up(grid, board_size);

			if (!matrix_equal(temp, grid, board_size)) {

				output.push_back(k);
			}

		}

		else if (k == 1) {

			temp = arrow_down(grid, board_size);

			if (!matrix_equal(temp, grid, board_size)) {

				output.push_back(k);
			}

		}

		else if (k == 2) {

			temp = arrow_up(grid, board_size);

			if (!matrix_equal(temp, grid, board_size)) {

				output.push_back(k);
			}

		}

		else if (k == 3) {

			temp = arrow_up(grid, board_size);

			if (!matrix_equal(temp, grid, board_size)) {

				output.push_back(k);

			}

		}
	}
	return output;
}

std::vector<std::vector<int>> random_mover::get_state() {

	return random_mover::board_state;
}

void random_mover::set_board_state(std::vector<std::vector<int>> grid) {

	random_mover::board_state = grid;
}

void random_mover::set_file_name(std::string filename) {

	random_mover::filename_random_mover = filename;
}