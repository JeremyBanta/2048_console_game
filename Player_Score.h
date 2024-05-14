#pragma once

class Player_Score {

public:

	static int total_score;
	static int block;

	static int get_score() {

		return total_score;
	}

	static int get_block() {

		return block;
	}

	static void set_score(int new_score) {

		total_score = new_score;
	}

	static void set_block(int new_block) {

		block = new_block;
	}

	Player_Score() {

		total_score = 0;

	}
};