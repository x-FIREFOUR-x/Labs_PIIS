#include "SimplexMethod.h"

SimplexMethod::SimplexMethod(vector<vector<float>>& A, vector<float> B, vector<float> C)
{
	this->A = A;
	this->B = B;
	this->C = C;
}

void SimplexMethod::print() 
{
    for (int i = 0; i < A.size(); i++) 
    {
        for (int j = 0; j < A[i].size(); j++) 
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void SimplexMethod::CalculateSimplex()
{
    bool is_finish = false;

    cout << "initial array(Not optimal)" << endl;
    print();

    cout << " " << endl;
    cout << "final array(Optimal solution)" << endl;


    while (!is_finish) 
    {
        is_finish = simplex_algorithm_calculataion();
    }
    cout << "Answers for the Constraints of variables" << endl;

    for (int i = 0; i < A.size(); i++) 
    {  //every basic column has the values, get it form B array
        int count0 = 0;
        int index = 0;
        for (int j = 0; j < A.size(); j++) 
        {
            if (A[j][i] == 0.0) 
            {
                count0 += 1;
            }
            else if (A[j][i] == 1) 
            {
                index = j;
            }
        }

        if (count0 == A.size() - 1) {

            cout << "variable" << index + 1 << ": " << B[index] << endl;  //every basic column has the values, get it form B array
        }
        else {
            cout << "variable" << index + 1 << ": " << 0 << endl;

        }

    }


    cout << "" << endl;
    cout << "maximum value: " << maximum << endl;  //print the maximum values
}




bool SimplexMethod::simplex_algorithm_calculataion()
{
    //check whether the table is optimal,if optimal no need to process further
    if (check_optimality() == true) {
        return true;
    }
    
    if (is_unbounded == true) {
        cout << "Error unbounded" << endl;
        return true;
    }

    //find the column which has the pivot.The least coefficient of the objective function(C array).
    int pivot_column = find_pivot_column();
    //find the row with the pivot value.The least value item's row in the B array
    int pivot_row = find_pivot_row(pivot_column);

    //form the next table according to the pivot value
    make_pivotting(pivot_row, pivot_column);

    return false;
}

bool SimplexMethod::check_optimality()
{
    bool is_optimal = false;
    int amount_positve_value = 0;

    //check if the coefficients of the objective function are negative
    for (int i = 0; i < C.size(); i++) 
    {
        float value = C[i];
        if (value >= 0) 
        {
            amount_positve_value++;
        }
    }

    //if all the constraints are positive now,the table is optimal
    if (amount_positve_value == C.size()) 
    {
        is_optimal = true;
        print();
    }
    return is_optimal;
}

void SimplexMethod::make_pivotting(int pivot_row, int pivot_column)
{
    float pivot_value = A[pivot_row][pivot_column];
    vector<float> pivot_row_values;
    vector<float> pivot_column_values;
    vector<float> new_row;

    maximum = maximum - (C[pivot_column] * (B[pivot_row] / pivot_value));  //set the maximum step by step

     //get the row that has the pivot value
    for (int i = 0; i < A[0].size(); i++) 
    {
        pivot_row_values.push_back(A[pivot_row][i]);
    }
    //get the column that has the pivot value
    for (int j = 0; j < A.size(); j++) 
    {
        pivot_column_values.push_back(A[j][pivot_column]);
    }

    //set the row values that has the pivot value divided by the pivot value and put into new row
    for (int k = 0; k < A[0].size(); k++) 
    {
        new_row.push_back(pivot_row_values[k] / pivot_value);
    }

    B[pivot_row] = B[pivot_row] / pivot_value;


    //process the other coefficients in the A array by subtracting
    for (int i = 0; i < A.size(); i++) 
    {
        //ignore the pivot row as we already calculated that
        if (i != pivot_row) 
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                A[i][j] = A[i][j] - (pivot_column_values[i] * new_row[j]);
                //C[p] = C[p] - (multiplyValue*C[pivotRow]);
                //B[i] = B[i] - (multiplyValue*B[pivotRow]);
            }
        }
    }

    //process the values of the B array
    for (int i = 0; i < B.size(); i++) 
    {
        if (i != pivot_row)
        {
            B[i] = B[i] - (pivot_column_values[i] * B[pivot_row]);
        }
    }

    //the least coefficient of the constraints of the objective function
    //float multiplyValue = C[pivotColumn];
    //process the C array
    for (int i = 0; i < C.size(); i++) 
    {
        C[i] = C[i] - (C[pivot_column] * new_row[i]);
    }

    //replacing the pivot row in the new calculated A array
    for (int i = 0; i < A[0].size(); i++) 
    {
        A[pivot_row][i] = new_row[i];
    }

}

int SimplexMethod::find_pivot_column()
{
    int index = 0;
    float minm = C[0];

    for (int i = 1; i < C.size(); i++) 
    {
        if (C[i] < minm) {
            minm = C[i];
            index = i;
        }
    }
    return index;
}

int SimplexMethod::find_pivot_row(int pivot_column)
{
    vector<float> positive_values;
    int amount_negative_value = 0;
    for (int i = 0; i < A.size(); i++) 
    {
        if (A[i][pivot_column] > 0) 
        {
            positive_values.push_back(A[i][pivot_column]);
        }
        else 
        {
            positive_values.push_back(0);
            amount_negative_value += 1;
        }
    }

    //checking the unbound condition if all the values are negative ones
    vector<float> result;
    if (amount_negative_value == A.size()) 
    {
        is_unbounded = true;
    }
    else 
    {
        for (int i = 0; i < A.size(); i++) 
        {
            float value = positive_values[i];
            if (value > 0) 
            {
                result.push_back(B[i] / value);
            }
            else 
            {
                result.push_back(0);
            }
        }
    }

    //find the minimum's location of the smallest item of the B array
    float minimum = 100000;
    int index = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (result[i] > 0) 
        {
            if (result[i] < minimum) 
            {
                minimum = result[i];
                index = i;
            }
        }

    }
    return index;
}
