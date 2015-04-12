#ifndef PATCH_H
#define PATCH_H

#include <swarm_pheromone/GlobalDeclaration.h>
#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>

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
        void publishPatches();
        Patch getPatch(int i, int j);
        void setPatch(int i, int j, Patch patch);

        ros::Publisher envPublisher;
    private:
        Patch patches[environmentHeight][environmentWidth];

};

#endif // PATCH_H
