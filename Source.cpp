#include "Header.h"
//����� �������
void printMatrix(const vector<vector<int>>& matrix)
{
    cout << "������� ���������:" << endl;
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
//���������� ������
void generateRandomGraph()
{
    ofstream file("1.txt");
    if (!file)
    {
        cout << "������ �������� �����!" << endl;
        return;
    }
    srand(time(0));
    int n = 3 + rand() % 5; //�� 3 �� 7 ������
    file << n << endl;
    vector<vector<int>> matrix(n, vector<int>(n)); //��� �������� �������
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((rand() % 100) < 30) 
            { // 30% ����������� �����
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
        if ((rand() % 100) < 10) 
        { // 10% ����������� �����
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

//���������� �������� ������
void calculateDegrees()
{
    ifstream file("1.txt");
    if (!file)
    {
        cout << "������ �������� �����!" << endl;
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

    vector<int> degrees(n, 0); //��� �������� ��������
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

    cout << "������� ������:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "������� " << i + 1 << ": ������� " << degrees[i] << endl;
    }
    cout << endl;
}
int getValidIntegerInput() //��������
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
                cout << "������� ������� �����! ������� �����: "<<endl;
            }
        }
        else
        {
            cout << "������, ������� ����� ����� ";
        }
    }
}
//���� � ����������
void createGraphManually()
{

    ofstream file("1.txt");
    if (!file)
    {
        cout << "������ �������� �����!" << endl;
        return;
    }

    int n;
    cout << "������� ���������� ������: ";
    n = getValidIntegerInput();
    file << n << endl;

    cout << "������� ������� �����: " << endl;
    vector<vector<int>> matrix(n, vector<int>(n));
    while (true) 
    {
        int i, j;
        cout << "�����: ";
        cin >> i;
        if (i == 0) break;
        cin>>j;

        if (cin.fail() || i < 1 || j < 1 || i > n || j > n) 
        {
            cout << "�������� ������ ������! ��������� �������� �� 1 �� " << n << endl;
            continue;
        }

        matrix[i - 1][j - 1] = 1;
        matrix[j - 1][i - 1] = 1; //�������������� ��� ������������������ �����
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
