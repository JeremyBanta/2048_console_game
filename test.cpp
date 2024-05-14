#include"Test.h"
#include"Core.h"
#include<iostream>


void print_vector(std::vector<int> test_vector) {


	for (int element : test_vector) {

		std::cout << element << " ";
	}

	std::cout << std::endl;
}


void test_write_txt_file() {

	for (int k = 0; k < 3;k++) {
		std::cout << "hello";
		set_score(k);
		write_to_file(get_score());
		sort_score();
	}
}   