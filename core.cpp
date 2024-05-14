#include "Core.h";

namespace player {

	int score = 0;
	std::string filename = "C:\\Users\\Jeremy\\Documents\\Best_Scores.txt";





}


int get_color_number(int block_number) {

	if (block_number == 2) {

		return 8;
	}

	else if (block_number == 4) {

		return 7;
	}

	else if (block_number == 8) {

		return 1;
	}

	else if (block_number == 16) {

		return 2;
	}

	else if (block_number == 32) {

		return 3;

	}

	else if (block_number == 64) {

		return 15;

	}


	else if (block_number == 128) {

		return 24;
	}

	else if (block_number == 256) {

		return 5;
	}

	else if (block_number == 512) {

		return 9;
	}

	else if (block_number == 1024) {

		return 11;
	}

	else if (block_number == 2048) {

		return 10;
	}

	else if (block_number == 4096) {

		return 16;
	}

	else if (block_number == 8192) {

		return 12;
	}

	else {

		return 14;
	}
}

std::vector<std::vector<int>> arrow_left(std::vector<std::vector<int>> grid, int board_size) {

	std::vector<int> row;
	std::vector<std::vector<int>> new_grid;
	new_grid = grid;
	for (int row_number = 0; row_number < board_size; row_number++) {

		row = get_row(grid, row_number);

		row = add_column_or_row(row, true);

		grid[row_number] = row;


	}

	if (!matrix_equal(grid, new_grid, board_size)) {
		grid = add_random_value(grid, true, true, board_size);
	}


	return grid;
}

std::vector<std::vector<int>> arrow_right(std::vector<std::vector<int>> grid, int board_size) {

	std::vector<int> row;
	std::vector<std::vector<int>> new_grid;
	new_grid = grid;
	for (int row_number = 0; row_number < board_size; row_number++) {

		row = get_row(grid, row_number);
		row = add_column_or_row(row, false);
		grid[row_number] = row;

	}

	if (!matrix_equal(grid, new_grid, board_size)) {
		grid = add_random_value(grid, true, true, board_size);
	}

	return grid;
}

std::vector<std::vector<int>> arrow_down(std::vector<std::vector<int>> grid, int board_size) {

	std::vector<int> column;
	std::vector<std::vector<int>> new_grid;
	new_grid = grid;

	for (int index = 0; index < board_size; index++) {

		column = get_column(grid, index);
		column = add_column_or_row(column, false);

		for (int k = 0; k < board_size; k++) {

			grid[k][index] = column[k];
		}

	}

	if (!matrix_equal(grid, new_grid, board_size)) {

		grid = add_random_value(grid, true, true, board_size);
	}


	return grid;
}

std::vector<std::vector<int>> arrow_up(std::vector<std::vector<int>> grid,int board_size) {

	std::vector<int> column;
	std::vector<std::vector<int>> new_grid;
	new_grid = grid;

	for (int index = 0; index < board_size; index++) {


		column = get_column(grid, index);
		column = add_column_or_row(column, true);

		for (int k = 0; k < board_size; k++) {

			grid[k][index] = column[k];
		}
	}

	if (!matrix_equal(grid, new_grid, board_size)) {

		grid = add_random_value(grid, true, true, board_size);
	}

	return grid;
}




std::vector<int> get_row(std::vector<std::vector<int>> grid, int row_number) {

	return grid[row_number];


}

std::vector<int> get_column(std::vector<std::vector<int>> grid, int column_number)
{
	int board_size = 4;
	std::vector<int> column(board_size, 0);


	for (int index = 0; index < board_size; index++) {

		column[index] = grid[index][column_number];

	}

	return column;
}

std::vector<int> get_column(std::vector<std::vector<int>> grid, int column_number, int board_size) {

	std::vector<int> column;


	for (int index = 0; index < board_size; index++) {


		column.push_back(grid[index][column_number]);


	}

	return column;
}

std::vector<int> add_column_or_row(std::vector<int> column_or_row, bool direction) {

	std::vector<int> without_zero;

	without_zero = vector_without_zero(column_or_row);
	
	
	if (without_zero.size() == 0) {

		return column_or_row;
	}
	
	
	std::vector<int> without_zero_copy = without_zero;

		for (int element = 0; element < without_zero.size() - 1; element++) {


			if (without_zero_copy[element + 1] == without_zero_copy[element] and without_zero_copy[element] != 0) {


				set_score(column_or_row[element]);

				if (direction) {
					without_zero_copy[element] = 2 * without_zero_copy[element + 1];
					without_zero_copy[element + 1] = 0;

				}

				else {

					without_zero_copy[element + 1] = 2 * without_zero_copy[element];
					without_zero_copy[element] = 0;
				}
			}

		}
		int difference = column_or_row.size() - without_zero_copy.size();

		for (int counter = 0; counter < difference; counter++) {

			if (direction) {

				without_zero_copy.push_back(0);
			}

			else {
				without_zero_copy.insert(without_zero_copy.begin(), 0);
			}
		}

		std::vector<int> new_row_or_col;

		new_row_or_col = vector_without_zero(without_zero_copy);
		difference = column_or_row.size() - new_row_or_col.size();

		for (int counter = 0; counter < difference; counter++) {

			if (direction) {

				new_row_or_col.push_back(0);
			}

			else {
				new_row_or_col.insert(new_row_or_col.begin(), 0);
			}
		}
		
	

		return new_row_or_col;
	
}



bool get_game_over(std::vector<std::vector<int>> grid, int board_size) {

	std::vector<int> row;
	std::vector<int> column;

	for (int row_or_column = 0; row_or_column < board_size; row_or_column++) {

		row = get_row(grid, row_or_column);

		

	
		column = get_column(grid, row_or_column);

		if (row[board_size - 1] == 0) {

			return false; 
		}

		for (int index = 0; index < board_size - 1; index++) {

			if (row[index] == 0) {

			
				return false;
			}

			if (row[index] == row[index + 1]) {

				return false;
			}

			if (column[index] == column[index + 1]) {

				return false;
			}
		
		}
	}

	return true;
}

std::vector<std::vector<int>> add_random_value(std::vector<std::vector<int>> grid, bool add_four, bool add_two, int board_size) {

	std::vector<int> buffer;
	int count_number = 0;

	if (add_four and add_two) {

		for (int k = 0; k < 100; k++) {

			buffer.push_back(2);

		}

		for (int j = 0; j < 15; j++) {

			buffer.push_back(4);
		}

	}

	else if (add_four) {

		for (int n = 0; n < 40; n++) {

			buffer.push_back(4);

		}

	}

	else if (add_two) {

		for (int m = 0; m < 200; m++) {

			buffer.push_back(2);
		}

	}

	unsigned random_seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(buffer.begin(), buffer.end(), std::default_random_engine(random_seed));
	buffer.resize(1);

	
	
	for (int i = 0; i < board_size; i++) {
		


		for (int j = 0; j < board_size; j++) {

			if (get_zero(grid[i][j])) {

				count_number++;


			}


		}
	}

	if (count_number == 0) {

		return grid;
	}

	std::vector<int> possible_blocks;

	for (int number = 1; number < count_number+1; number++) {

		possible_blocks.push_back(number);
	}

	
	std::shuffle(possible_blocks.begin(), possible_blocks.end(), std::default_random_engine(random_seed));
	possible_blocks.resize(1);
	count_number = possible_blocks[0];

	int iter = 0;
	
	
	for (int rows = 0; rows < board_size; rows++) {

		for (int cols = 0; cols < board_size; cols++) {


			if (get_zero(grid[rows][cols])) {
			
				iter++;

			}

			if (iter == count_number) {

				grid[rows][cols] = buffer[0];

				return grid;
			}
		}
	}

	return grid;
}

std::vector<std::vector<int>> get_initiaL_board_grid(int square_board_size) {

	std::vector<std::vector<int> > grid(
		square_board_size,
		std::vector<int>(square_board_size, 0));

	std::vector<int> buffer;

	for (int k = 0; k < 100; k++) {

		buffer.push_back(2);
	}

	for (int j = 0; j < 10; j++) {

		buffer.push_back(4);

	}

	unsigned random_seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(buffer.begin(), buffer.end(), std::default_random_engine(random_seed));
	buffer.resize(2);

	std::vector<int> possible_value;

	int max_value = square_board_size * square_board_size;

	for (int k = 0; k < max_value; k++) {

		possible_value.push_back(k);
	}

	std::shuffle(possible_value.begin(), possible_value.end(), std::default_random_engine(random_seed));
	possible_value.resize(2);

	int count = 0;

	for (int k = 0; k < 2; k++) {


		grid[possible_value[k] / square_board_size][possible_value[k] % square_board_size] = buffer[k];
	}

	return grid;
	
}


void print(std::vector<std::vector<int>> grid, int board_size,int best_score_ever) {

	board_size = board_size * 2 + 1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	std::cout << "----  " << "Score: " << get_score() << "  ----" << std::endl;
	for (int k = 0; k < board_size; k++) {


		for (int j = 0; j < board_size; j++) {

			

			if (j % 2 == 0) {

				std::cout << "|";

			}

			else if (k % 2 == 0) {

				if (k % 2 == 0 and j % 2 == 0 ) {

					std::cout << "-+- ";
				}
				else {
					std::cout << "-------";
				}

			}

			else {


				int temp = grid[(k - 1) / 2][(j - 1) / 2];

				SetConsoleTextAttribute(hConsole, get_color_number(temp));
				

				if(temp<10) {
					std::cout << "   " << grid[(k - 1) / 2][(j - 1) / 2] << "   ";
				}

				else if (temp < 100) {

					std::cout << "  " << grid[(k - 1) / 2][(j - 1) / 2] << "   ";

				}

				else if (temp < 1000) {

					std::cout << " " << grid[(k - 1) / 2][(j - 1) / 2] << "   ";
				}

				else if (temp < 10000) {

					std::cout << "" << grid[(k - 1) / 2][(j - 1) / 2] << "   ";
				}

				else if (temp < 1e5) {

					std::cout << "" << grid[(k - 1) / 2][(j - 1) / 2] << "  ";
				}

				else if (temp < 1e6) {

					std::cout << "" << grid[(k - 1) / 2][(j - 1) / 2] << " ";
				}

				else {

					std::cout << "" << grid[(k - 1) / 2][(j - 1) / 2] << "";
				}

				SetConsoleTextAttribute(hConsole, 15);


			}
		}

		std::cout << std::endl;

		
	}

	std::cout << "----  " << "High Score: " << best_score_ever << "  ----" << std::endl;


}

bool get_zero(int number) {

	return number == 0;

}


int get_score() {

	return player::score;

}


void set_score() {

	player::score = 0; //reset score
}



void set_score(int block) {

	player::score = get_score() + block * 2;

}



void write_to_file(int best_score) {

	std::fstream top_score;

	top_score.open(player::filename, std::ios_base::app);

	top_score <<std::endl<< best_score;

	top_score.close();

}





std::vector<int> sort_score() {


	std::vector<int> high_score_list;
	 int number_of_scores = 1000;

	std::ifstream file(player::filename);

	std::string line;

	while (std::getline(file, line)) {

		
		if (isdigit(line[0])) {
			
			high_score_list.push_back(std::stoi(line));
		}
	}

	file.close();

	std::sort(high_score_list.begin(), high_score_list.end());

	std::reverse(high_score_list.begin(), high_score_list.end());

	high_score_list.resize(number_of_scores, 0);

	return high_score_list;
}

int get_high_score() {


	

	
	if (does_file_exist(player::filename)) {
		
		
		
		std::ifstream file(player::filename);
		std::string first_line;
		std::getline(file, first_line);
		return std::stoi(first_line);
	}

	return -55;
}


int get_best_score() {

	int current_score = player::score;

	int historic_best = get_high_score();

	if (current_score > historic_best) {

		return current_score;
	}
	
	else {

		return historic_best;
	}
	
}

int get_best_score(int current_score) {

	int historic_best = get_high_score();

	if (historic_best > current_score) {

		return historic_best;
	}

	else {

		return current_score;
	}
}

int get_best_score(int current_score, int historic_best) {

	if (current_score > historic_best) {

		return current_score;
	}

	else {

		return historic_best;
	}
}





void make_file_if_empty() {

	std::string name = player::filename;
	 
	if (!does_file_exist(name)) {
		
		write_to_file(0);

	}
}

inline bool does_file_exist(const std::string& name) {

	std::ifstream file(name.c_str()); 

	return file.good();

}

std::vector<int> vector_without_zero(std::vector<int> vect) {

	std::vector<int> new_vector;

	for (int element : vect) {

		if (element != 0) {
			new_vector.push_back(element);
		}
	}

	return new_vector;
}

bool matrix_equal(std::vector<std::vector<int>> grid, std::vector<std::vector<int>> new_grid,int board_size) {

	std::vector <int> vect;
	std::vector<int> new_vect;
	

	for (int k = 0; k < board_size; k++) {
		
		vect = get_row(grid, k);
		new_vect = get_row(new_grid, k);
	
		for (int index = 0; index < board_size; index++) {

			if (vect[index] != new_vect[index]) {

				
				return false;
			}



		}
		

	}

	return true;
}


void clear_screen() {

	


}