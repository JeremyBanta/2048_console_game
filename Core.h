#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <chrono>
#include <ctime>

int get_color_number(int block_number);

std::vector<std::vector<int>> arrow_left(std::vector<std::vector<int>> grid, int board_size);

std::vector<std::vector<int>> arrow_right(std::vector<std::vector<int>> grid, int board_size);

std::vector<std::vector<int>> arrow_down(std::vector<std::vector<int>> grid, int board_size);

std::vector<std::vector<int>> arrow_up(std::vector<std::vector<int>> grid, int board_size);

std::vector<int> get_row(std::vector<std::vector<int>> grid, int row_number);

std::vector<int> get_column(std::vector<std::vector<int>> grid, int column_number);

std::vector<int> add_column_or_row(std::vector<int> column_or_row,bool direction);

bool get_game_over(std::vector<std::vector<int>> grid, int board_size);

std::vector<std::vector<int>> add_random_value(std::vector<std::vector<int>> grid, bool add_four, bool add_two, int board_size);

std::vector<std::vector<int>> get_initiaL_board_grid(int square_board_size);

void print(std::vector<std::vector<int>> grid, int board_size, int best_score_ever);

bool get_zero(int number);

int get_score();

void set_score();

void set_score(int block);

std::vector<int> sort_score();

int get_best_score();

int get_best_score(int current_score);

int get_best_score(int current_score, int historic_best);


void make_file_if_empty();

void write_to_file(int best_score);

void animate_screen();

inline bool does_file_exist(const std::string& name);


std::vector<int> vector_without_zero(std::vector<int> vect);

bool matrix_equal(std::vector<std::vector<int>> grid, std::vector<std::vector<int>> new_grid, int board_size);