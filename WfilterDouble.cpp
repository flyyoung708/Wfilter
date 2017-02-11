#include "Arduino.h"
#include "WfilterDouble.h"


WfilterDouble::WfilterDouble() {
	numReadingsCollected = 20;
	outliersRemoved = 4;
	Setup(numReadingsCollected, outliersRemoved);
}

WfilterDouble::WfilterDouble(int numReadingsCollected) {
	numReadingsCollected = numReadingsCollected;
	if (numReadingsCollected < 3)
		outliersRemoved = 1;
	else
		outliersRemoved = numReadingsCollected / 4;
	Setup(numReadingsCollected, outliersRemoved);
}

WfilterDouble::WfilterDouble(int numReadingsCollected, int outliersRemoved) {
	numReadingsCollected = numReadingsCollected;
	outliersRemoved = outliersRemoved;
	Setup(numReadingsCollected, outliersRemoved);
}

WfilterDouble::~WfilterDouble() {
	delete[] _valArray;
	delete[] _valArrayin;
}


double WfilterDouble::filtered(double reading) {
	_reading = reading;

	_valArrayin[_i] = _reading;

	for (int k = 0; k < arraysize; k++) {
		_valArray[k] = _valArrayin[k];
	}

	for (int k = 0; k < _outliers; k++) {
		_maxval = -1000000;
		_minval = 1000000;
		_maxvalind = 0;
		_minvalind = 0;
		for (int j = 0; j < arraysize; j++) {
			if (_valArray[j] >= _maxval) {
				_maxvalind = j;
				_maxval = _valArray[j];
			}
			if (_valArray[j] <= _minval) {
				_minvalind = j;
				_minval = _valArray[j];

			}
		}

		_valArray[_maxvalind] = _val;
		_valArray[_minvalind] = _val;

	}

	_sum = 0;
	for (int r = 0; r < arraysize; r++) {
		_sum += _valArray[r];
	}

	_val = _sum/divider;

	_i++;
	if (_i >= arraysize) {
		_i = 0;
	}

	return _val;
}

void WfilterDouble::Setup(int numReadingsCollected, int outliersRemoved) {
	_valArrayin = new double[numReadingsCollected];
	_valArray = new double[numReadingsCollected];
	//std::cout << _valArrayin << std::endl; 
	//std::cout << _valArray << std::endl; 
		arraysize = numReadingsCollected;
		divider = arraysize;
		_outliers = outliersRemoved;
		_val = 0;
		_i = 0;
}