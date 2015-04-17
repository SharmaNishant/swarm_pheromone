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

global tempTrail

diffusionRate = 0.3;
evaporationRate = 0.1;

envInit();
nestInit();
foodPatchInit();
robotInit();
i=1;
global ticks
ticks = 1;
for t=1:10000
    %pause(0.01);
    if mod(ticks, 10) == 0
        recolorPatch();
        drawnow();
     end
    ticks = ticks + 1;
    for i=1:numRobots

        if (ticks - Robots(i).lastFoodTime ) > 500 
            Robots(i).lifeFlag = false;
            disp('died')
        end
        
        if(Robots(i).lifeFlag == false)
           continue 
        end
        
        if Robots(i).state == lookFood
            lookForFood(i);
        else
            returnToNest(i);
        end

        
        Robots(i).lastX = Robots(i).x; 
        Robots(i).lastY = Robots(i).y;
        Robots(i).x = Robots(i).x + (Robots(i).step * cos(Robots(i).direction));
        Robots(i).y = Robots(i).y + (Robots(i).step * sin(Robots(i).direction));
        checkLimits(i);
        set(Robots(i).handle, 'xData',Robots(i).x,'yData',Robots(i).y,'MarkerFaceColor',Robots(i).color);
    end
    disp(t)
    diffusionAndEvaporation();
end
