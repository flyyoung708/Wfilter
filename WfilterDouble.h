#ifndef WfilterDouble_H
#define WfilterDouble_H

#include "Arduino.h"

class WfilterDouble
{
public:
	WfilterDouble();
	~WfilterDouble();
	WfilterDouble(int numReadingsCollected);
	WfilterDouble(int numReadingsCollected, int outliersRemoved);
	double filtered(double reading);

private:
	int numReadingsCollected;
	int outliersRemoved;
	double _reading;
	double _val;
	double * _valArrayin;
	double * _valArray;
	double _maxval;
	double _minval;
	int _maxvalind;
	int _minvalind;
	unsigned long _sum;
	int _i;
	int arraysize;
	int _outliers;
	double divider; 

	void Setup(int numReadingsCollected, int outliersRemoved);
};

#endif