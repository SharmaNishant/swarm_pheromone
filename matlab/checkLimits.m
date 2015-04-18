function checkLimits(i)

global Robots
global EnvSize

x = floor(Robots(i).x);
y = floor(Robots(i).y);

if Robots(i).x < 1 || Robots(i).x > EnvSize || Robots(i).y < 1 || Robots(i).y > EnvSize
   Robots(i).direction = Robots(i).direction + 3.14;
   Robots(i).x = Robots(i).lastX;
   Robots(i).y = Robots(i).lastY;
end