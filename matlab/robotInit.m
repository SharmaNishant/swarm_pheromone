function robotInit()

global numRobots
global Robots
global lookFood
global toNest
global ticks

Robots = struct();
Robots(1:numRobots) = struct();

for i=1:numRobots
    Robots(i).x = 4.5;
    Robots(i).y = 4.5;
    Robots(i).lastX = rand(1,1)*50;
    Robots(i).lastY = rand(1,1)*50;
    Robots(i).step = 1;
    Robots(i).lifeFlag = false;
    Robots(i).direction = rand(1,1);
    Robots(i).color = 'red';
    Robots(i).handle = plot(Robots(i).x,Robots(i).y,'Marker','o','MarkerFaceColor',Robots(i).color,'MarkerSize',6);
    Robots(i).state = lookFood;
    Robots(i).lastFoodTime = 0;
    Robots(i).firstFoodTime = 0;
    Robots(i).firstFoodFlag = false;
    Robots(i).arrivalTime = 0;
    Robots(i).deathTime = 0;
end