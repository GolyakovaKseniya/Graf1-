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

//����� �������
void printMatrix(const vector<vector<int>>& matrix);
//����� ������
void generateRandomGraph();
//���������� �������� ������
void calculateDegrees();
//��������
int getValidIntegerInput();
//���� � ����������
void createGraphManually();
