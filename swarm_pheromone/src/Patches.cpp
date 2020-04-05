#include "swarm_pheromone/Patches.h"

Environment::Environment() {
  envInit();
  nestInit();
  foodPatchInit();
  markerInit();
}

Environment::~Environment() {
  // dtor
}

void Environment::envInit() {
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      this->patches[i][j].color.r = this->patches[i][j].color.g =
          this->patches[i][j].color.b = this->patches[i][j].color.a = 1.0f;
      this->patches[i][j].nestChemical = 0;
      this->patches[i][j].foodTrailChemical = 0;
      this->patches[i][j].foodPatchNumber = -1;
      this->patches[i][j].foodValue = 0;
      this->patches[i][j].patchType = EMPTY;
      Point position;
      position.x = i;
      position.y = j;
      this->patches[i][j].position = position;
    }
  }
}

void Environment::nestInit() {
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      float dist =
          sqrt(pow((this->patches[i][j].position.x - nestLocation.x), 2) +
               pow((this->patches[i][j].position.y - nestLocation.y), 2));
      if (dist < nestRadius) {
        this->patches[i][j].patchType = NEST;
      }
      this->patches[i][j].nestChemical = 500 - dist;
    }
  }
}

void Environment::foodPatchInit() {
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      for (int k = 0; k < foodPatches.size(); k++) {
        float dist = sqrt(
            pow((this->patches[i][j].position.x - foodPatches[k].location.x),
                2) +
            ((this->patches[i][j].position.y - foodPatches[k].location.y), 2));
        if (dist < foodPatchRadius) {
          this->patches[i][j].patchType = FOOD;
          this->patches[i][j].foodPatchNumber = k;
          this->patches[i][j].foodValue = foodPatches[k].foodValue;
        }
      }
    }
  }
}

void Environment::markerInit() {
  int id = 0;
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      this->patches[i][j].marker.header.frame_id = "swarm_pheromone";
      this->patches[i][j].marker.header.stamp = ros::Time::now();
      this->patches[i][j].marker.ns = "environment patches";
      this->patches[i][j].marker.action = visualization_msgs::Marker::ADD;
      this->patches[i][j].marker.pose.orientation.w = 1.0;

      // setting id for each marker
      this->patches[i][j].marker.id = id++;

      // defining types
      this->patches[i][j].marker.type = visualization_msgs::Marker::CUBE;

      // setting position
      this->patches[i][j].marker.pose.position.x = i;
      this->patches[i][j].marker.pose.position.y = j;
      this->patches[i][j].marker.pose.position.z = -1;

      // setting scale
      this->patches[i][j].marker.scale.x = 1;
      this->patches[i][j].marker.scale.y = 1;
      this->patches[i][j].marker.scale.z = 0.5;

      // assigning colors
      this->patches[i][j].marker.color.b = 1.0f;
      this->patches[i][j].marker.color.a = 1.0f;
    }
  }
}

void Environment::recolorPatch() {
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      Color color;
      if (this->patches[i][j].patchType == NEST) {
        color.r = 0.0f;
        color.g = 0.0f;
        color.b = 0.4f;
      } else if (this->patches[i][j].patchType == EMPTY) {
        color.r = 1.0f;
        color.g = 1.0f;
        color.b = 1.0f;

        if (this->patches[i][j].foodTrailChemical > 2) {
          float yellow = this->patches[i][j].foodTrailChemical / 500;
          color.r = yellow;
          color.g = yellow;
          color.b = 0.0f;
        }

      } else if (this->patches[i][j].patchType == FOOD) {
        if (this->patches[i][j].foodValue > 0) {
          color.r = 0.0f;
          color.g = 1.0f;
          color.b = 1.0f;
        } else {
          color.r = color.g = color.b = 1.0f;
        }
      }
      color.a = 1.0f;
      this->patches[i][j].color = color;
    }
  }
}

void Environment::diffusion() {
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {
          if (k < 0 || k >= environmentHeight || l < 0 || l > environmentWidth)
            continue;
          else if (k == i || l == j) {
            this->patches[i][j].foodTrailChemical *= (1 - diffusionRate);
          } else {
            this->patches[k][l].foodTrailChemical +=
                (this->patches[i][j].foodTrailChemical * (diffusionRate / 8));
          }
        }
      }
    }
  }
}

void Environment::evaporation() {
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      this->patches[i][j].foodTrailChemical *= (1 - evaporationRate);
    }
  }
}

void Environment::update() {
  diffusion();
  evaporation();
  recolorPatch();
}

Patch Environment::getPatch(int i, int j) { return this->patches[i][j]; }

void Environment::setPatch(int i, int j, Patch patch) {
  this->patches[i][j] = patch;
}

void Environment::publishPatches() {
  vector<Marker> markers;
  for (int i = 0; i < environmentHeight; i++) {
    for (int j = 0; j < environmentWidth; j++) {
      markers.push_back(this->patches[i][j].marker);
    }
  }
  visualization_msgs::MarkerArray markerArray;
  markerArray.markers = markers;
  envPublisher.publish(markerArray);
}
