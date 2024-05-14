// version_2048.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include "core.h"
#include "Test.h"
#include"AI.h"
constexpr auto KEY_UP = 72;;
constexpr auto KEY_DOWN = 80;;
constexpr auto KEY_RIGHT = 77;;
constexpr auto KEY_LEFT = 75;;




int main()
{

   // random_mover random_bot=random_mover();
    
    bool no_test = true;
    int board_size = 4; //default size
    int c = 0;
    int historic_best_score_ever = sort_score()[0];

    std::vector<std::vector<int>> grid = get_initiaL_board_grid(board_size);
    make_file_if_empty();
    
    print(grid, board_size,get_best_score(get_score(),historic_best_score_ever));
    
    while (true) {

        while (true) {

            c = _getch();

            if (c == KEY_UP) {

                grid = arrow_up(grid, board_size);
               
                print(grid, board_size,get_best_score(get_score(),historic_best_score_ever));

                c = 0;

                break;
            }

            else if (c == KEY_DOWN) {

                grid=arrow_down(grid, board_size);

                print(grid, board_size,get_best_score(get_score(),historic_best_score_ever));

                c = 0;
                break;
            }

            else if (c == KEY_RIGHT) {

                grid = arrow_right(grid, board_size);

                print(grid, board_size,get_best_score(get_score(),historic_best_score_ever));
                c = 0;
                break;
            }

            else if (c == KEY_LEFT) {

                grid = arrow_left(grid, board_size);

                print(grid, board_size,get_best_score(get_score(),historic_best_score_ever));
                c = 0;
                break;

            }



        }

        if (get_game_over(grid,board_size)) {

            std::string input;
            std::cout << std::endl << "enter q or Q to quit any other key plays again. ";
            std::cin >> input;

            if (input == "q" || input == "Q") {

                write_to_file(get_score());
                int historic_high_score=sort_score()[0];

                break;
            }

            else {

                write_to_file(get_score());
                int historic_high_score=sort_score()[0];
                set_score();
                grid = get_initiaL_board_grid(board_size);
                int best_score_ever = get_best_score(get_score(), historic_high_score);
                print(grid,board_size,best_score_ever);
            }
        }
    }

   
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
