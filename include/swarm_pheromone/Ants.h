#ifndef ANTS_H
#define ANTS_H

enum RobotState{LOOK_FOR_FOOD};

struct Ant
{
    Point curPos;
    Point lastPos;
    float stepSize;
    float direction;
    Color color;
    Marker marker;
    RobotState state;
};

class Ants
{
    public:
        /** Default constructor */
        Ants();
        /** Default destructor */
        virtual ~Ants();
    protected:
    private:
        vector<Ant> antBots;
};

#endif // ANTS_H
