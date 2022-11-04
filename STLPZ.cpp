#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <random>
#include <numeric>
#include <iomanip>

using namespace std;

#pragma warning(disable : 4996)
void NumRep(const string& input)
{
    map<string, int> strnum;
    char* unic = strtok(const_cast<char*>(input.c_str()), " ");

    while (unic != nullptr)
    {
        if (!strnum.count(unic))
        {
            strnum[unic] = 1;
            unic = strtok(NULL, " ");
        }
        else
        {
            strnum[unic] += 1;
            unic = strtok(NULL, " ");
        }
    }
    map <string, int>::iterator it = strnum.begin();
    for (int i = 0; it != strnum.end(); it++, i++)
    {
        cout << i << ") String: " << it->first << ", Amount: " << it->second << endl;
    }
}

double GetArithmMean(vector<int> *V)
{
    return accumulate(V->begin(), V->end(), 0.0) / V->size();
}

void VectorFunc(int size1, int size2)
{
    //value limits
    int high = 100, low = -100;

    vector<int> V1, V2;
    V1.reserve(size1);
    V2.reserve(size2);

    //init vector1
    for (int i = 0; i < size1; i++)
        V1.push_back(rand() % (high - low + 1) + low);

    //init vector2
    for (int i = 0; i < size2; i++)
        V2.push_back(rand() % (high - low + 1) + low);
    
    cout << "Vector 1: ";
    for (int i = 0; i < size1; i++)
        cout << V1[i] << " ";
    cout << endl;

    cout << "Vector 2: ";
    for (int i = 0; i < size2; i++)
        cout << V2[i] << " ";
    cout << endl;

    cout << "The arithmetic mean vector 1: " << GetArithmMean(&V1) << endl;
    cout << "The arithmetic mean vector 2: " << GetArithmMean(&V2) << endl;

    //Vector compare
    if (V1 != V2)
    {
        cout << "Equal values: ";
        int flag = 0;
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if (V1[i] == V2[j])
                {
                    cout << V1[i] << " ";
                    flag = 1;
                }
            }
        }
        if (!flag)
            cout << "nothing :(";

        cout << endl;
    }
}

void MatrOut(vector<vector<int>> &Matrix)
{
    cout << "+---+";
    for (int k = 0; k < Matrix.size() - 1; k++)
        cout << "---+";
    cout << endl;
    for (int i = 0; i < Matrix.size(); i++)
    {
        for (int j = 0; j < Matrix.size(); j++)
            cout << setw(3) << Matrix[i][j] << " ";
        cout << endl;

        cout << "+---+";
        for (int k = 0; k < Matrix.size() - 1; k++)
            cout << "---+";
        cout << endl;
    }
    cout << endl;
}

void ReachMatrix()
{
    int N = 0;
    //Number of elements
    cin >> N; 
    cin.ignore(256, '\n');

    vector< vector<int> > GraphMatr(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " --> ";
        
        string input;
        getline(cin, input);

        stringstream ss(input);
        int j = 0;

        while (ss >> j)
        {
            if (j) GraphMatr[i][j-1] = 1;
        }
        cout << endl;
    }

    MatrOut(GraphMatr);

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                GraphMatr[i][j] = (GraphMatr[i][j] || (GraphMatr[i][k] && GraphMatr[k][j]));

    for (int i = 0; i < N; i++)
        GraphMatr[i][i] = 1;

    MatrOut(GraphMatr);
}

int main()
{
    string Input = "bob mom dod kok lol pop bob pop lol";
    NumRep(Input);

    ////--------------------
    
    int size1 = 0, size2 = 0;
    cout << "Enter the sizes of Vectors: ";
    cin >> size1; cin >> size2;
    VectorFunc(size1, size2);

    //--------------------

    ReachMatrix();

    //--------------------

    return 32;
}