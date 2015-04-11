#ifndef PATCH_H
#define PATCH_H

#include <swarm_pheromone/GlobalDeclaration.h>

enum PatchType{NEST,FOOD,EMPTY};

struct Patch
{
    Marker marker;
    Color color;
    float nestChemical;
    float foodTrailChemical;
    int foodPatchNumber;
    float foodValue;
    bool isNest;
    Point position;
};


class Environment
{
    public:
        Environment();
        virtual ~Environment();
        void nestInit();
        void foodPatchInit();
        void markerInit();
    private:
        Patch patches[environmentHeight][environmentWidth];

};

#endif // PATCH_H
