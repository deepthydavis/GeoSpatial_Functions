#include <geos/geom/GeometryFactory.h>
#include <geos/geom/Point.h>
#include <geos/io/WKBWriter.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

// Function to serialize a GEOS geometry to WKB (Well-Known Binary)
std::vector<char> serialize(const geos::geom::Geometry* geometry) {
    geos::io::WKBWriter writer;
    std::ostringstream os;
    writer.write(*geometry, os);
    std::string str = os.str();
    return std::vector<char>(str.begin(), str.end());
}

// Create a Point geometry with given coordinates and serialize it
std::vector<char> stPoint(double x, double y) {
    const geos::geom::GeometryFactory& factory = *geos::geom::GeometryFactory::getDefaultInstance();
    geos::geom::Coordinate coord(x, y);
    std::unique_ptr<geos::geom::Point> point(factory.createPoint(coord));
    return serialize(point.get());
}

int main() {
    double x = 1.0, y = 2.0;
    std::vector<char> wkb = stPoint(x, y);
    std::cout << "WKB of Point(" << x << " " << y << "): ";
    for (unsigned char byte : wkb) {
        printf("%02x", byte);
    }
    std::cout << std::endl;
    return 0;
}

