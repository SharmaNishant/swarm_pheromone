function checkLimits(i)

global Robots

x = floor(Robots(i).x);
y = floor(Robots(i).y);

if Robots(i).x < 1 || Robots(i).x > 100 || Robots(i).y < 1 || Robots(i).y > 100
   Robots(i).direction = Robots(i).direction + 3.14;
   Robots(i).x = Robots(i).lastX;
   Robots(i).y = Robots(i).lastY;
end