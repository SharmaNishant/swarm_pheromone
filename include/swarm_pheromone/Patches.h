#ifndef PATCH_H
#define PATCH_H

#include <swarm_pheromone/GlobalDeclaration.h>

float evaporationRate = 0.01;
float diffusionRate = 0.20;
enum PatchType{NEST,FOOD,EMPTY};

struct Patch
{
    Marker marker;
    Color color;
    float nestChemical;
    float foodTrailChemical;
    int foodPatchNumber;
    float foodValue;
    PatchType patchType;
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
        void envInit();
        void recolorPatch();
        void diffusion();
        void evaporation();
        void update();

        Patch getPatch(int i, int j);
        void setPatch(int i, int j, Patch patch);

    private:
        Patch patches[environmentHeight][environmentWidth];

};

#endif // PATCH_H
