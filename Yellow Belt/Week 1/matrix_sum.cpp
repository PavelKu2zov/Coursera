#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{

public:
    Matrix()
    {
        matrix.resize(0);
    }
    Matrix(int num_rows, int num_cols)
    {
        matrix.resize(num_rows);
        for(auto& row : matrix)
        {
            row.resize(num_cols);
        }
    }

    void Reset (int num_rows, int num_cols)
    {
        matrix.resize(num_rows);
        for(auto& row : matrix)
        {
            row.resize(num_cols);
            for(int i=0;i<num_cols;i++)
            {
                row[i]= 0;
            }
        }
    }

    int At(int row,int cols) const
    {
        return matrix.at(row).at(cols);
    }

    int& At(int row,int cols)
    {
        return matrix[row][cols];
    }

    int GetNumRows(void) const
    {
        return matrix.size();
    }

    int GetNumColumns(void) const
    {
        return matrix.at(0).size();
    }

private:
    vector<vector<int>> matrix;

};

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

istream& operator>>(istream& stream, Matrix& m)
{
    int rows,cols;
    cin >> rows >> cols;
    Matrix matrix(rows,cols);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin >>matrix.At(i,j);
        }
    }

    m = matrix;
    return stream;
}

ostream& operator<<(ostream& stream, Matrix& m)
{
    cout << m.GetNumRows() <<" "<<m.GetNumColumns() << endl;

    for(int i=0;i<m.GetNumRows();i++)
    {
        for(int j=0;j<m.GetNumRows();j++)
        {
            cout << m.At(i,j);
            if(j == m.GetNumRows()-1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }

    return stream;
}

bool operator==(Matrix& lm, Matrix& rm)
{
    bool result = true;
    if ((lm.GetNumRows() == rm.GetNumRows()) && (lm.GetNumColumns() == rm.GetNumColumns()))
    {
        for(int i=0;i<lm.GetNumRows();i++)
        {
            for(int j=0;j<lm.GetNumColumns();j++)
            {
                if(lm.At(i,j) != rm.At(i,j))
                {
                    result = false;
                    break;
                }
            }
            if (result == false)
            {
                break;
            }
        }
    }
    else
    {
        result = false;
    }

    return result;
}

Matrix operator+(Matrix& lm, Matrix& rm)
{
    Matrix matrix(lm.GetNumRows(),lm.GetNumColumns());
    if ((lm.GetNumRows() == rm.GetNumRows()) && (lm.GetNumColumns() == rm.GetNumColumns()))
    {
        for(int i=0;i<lm.GetNumRows();i++)
        {
            for(int j=0;j<lm.GetNumColumns();j++)
            {
               matrix.At(i,j) = lm.At(i,j) + rm.At(i,j);
               
            }
        }
    }

    return matrix;
}


int main() {
  Matrix one;
  Matrix two;
  Matrix tree;  

  cin >> one >> two;
  tree = one + two;
  cout << one+two << endl;
  /*if (one == two)  
  cout << "equle";
  else
  cout << "not equal";*/
  return 0;
}
