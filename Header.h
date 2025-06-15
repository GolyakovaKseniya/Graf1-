#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//вывод матрицы
void printMatrix(const vector<vector<int>>& matrix);
//вывод рандом
void generateRandomGraph();
//вычисление степеней вершин
void calculateDegrees();
//проверка
int getValidIntegerInput();
//ввод с клавиатуры
void createGraphManually();
