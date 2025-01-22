#include "polygonizer.hh"

using namespace Geometry;

namespace {
  extern "C" {
    #include "bloomenthal-polygonizer.h"
  }

  std::function<double(const Point3D &)> surface;

  TriMesh mesh;
  VERTICES points;

  double evalSurface(double x, double y, double z) {
    return -surface({x, y, z});
  }

  static int addTriangle(int i1, int i2, int i3, VERTICES vertices) {
    mesh.addTriangle(i1, i2, i3);
    points = vertices;
    return 1;
  }

}

namespace Polygonizer {

TriMesh isosurface(std::function<double(const Geometry::Point3D &)> f,
                   const Point3D &center, double size, size_t resolution, bool tetp) {
  mesh.clear();
  surface = f;
  polygonize(evalSurface, size / resolution, resolution, center[0], center[1], center[2],
             addTriangle, tetp ? TET : NOTET);
  PointVector pv;
  for (int i = 0; i < points.count; i++) {
    const auto &p = points.ptr[i].position;
    pv.emplace_back(p.x, p.y, p.z);
  }
  mesh.setPoints(pv);
  return mesh;
}

}

