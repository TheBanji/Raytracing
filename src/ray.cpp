////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ray.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Ray::Ray() : _origin(), _dir() {}

Ray::Ray(const Point& origin, const Vector& dir) : _origin(origin), _dir(dir) {
    _dir.normalize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Point Ray::getOrigin() const {
    return _origin;
}

Vector Ray::getDir() const {
    return _dir;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Ray::setDir(const Vector& dir) {
    _dir = dir;
    _dir.normalize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Point Ray::operator()(double t) const {
    return _origin + t*_dir;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& stream, const Ray& ray) {
    stream << "Origin    : " << ray._origin << std::endl;
    stream << "Direction : " << ray._dir    << std::endl;
    return stream;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////