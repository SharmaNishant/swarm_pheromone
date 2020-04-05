#ifndef ANTS_H
#define ANTS_H

#include <ros/ros.h>
#include <swarm_pheromone/GlobalDeclaration.h>
#include <visualization_msgs/MarkerArray.h>

enum RobotState { LOOK_FOR_FOOD };

struct Ant {
  Point curPos;
  Point lastPos;
  float direction;
  Color color;
  Marker marker;
  RobotState state;
  int aliveTime;
};

class Ants {
public:
  /** Default constructor */
  Ants();
  /** Default destructor */
  virtual ~Ants();
  void antInit(Ant &ant);
  void publishAnts();
  void uphillFoodChemical();
  void returnToNest();
  void lookForFood();
  void checkBoundary();
  void isInsideBoundary(Ant ant);
  void update();
  void markerInit(Ant &ant);
  void repaintAnts();

  ros::Publisher antPublisher;

protected:
private:
  vector<Ant> antBots;
};

#endif // ANTS_H
