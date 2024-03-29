#include "Matrix.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintFrameLine(int length);
void PrintMessageInFrame(const string& message);
float** GetRandomData(int row, int column);
void TEST_FILL_BY_VALUE();
void TEST_FILL_BY_DATA();
void TEST_ADDITION();
void TEST_SUBSTRUCTION();
void TEST_MULTIPLICATION_MATRIX();
void TEST_MULTIPLICATION_CONSTANT();
void TEST_DIVISION();
void COLUMN_MODULE_TEST();
void ELEMENT_POWER_TEST();

int main()
{
	TEST_FILL_BY_VALUE();
	TEST_FILL_BY_DATA();
	TEST_ADDITION();
	TEST_SUBSTRUCTION();
	TEST_MULTIPLICATION_MATRIX();
	TEST_MULTIPLICATION_CONSTANT();
	TEST_DIVISION();
	COLUMN_MODULE_TEST();
	ELEMENT_POWER_TEST();
	system("pause");
	return 0;
}
void PrintFrameLine(int length)
{
	cout << "+";
	length -= 2;
	for (int i = 0; i < length; i++)
	{
		cout << "-";
	}
	cout << "+" << endl;
}
void PrintMessageInFrame(const string& message)
{
	PrintFrameLine(message.length() + 4);
	cout << "| " << message << " |" << endl;
	PrintFrameLine(message.length() + 4);
}
float** GetRandomData(int row, int column)
{
	float** matrixData = new float*[row];
	for (int i = 0; i < row; i++)
	{
		matrixData[i] = new float[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrixData[i][j] = -10 + rand() % (22);
		}
	}
	return matrixData;
}
void TEST_FILL_BY_VALUE()
{
	PrintMessageInFrame("FILL BY VALUE TEST");
	Matrix m1;
	Matrix_Allocate(m1, 2, 3);
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_FillByValue(m1, float(1.34));
	Matrix_Display(m1);
	Matrix_Free(m1);
	cout << endl;
	Matrix_Allocate(m1, 4, 3);
	cout << "MATRIX: 4 x 3" << endl;
	Matrix_FillByValue(m1, float(-2.65));
	Matrix_Display(m1);
	Matrix_Free(m1);
}
void TEST_FILL_BY_DATA()
{
	PrintMessageInFrame("FILL BY DATA TEST");
	Matrix m1;
	Matrix_Allocate(m1, 2, 3);
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_FillByData(m1, GetRandomData(2, 3));
	Matrix_Display(m1);
	Matrix_Free(m1);
	cout << endl;
	Matrix_Allocate(m1, 4, 3);
	cout << "MATRIX: 4 x 3" << endl;
	Matrix_FillByData(m1, GetRandomData(4, 3));
	Matrix_Display(m1);
	Matrix_Free(m1);
}
void TEST_ADDITION()
{
	PrintMessageInFrame("ADDITION TEST");
	Matrix m1, m2, m3;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "First Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m1);
	Matrix_Allocate(m2, 2, 3);
	Matrix_FillByData(m2, GetRandomData(2, 3));
	cout << "Second Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m2);
	Matrix_Addition(m1, m2, m3);
	cout << "Result Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m3);
	Matrix_Free(m1);
	Matrix_Free(m2);
	Matrix_Free(m3);
}
void TEST_SUBSTRUCTION()
{
	PrintMessageInFrame("SUBSTRUCTION TEST");
	Matrix m1, m2, m3;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "First Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m1);
	Matrix_Allocate(m2, 2, 3);
	Matrix_FillByData(m2, GetRandomData(2, 3));
	cout << "Second Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m2);
	Matrix_Substruction(m1, m2, m3);
	cout << "Result Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m3);
	Matrix_Free(m1);
	Matrix_Free(m2);
	Matrix_Free(m3);
}
void TEST_MULTIPLICATION_MATRIX()
{
	PrintMessageInFrame("MATRIX MULTIPLICATION TEST");
	Matrix m1, m2, m3;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "First Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m1);
	Matrix_Allocate(m2, 3, 2);
	Matrix_FillByData(m2, GetRandomData(3, 2));
	cout << "Second Matrix:" << endl;
	cout << "MATRIX: 3 x 2" << endl;
	Matrix_Display(m2);
	Matrix_Multiplication(m1, m2, m3);
	cout << "Result Matrix:" << endl;
	cout << "MATRIX: 2 x 2" << endl;
	Matrix_Display(m3);
	Matrix_Free(m1);
	Matrix_Free(m2);
	Matrix_Free(m3);
}
void TEST_MULTIPLICATION_CONSTANT()
{
	PrintMessageInFrame("SCALAR MULTIPLICATION TEST");
	Matrix m1, m2;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m1);
	float scalar = 3;
	Matrix_Multiplication(m1, scalar, m2);
	cout << "Result Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m2);
	Matrix_Free(m1);
	Matrix_Free(m2);
}
void TEST_DIVISION()
{
	PrintMessageInFrame("SCALAR DIVISION TEST");
	Matrix m1, m2;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));

	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m1);
	float scalar = 3;
	Matrix_Division(m1, scalar, m2);
	cout << "Result Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m2);
	Matrix_Free(m1);
	Matrix_Free(m2);
}

void COLUMN_MODULE_TEST() {

	Matrix m1, m2;
	PrintMessageInFrame("COLUMN MODULE TEST");
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m1);

	cout << "Result Matrix:" << endl;
	cout << "MATRIX: 3 x 1" << endl;
	Matrix_Column_Module(m1, m2);
	Matrix_Display(m2);

	Matrix_Free(m1);
	Matrix_Free(m2);

}
void ELEMENT_POWER_TEST() {

	PrintMessageInFrame("ELEMENT POWER TEST");
	Matrix m1, m2;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m1);

	float power = 3;
	Matrix_Element_Power(m1, power, m2);
	cout << "Result Matrix:" << endl;
	cout << "MATRIX: 2 x 3" << endl;
	Matrix_Display(m2);

	Matrix_Free(m1);
	Matrix_Free(m2);
}