#include "swarm_pheromone/Patches.h"

Environment::Environment()
{
    //ctor
}

Environment::~Environment()
{
    //dtor
}

void Environment::nestInit()
{
    for(int i = 0; i < environmentHeight; i++)
    {
        for(int j = 0;j < environmentWidth; j++)
        {
            float dist = sqrt(pow((this->patches[i][j].position.x - nestLocation.x),2) + pow((this->patches[i][j].position.y - nestLocation.y),2));
            if(dist < nestRadius)
            {
                this->patches[i][j].isNest = true;
            }
            this->patches[i][j].nestChemical = 500 - dist;
        }
    }
}

void Environment::foodPatchInit()
{
    for(int i = 0; i < environmentHeight; i++)
    {
        for(int j = 0;j < environmentWidth; j++)
        {
            for(int k =0; k < foodPatches.size(); k++)
            {
                float dist = sqrt(pow((this->patches[i][j].position.x - foodPatches[k].location.x),2) + ((this->patches[i][j].position.y - foodPatches[k].location.y),2));
                if (dist < foodPatchRadius)
                {
                    this->patches[i][j].isFood = true;
                    this->patches[i][j].foodPatchNumber = k;
                    this->patches[i][j].foodValue = 5;

                }
            }
        }
    }
}

void Environment::markerInit()
{
    int id = 0;
    for(int i =0; i< environmentHeight;i++)
    {
        for(int j=0;j<environmentWidth;j++)
        {
            this->patches[i][j].marker.header.frame_id    = "swarm_pheromone";
            this->patches[i][j].marker.header.stamp       = ros::Time::now();
            this->patches[i][j].marker.ns                 = "environment patches";
            this->patches[i][j].marker.action             = visualization_msgs::Marker::ADD;
            this->patches[i][j].marker.pose.orientation.w = 1.0;

            //setting id for each marker
            this->patches[i][j].marker.id = id++;

            //defining types
            this->patches[i][j].marker.type = visualization_msgs::Marker::SPHERE;

            //seeting z position
            this->patches[i][j].marker.pose.position.z = -1;

            //setting scale
            this->patches[i][j].marker.scale.x = 1;
            this->patches[i][j].marker.scale.y = 1;
            this->patches[i][j].marker.scale.z = 1;

            //assigning colors
            this->patches[i][j].marker.color.b   = 1.0f;
            this->patches[i][j].marker.color.a   = 1.0f;
        }
    }
}
