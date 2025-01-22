#pragma once

#include <functional>
#include <geometry.hh> // https://github.com/salvipeter/libgeom/

namespace Polygonizer {

Geometry::TriMesh isosurface(std::function<double(const Geometry::Point3D &)> f,
                             const Geometry::Point3D &center, double size,
                             size_t resolution, bool tetp);

}

