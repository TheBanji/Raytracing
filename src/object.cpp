////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "object.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Object::Object(Material * material) : _material(material) {}

Object::~Object() {
    if(!_material) {
        delete _material;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////