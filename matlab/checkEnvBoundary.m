function result = checkEnvBoundary(x,y)

global EnvSize

x1 = 0;
x2 = 0;
x3 = EnvSize;
y1 = 0;
y2 = EnvSize;
y3 = 0;

dv13 = ((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1));
dv12 = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
dv1m3 = ((x - x1) * (x3 - x1)) + ((y - y1) * (y3 - y1));
dv1m2 = ((x - x1) * (x2 - x1)) + ((y - y1) * (y2 - y1));

if(((0 < dv1m2) && (dv1m2 < dv12)) || ((0 < dv1m3) && (dv1m3 < dv13)))
    result = true;
else
    result = false;
end
 
    
