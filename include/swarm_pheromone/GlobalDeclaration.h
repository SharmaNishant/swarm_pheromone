#ifndef GLOBALDECLARATION_H
#define GLOBALDECLARATION_H

#include <cmath>
#include <vector>
#include <geometry_msgs/Point.h>
#include <visualization_msgs/Marker.h>
#include <std_msgs/ColorRGBA.h>

using namespace std;

typedef std_msgs::ColorRGBA Color;
typedef visualization_msgs::Marker Marker;
typedef geometry_msgs::Point Point;

struct FoodPatch
{
    Point location;
    int foodValue;
};

float getDistance(Point one, Point two);
float getDistance(float x_one, float y_one, float x_two, float y_two);

std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

float GetAngle(Point destination, Point source);
bool isInsideRectangle(Point boundaryOne, Point boundaryTwo, Point boundaryThree, Point location);
bool isInsideBoundary(Point location);


Point patchStarting;


const int environmentHeight = 100;
const int environmentWidth = 100;
const int initialAnts = 1;
int antCount = initialAnts;
const int nestRadius = 5;
const int foodPatchRadius = 5;

vector<FoodPatch> foodPatches;


Point nestLocation;

void initializeGlobalVariables();



#endif // GLOBALDECLARATION_H
