////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "lambertian.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Lambertian::Lambertian(Texture * texture) : _texture(texture) {} //const Color& albedo) : _albedo(albedo) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Lambertian::scatter(const Ray& shotRay, const Point& intersectionPoint, const Vector& normalVector, Ray& scatteredRay, Color& attenuation, const Object& object) const {
    double u, v;
    object.uv_projection(intersectionPoint, u, v);
    Vector scatteredRayDir = normalVector + Sphere::random_point(0.5);
    scatteredRay           = Ray(intersectionPoint, scatteredRayDir);
    attenuation            = (*_texture)(u, v, intersectionPoint);//_albedo;
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////