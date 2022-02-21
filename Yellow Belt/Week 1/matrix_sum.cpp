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
        if ((num_rows < 0) || (num_cols < 0))
        {
            throw std::out_of_range("");
        }
        if ((num_rows == 0) || (num_cols == 0))
        {
            matrix.resize(0);
        }
        else
        {
            matrix.resize(num_rows);
            for(auto& row : matrix)
            {
                row.resize(num_cols);
            }
        }   
    }

    void Reset (int num_rows, int num_cols)
    {
        if ((num_rows < 0) || (num_cols < 0))
        {
            throw std::out_of_range("");
        }
        if ((num_rows == 0) || (num_cols == 0))
        {
            matrix.resize(0);
        }
        else
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
    }

    int At(int row,int cols) const
    {
        if ((row > GetNumRows()-1) || (cols > GetNumColumns()-1))
        {
            throw std::out_of_range("");
        }
        else if ((row < 0) || (cols < 0))
        {
            throw std::out_of_range("");
        }

        return matrix.at(row).at(cols);
    }

    int& At(int row,int cols)
    {
        if ((row > GetNumRows()-1) || (cols > GetNumColumns()-1))
        {
            throw std::out_of_range("");
        }
        else if ((row < 0) || (cols < 0))
        {
            throw std::out_of_range("");
        }
        return matrix[row][cols];

    }

    int GetNumRows(void) const
    {
        return matrix.size();
    }

    int GetNumColumns(void) const
    {
        if (matrix.size()!= 0)
        {
            return matrix.at(0).size();
        }
        else
        {
            return 0;
        }
        
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

istream& operator>>(istream& stream,  Matrix& m)
{
    int rows,cols;
    stream >> rows >> cols;
    Matrix matrix(rows,cols);

    if ((rows == 0) || (cols == 0))
    {
        matrix.Reset(0,0);
    }
    else
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                stream >> matrix.At(i,j);
            }
        }
    }

    m = matrix;
    return stream;
}

ostream& operator<<(ostream& stream, const Matrix& m)
{
    stream << m.GetNumRows() <<" "<<m.GetNumColumns() << endl;

    for(int i=0;i<m.GetNumRows();i++)
    {
        for(int j=0;j<m.GetNumColumns();j++)
        {
            stream << m.At(i,j);
            if(j == m.GetNumColumns()-1)
            {
                stream << endl;
            }
            else
            {
                stream << " ";
            }
        }
    }

    return stream;
}

bool operator==(const Matrix& lm, const Matrix& rm)
{
    bool result = true;
    if ((lm.GetNumRows() == 0) && (rm.GetNumRows() == 0) )
    {
        result = true;
    } 
    else if ((lm.GetNumRows() == rm.GetNumRows()) && (lm.GetNumColumns() == rm.GetNumColumns()))
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

Matrix operator+(const Matrix& lm, const Matrix& rm)
{
    Matrix matrix(lm.GetNumRows(),lm.GetNumColumns());
    if ((lm.GetNumRows() == 0)  &&  (rm.GetNumRows() == 0))
    {
        matrix.Reset(0,0);
    } 
   else if ((lm.GetNumRows() == rm.GetNumRows()) && (lm.GetNumColumns() == rm.GetNumColumns()))
    {
        for(int i=0;i<lm.GetNumRows();i++)
        {
            for(int j=0;j<lm.GetNumColumns();j++)
            {
               matrix.At(i,j) = lm.At(i,j) + rm.At(i,j);
               
            }
        }
    }
    else
    {
        throw std::invalid_argument("");
    }

    return matrix;
}


int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
 
  return 0;
}
