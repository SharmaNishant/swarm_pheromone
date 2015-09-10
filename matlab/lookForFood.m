function lookForFood(i)

global Patches
global Robots
global toNest
global ticks
x = floor(Robots(i).x);
y = floor(Robots(i).y);
%disp(x)
%disp(y)
if Patches(x,y).foodValue > 0
    Robots(i).color = 'm';
    Patches(x,y).foodValue = Patches(x,y).foodValue - 1;
    Robots(i).direction = Robots(i).direction * -1;
    Robots(i).state = toNest;
    Robots(i).lastFoodTime = ticks;
    disp('food found');
elseif Patches(x,y).foodTrailChemical > 1
    disp('going downhill')
    downhillFoodChemical(i);
else
    temp = rand(1,1) * 2;
    temp = temp - 1;
    Robots(i).direction = Robots(i).direction + temp;
end

end