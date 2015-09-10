#include "swarm_pheromone/GlobalDeclaration.h"

float getDistance(Point one, Point two)
{
    return sqrt(pow(one.x - two.x,2) + pow(one.y - two.y,2));
}

float getDistance(float x_one, float y_one, float x_two, float y_two)
{
    return sqrt(pow(x_one - x_two,2) + pow(y_one - y_two,2));
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

float GetAngle(Point destination, Point source)
{
    return atan2(destination.y - source.y , destination.x - source.x);
}

bool isInsideBoundary(Point location)
{
    Point boundaryOne, boundaryTwo, boundaryThree;

    boundaryOne = boundaryTwo = boundaryThree = patchStarting;
    boundaryTwo.y += environmentWidth;
    boundaryThree.x += environmentHeight;

    bool result = isInsideRectangle(boundaryOne,boundaryTwo,boundaryThree,location);

    return result;
}

bool isInsideRectangle(Point boundaryOne, Point boundaryTwo, Point boundaryThree, Point location)
{
    float firstBoundary, secondBoundary;

    firstBoundary = pow((boundaryThree.x - boundaryOne.x),2) + pow((boundaryThree.y - boundaryOne.y),2);
    secondBoundary = pow((boundaryTwo.x - boundaryOne.x),2) + pow((boundaryTwo.y - boundaryOne.y),2);

    float ptFirstBoundProj = ((location.x - boundaryOne.x) * (boundaryThree.x - boundaryOne.x)) + ((location.y - boundaryOne.y) * (boundaryThree.y - boundaryOne.y));
    float ptSecondBoundProj = ((location.x - boundaryOne.x) * (boundaryTwo.x - boundaryOne.x)) + ((location.y - boundaryOne.y) * (boundaryTwo.y - boundaryOne.y));

    if(((0 < ptSecondBoundProj) && (ptSecondBoundProj < secondBoundary)) || ((0 < ptFirstBoundProj) && (ptFirstBoundProj < firstBoundary)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void initializeGlobalVariables()
{
    nestLocation.x = 5;
    nestLocation.y = 5;

    patchStarting.x = 0;
    patchStarting.y = 0;

    antCount = 0;

    Point foodPatchLocation;
    foodPatchLocation.x = 94;
    foodPatchLocation.y = 94;
    int foodVal = 5;

    FoodPatch foodPatchOne;
    foodPatchOne.location = foodPatchLocation;
    foodPatchOne.foodValue = foodVal;

    foodPatches.push_back(foodPatchOne);

}
