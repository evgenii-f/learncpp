#include "Point3d.h"
#include "Vector3d.h"

void Point3d::moveByVector(const Vector3d& v) {
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}
