all: compile run 

compile: 
	@g++ -std=c++11 unit_tests.cpp linked_list.cpp -o test_linked_list

run:
	@./test_linked_list

clean: 
	@rm test_linked_list