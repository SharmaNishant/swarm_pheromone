clear all
close all
%
%
%
global Patches
global EnvSize
global numRobots
global Robots
global toNest
global lookFood

global diffusionRate
global evaporationRate


diffusionRate = 0.3;
evaporationRate = 0.02;

envInit();
nestInit();
foodPatchInit();
robotInit();
i=1;
ticks = 1;
for t=1:10000
    %pause(0.01);
    drawnow();
    ticks = ticks + 1;
    
    if Robots(i).state == lookFood
        lookForFood(i);
    else
        
        recolorPatch();
        diffusionAndEvaporation();
        returnToNest(i);
    end


    disp(t)
    Robots(i).lastX = Robots(i).x; 
    Robots(i).lastY = Robots(i).y;
    Robots(i).x = Robots(i).x + (Robots(i).step * cos(Robots(i).direction));
    Robots(i).y = Robots(i).y + (Robots(i).step * sin(Robots(i).direction));
    checkLimits(i);
    set(Robots(i).handle, 'xData',Robots(i).x,'yData',Robots(i).y,'MarkerFaceColor',Robots(i).color);
end
