project(lab1-asd)
cmake_minimum_required(VERSION 3.12)   
option(BUILD_TESTS "Build test" ON)

#add_compile_options(-fsanitize=address)
#add_link_options(-fsanitize=address)
add_executable(main main.cpp knapsack.cpp knapsack.h  dynamic_knapsack.cpp dynamic_knapsack.hpp catch.hpp) # ����������� main.exe

if(BUILD_TESTS)
  enable_testing()
  add_executable(test1 test.cpp knapsack.cpp knapsack.h  dynamic_knapsack.cpp dynamic_knapsack.hpp catch.hpp) # ����������� test1.exe
  add_test(test1 test1) # ��������� test1.exe ��� �������� ���������. ���� �������, ���� ��� ���������� ��� 0.
endif()
