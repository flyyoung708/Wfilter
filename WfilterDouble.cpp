#include "Arduino.h"
#include "WfilterDouble.h"


WfilterDouble::WfilterDouble(int check){
_outliers = 3;
_val = 0;
_init = 0;
_i = 0;
}


double WfilterDouble::filtered(double reading){
_reading = reading;
if (_init == 0){
  delay(1000);
  for (int _w = 0; _w < 10; _w++){                // get a full set of measures at startup )
    _valArrayin[_w] = 0;       // otherwise all vals ignored since deviation from zero
  }
  _init = 1;
}
  
_valArrayin[_i] = _reading; 


  for (int _k = 0; _k < 10; _k++){               
    _valArray[_k] = _valArrayin[_k];
}

for (_z = 0; _z < _outliers; _z++){
   _maxval = -1000000;
   _minval = 1000000;
  for (_j = 0; _j < 10; _j++){
    if (_valArray[_j] >= _maxval){
      _maxvalind = _j;
      _maxval = _valArray[_j];
    }
    if (_valArray[_j] <= _minval){
      _minvalind = _j;
      _minval = _valArray[_j];

    }
  } 

  _valArray[_maxvalind] = _val;
  _valArray[_minvalind] = _val;
 
}

_val = 0;
for (int _r = 0; _r < 10; _r++){
  _val =(_val + _valArray[_r])/2;
  
}

_i++;
if (_i > 9){
  _i = 0;
}
return _val;
}



