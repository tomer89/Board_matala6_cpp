#include "IllegalCoordinateException.h"
#include "coordinate.h"


IllegalCoordinateException::IllegalCoordinateException(Coordinate c){
    _coord = &c;
}
string IllegalCoordinateException::theCoordinate() const{
    return to_string(_coord->x)+","+to_string(_coord->y);
}