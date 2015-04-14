function uphillNestChemical(i)
global Patches
global Robots


max = -1;
id = [-1 -1];

x = floor(Robots(i).x);
y = floor(Robots(i).y);


for k= (x-1):(x+1)
    for l= (y-1) : (y+1)
        if k < 1 || k > 100 || l < 1 || l > 100 || k == x || l ==y
            continue;
        end
        if(Patches(k,l).nestChemical > max)
            max = Patches(k,l).nestChemical;
            id = [k l];
        end
    end
end

direction = atan2((id(2) - y),(id(1)-x));
Robots(i).direction = direction;
Patches(x,y).foodTrailChemical = Patches(x,y).foodTrailChemical + 30000;
%disp(direction);
end
