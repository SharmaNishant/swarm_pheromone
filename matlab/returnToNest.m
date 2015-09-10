function returnToNest(i)

global Robots
global Patches
global lookFood
global toNest

x = floor(Robots(i).x);
y = floor(Robots(i).y);

if Patches(x,y).isNest == true
    Robots(i).color = 'r';
    Robots(i).direction = Robots(i).direction * -1;
    Robots(i).state = lookFood;
    disp('food');
    disp(Robots(i).x);
    disp(Robots(i).y);
else
    %disp(Robots(i).x);
   % disp(Robots(i).y);
   % disp(' ');
    uphillNestChemical(i);
end

end