#ifndef WfilterDouble_H
#define WfilterDouble_H

#include "Arduino.h"


class WfilterDouble
{ 
public:
	WfilterDouble(int check);
	double filtered(double reading);
private:
	double _reading;
	double _outliers;
	double _val;
	double _valArrayin[10];
	double _valArray[10];
	int _init;
	double _maxval;
	double _minval;
	int _maxvalind;
	int _minvalind;
	unsigned long _sum;
	int _i;
	int _w;
	int _k;
	int _z;
	int _j;
	int _r;
};

#endif