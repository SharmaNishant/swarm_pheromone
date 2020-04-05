#include "swarm_pheromone/Ants.h"

Ants::Ants() {
  for (int i = 0; i < initialAnts; i++) {
    Ant ant;
    antInit(ant);
    markerInit(ant);
    antBots.push_back(ant);
    antCount++;
  }
}

Ants::~Ants() {
  // dtor
}

void Ants::antInit(Ant &ant);
{
  ant.curPos = nestLocation;
  ant.lastPos = nestLocation;
  ant.direction = 0;

  Color color;
  color.r = color.a = 1.0f;

  ant.color = color;
  ant.state = LOOK_FOR_FOOD;
  ant.aliveTime = 0;
}

void Ants::markerInit(Ant &ant) {
  ant.marker.header.frame_id = "swarm_pheromone";
  ant.marker.header.stamp = ros::Time::now();
  ant.marker.ns = "environment patches";
  ant.marker.action = visualization_msgs::Marker::ADD;
  ant.marker.pose.orientation.w = 1.0;

  // setting id for each marker
  ant.marker.id = id++;

  // defining types
  ant.marker.type = visualization_msgs::Marker::SPHERE;

  // setting position
  ant.marker.pose.position = ant.curPos;

  // setting scale
  ant.marker.scale.x = 1;
  ant.marker.scale.y = 1;
  ant.marker.scale.z = 1;

  // assigning colors
  ant.marker.color.b = 1.0f;
  ant.marker.color.a = 1.0f;
}

void Ants::publishAnts() {
  vector<Marker> markers;
  for (int i = 0; i < antCount; i++) {
    markers.push_back(this->antBots[i].marker);
  }
  visualization_msgs::MarkerArray markerArray;
  markerArray.markers = markers;
  antPublisher.publish(markerArray);
}

void Ants::lookForFood(Environment &environment) {
  Patch patch;
  for (int i = 0; i < antBots.size(); i++) {
    if (antBots[i].state == LOOK_FOR_FOOD) {
      //            Color color;
      //            color.r = 1.0f;
      //            color.g = 0.6f;
      //            color.a = 1.0f;
      //            antBots[i].color = color;
      //            patch.foodValue = Patches(x,y).foodValue - 1;
      //            Robots(i).direction = Robots(i).direction * -1;
      //            Robots(i).state = toNest;
      //            disp('food found');
    }
    elseif Patches(x, y).foodTrailChemical > 1 % uphillNestChemical(i);
    else temp = rand(1, 1) * 2;
    temp = temp - 1;
    Robots(i).direction = Robots(i).direction + temp;
    end

        end
  }
}
