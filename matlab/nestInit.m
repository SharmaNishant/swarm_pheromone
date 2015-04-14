function nestInit()



global Patches
global EnvSize

nestRadius = 5;
nestX = 4;
nestY = 4;

for i=1:EnvSize
    for j=1:EnvSize
        dist = sqrt(((Patches(i,j).position(1) - nestX)*(Patches(i,j).position(1) - nestX)) + ((Patches(i,j).position(2) - nestY)*(Patches(i,j).position(2) - nestY)));
        if dist < 4
            Patches(i,j).isNest = true;
            Patches(i,j).H.polygon = fill(Patches(i,j).polygon(:,1), Patches(i,j).polygon(:,2), 'b', 'FaceAlpha',0.4);
        end
        Patches(i,j).nestChemical = 500 - dist;
    end
end
