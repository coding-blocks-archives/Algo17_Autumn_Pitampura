#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

template <typename T>
void setArrayWithValue(T* array, int size, T value) {
	for (int i = 0; i < size; i++) {
		array[i] = value;
	}
}

template <typename T>
void matInput(T** array, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		array[i] = new T[cols];
		for (int j = 0; j < cols; j++) {
			cin >> array[i][j];
		}
	}
}

template <typename T>
void initMat(T** array, int rows, int cols, int value = 0) {
	for (int i = 0; i < rows; i++) {
		array[i] = new T[cols];
		for (int j = 0; j < cols; j++) {
			array[i][j] = value;
		}
	}
}

#endif