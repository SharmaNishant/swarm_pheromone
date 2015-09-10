function result = checkNestBoundary(x,y)
global nest

x1 = nest(1,1);
x2 = nest(2,1);
x3 = nest(3,1);
y1 = nest(1,2);
y2 = nest(2,2);
y3 = nest(3,2);

dv13 = ((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1));
dv12 = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
dv1m3 = ((x - x1) * (x3 - x1)) + ((y - y1) * (y3 - y1));
dv1m2 = ((x - x1) * (x2 - x1)) + ((y - y1) * (y2 - y1));

if(((0 < dv1m2) && (dv1m2 < dv12)) || ((0 < dv1m3) && (dv1m3 < dv13)))
    result = true;
else
    result = false;
end