#include "pch.h"

using namespace System;

array<int, 2>^ MultiplyMatrixes(array<int, 2>^ A, array<int, 2>^ B) {
    int rowsA = A->GetLength(0);
    int colsA = A->GetLength(1);
    int rowsB = B->GetLength(0);
    int colsB = B->GetLength(1);

    // Перевірка
    if (colsA != rowsB) {
        throw gcnew ArgumentException("Matrices cannot be multiplied. Invalid dimensions.");
    }
        // Результуюча матриця
        array<int, 2>^ result = gcnew array<int, 2>(rowsA, colsB);

        // Множення матриць
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                result[i, j] = 0;
                for (int k = 0; k < colsA; k++) {
                    result[i, j] += A[i, k] * B[k, j];
                }
            }
        }

    return result;
}

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Task 1");
    float pi = Math::PI, n = 0.0018, P = 0.02;
    float V;
    int l = 2;
    array<double>^ R = gcnew array<double>{0.108, 0.114, 0.133, 0.159, 0.168, 0.219, 0.273, 0.325, 0.426, 0.53};

    for (int i = 0; i < 10; i ++) {
        V = ((pi * Math::Pow(R[i], 4)) / (8 * n * l)) * P;
        Console::WriteLine(L"Znachenya V = " + V + L" pri R = " + R[i]);
    }

    Console::WriteLine(L"\nTask 2");

    array<int, 2>^ A = gcnew array<int, 2>(3, 3);
    A[0, 0] = 5; A[0, 1] = 3; A[0, 2] = 2; 
    A[1, 0] = 9; A[1, 1] = 11; A[1, 2] = 1;
    A[2, 0] = 4; A[2, 1] = 7; A[2, 2] = 8;

    array<int, 2>^ B = gcnew array<int, 2>(3, 3);
    B[0, 0] = 1; B[0, 1] = 2; B[0, 2] = 3;
    B[1, 0] = 4; B[1, 1] = 5; B[1, 2] = 6;
    B[2, 0] = 7; B[2, 1] = 8; B[2, 2] = 9;

    array<int, 2>^ result = MultiplyMatrixes(A, B);
    
    // Вивід результату
    Console::WriteLine("Result multiply matrixes:");
    for (int i = 0; i < result->GetLength(0); i++) {
        for (int j = 0; j < result->GetLength(1); j++) {
            Console::Write(result[i, j] + " ");
        }
        Console::WriteLine();
    }

    return 0;
}
