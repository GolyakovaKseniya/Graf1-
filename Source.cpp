#include "Header.h"
//вывод матрицы
void printMatrix(const vector<vector<int>>& matrix)
{
    cout << "Матрица смежности:" << endl;
    cout << "   ";
    for (size_t j = 0; j < matrix.size(); j++)
    {
        cout << setw(3) << j + 1;
    }
    cout << "\n   ";
    for (size_t j = 0; j < matrix.size(); j++)
    {
        cout << "---";
    }
    cout << endl;

    for (size_t i = 0; i < matrix.size(); i++)
    {
        cout << setw(2) << i + 1 << "|";
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}
//заполнение рандом
void generateRandomGraph()
{
    ofstream file("1.txt");
    if (!file)
    {
        cout << "Ошибка создания файла!" << endl;
        return;
    }
    srand(time(0));
    int n = 3 + rand() % 5; //от 3 до 7 вершин
    file << n << endl;
    vector<vector<int>> matrix(n, vector<int>(n)); //для хранения матрицы
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((rand() % 100) < 30) 
            { // 30% вероятность ребра
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
        if ((rand() % 100) < 10) 
        { // 10% вероятность петли
            matrix[i][i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }
    printMatrix(matrix);
}

//вычисление степеней вершин
void calculateDegrees()
{
    ifstream file("1.txt");
    if (!file)
    {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    int n;
    file >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> matrix[i][j];
        }
    }

    vector<int> degrees(n, 0); //для подсчета степеней
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (i == j)
                {
                    degrees[i] += 2;
                }
                else
                {
                    degrees[i] += 1;
                }
            }
        }
    }

    cout << "Степени вершин:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Вершина " << i + 1 << ": степень " << degrees[i] << endl;
    }
    cout << endl;
}
int getValidIntegerInput() //проверка
{

    while (true)
    {
        string l;
        getline(cin, l);
        istringstream iss(l);
        int data;
        char c;
        if (iss >> data && !(iss >> c))
        {
            if (data <= 100000)
            {
                return data;
            }   
            else
            {
                cout << "Слишком большое число! Введите снова: "<<endl;
            }
        }
        else
        {
            cout << "Ошибка, введите целое число ";
        }
    }
}
//ввод с клавиатуры
void createGraphManually()
{

    ofstream file("1.txt");
    if (!file)
    {
        cout << "Ошибка создания файла!" << endl;
        return;
    }

    int n;
    cout << "Введите количество вершин: ";
    n = getValidIntegerInput();
    file << n << endl;

    cout << "Введите смежные ребра: " << endl;
    vector<vector<int>> matrix(n, vector<int>(n));
    while (true) 
    {
        int i, j;
        cout << "Ребро: ";
        cin >> i;
        if (i == 0) break;
        cin>>j;

        if (cin.fail() || i < 1 || j < 1 || i > n || j > n) 
        {
            cout << "Неверные номера вершин! Допустимы значения от 1 до " << n << endl;
            continue;
        }

        matrix[i - 1][j - 1] = 1;
        matrix[j - 1][i - 1] = 1; //симметричность для неориентированного графа
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }

    printMatrix(matrix);
}
