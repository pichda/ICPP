#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

template <typename T>

class Matrix {
private:
	T** _matrix;
	int rows;
	int columns;

public:
	Matrix(int row, int column);
	Matrix(const Matrix<T>& m);
	~Matrix();
	void SetMatrix(int row, int column, T value);
	void SetMatrixFrom(T* array);
	T& Get(int row, int column);
	const T& Get(int row, int column, int) const;
	Matrix<T> Transposition() const;
	Matrix<T> Product(const Matrix& m) const;
	Matrix<T> Product(T scalar) const;
	Matrix<T> Sum(const Matrix& m) const;
	Matrix<T> Sum(T scalar) const;
	bool IsIdentical(const Matrix& m) const;
	void PrintMatrix()const;

	template<typename R>
	Matrix<R> Parse() const;
};

template<typename T>
inline Matrix<T>::Matrix(int row, int column)
{
	if (row <= 0 || column <= 0) {
		throw std::invalid_argument("row or column is smaller than 1");
	}
	rows = row;
	columns = column;
	_matrix = new T * [rows];

	for (int i = 0; i < rows; i++)
	{
		_matrix[i] = new T[columns];
		for (int j = 0; j < columns; j++)
		{
			_matrix[i][j] = 0;
		}
	}
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& m)
{
	if (m._matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}
	columns = m.columns;
	rows = m.rows;
	_matrix = new T * [rows];

	for (int i = 0; i < m.rows; i++)
	{
		_matrix[i] = new T[m.columns];
		for (int j = 0; j < m.columns; j++)
		{
			_matrix[i][j] = m._matrix[i][j];
		}
	}
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] _matrix[i];
	}
	delete[] _matrix;
}

template<typename T>
inline void Matrix<T>::SetMatrix(int row, int column, T value)
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	if (row > rows || column > columns) {
		std::invalid_argument("invalid row or column");
	}

	_matrix[row][column] = value;
}

template<typename T>
inline void Matrix<T>::SetMatrixFrom(T* array)
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			_matrix[i][j] = array[i + j];
		}
	}
}

template<typename T>
inline T& Matrix<T>::Get(int row, int column)
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	if (row > rows || column > columns) {
		std::invalid_argument("invalid row or column");
	}
	return _matrix[row][column];
}

template<typename T>
inline const T& Matrix<T>::Get(int row, int column, int) const
{
	return Get(row, column);
}

template<typename T>
inline Matrix<T> Matrix<T>::Transposition() const
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	Matrix<T> m{ rows,columns };
	m.columns = rows;
	m.rows = columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m._matrix[j][i] = _matrix[i][j];
		}
	}

	return m;
}

template<typename T>
inline Matrix<T> Matrix<T>::Product(const Matrix& m) const
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	if (!columns == m.rows) {
		std::invalid_argument("invalid matrix size");
	}
	Matrix<T> mult{ rows,columns };
	mult.rows = rows;
	mult.columns = columns;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < m.columns; j++) {
			for (int k = 0; k < columns; k++)
			{
				mult._matrix[i][j] += _matrix[i][k] * m._matrix[k][j];
			}
		}
	}
	return mult;
}

template<typename T>
inline Matrix<T> Matrix<T>::Product(T scalar) const
{
	Matrix<T> m{ rows,columns };
	m.rows = rows;
	m.columns = columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m._matrix[i][j] = _matrix[i][j] * scalar;
		}
	}
	return m;
}

template<typename T>
inline Matrix<T> Matrix<T>::Sum(const Matrix& m) const
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	if (m.rows != rows || m.columns != columns) {
		std::invalid_argument("invalid matrix size");
	}

	Matrix<T> sum{ rows,columns };
	sum.rows = rows;
	sum.columns = columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sum._matrix[i][j] = _matrix[i][j] + m._matrix[i][j];
		}
	}
	return sum;
}

template<typename T>
inline Matrix<T> Matrix<T>::Sum(T scalar) const
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	Matrix sumMatrix = Matrix(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sumMatrix.SetMatrix(i, j, _matrix[i][j] + scalar);
		}
	}
	return sumMatrix;
}

template<typename T>
inline bool Matrix<T>::IsIdentical(const Matrix& m) const
{
	if (_matrix == nullptr || m._matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	if (m.rows != rows || m.columns != columns) {
		std::invalid_argument("invalid matrix size");
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (_matrix[i][j] != m._matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
inline void Matrix<T>::PrintMatrix() const
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
template<typename R>
inline Matrix<R> Matrix<T>::Parse() const
{
	if (_matrix == nullptr) {
		throw std::invalid_argument("Matrix is not set");
	}
	Matrix<R> m = Matrix<R>(rows, columns);

	for (size_t i = 0; i < 10; i++)
	{
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m.SetMatrix(i, j, _matrix[i][j]);
		}
	}

	return m;
}
#endif