// CPP program to decompose a matrix using
// Cholesky Decomposition
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void Cholesky_Decomposition(int matrix[][10], 
									int n)
{
	int lower[n][n];
	memset(lower, 0, sizeof(lower));

	// Decomposing a matrix into Lower Triangular
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int sum = 0;

			if (j == i) // summation for diagonals
			{
				for (int k = 0; k < j; k++)
					sum += pow(lower[j][k], 2);
				lower[j][j] = sqrt(matrix[j][j] -
										sum);
			} else {

				// Evaluating L(i, j) using L(j, j)
				for (int k = 0; k < j; k++)
					sum += (lower[i][k] * lower[j][k]);
				lower[i][j] = (matrix[i][j] - sum) /
									lower[j][j];
			}
		}
	}

	// Displaying Lower Triangular and its Transpose
	cout << setw(6) << " Lower Triangular"
		<< setw(30) << "Transpose" << endl;
	for (int i = 0; i < n; i++) {
		
		// Lower Triangular
		for (int j = 0; j < n; j++)
			cout << setw(6) << lower[i][j] << "\t";
		cout << "\t";
		
		// Transpose of Lower Triangular
		for (int j = 0; j < n; j++)
			cout << setw(6) << lower[j][i] << "\t";
		cout << endl;
	}
}

// Driver Code
int main()
{
	int n = 10;
	int matrix[10][10] = {};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i==j)
				matrix[i][j] = 5;
			else if(abs(i-j) == 1)
				matrix[i][j] = 2;
		}
	}
	matrix[0][0] = 1;
    // for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < n; j++)
	// 	{
	// 		cout<<matrix[i][j]<<"\t";
	// 	}
    //     cout<<"\n";
	// }
	Cholesky_Decomposition(matrix, n);
	return 0;
}
