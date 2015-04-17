function robotInit()

global numRobots
global Robots
global lookFood
global toNest
global ticks

lookFood = 1;
toNest = 2;


numRobots = 100;
Robots = struct();
Robots(1:numRobots) = struct();

for i=1:numRobots
    Robots(i).x = 4.5;
    Robots(i).y = 4.5;
    Robots(i).lastX = rand(1,1)*50;
    Robots(i).lastY = rand(1,1)*50;
    Robots(i).step = 1;
    Robots(i).direction = rand(1,1);
    Robots(i).color = 'red';
    Robots(i).handle = plot(Robots(i).x,Robots(i).y,'Marker','o','MarkerFaceColor',Robots(i).color,'MarkerSize',6);
    Robots(i).state = lookFood;
    Robots(i).lastAlive = ticks;
end