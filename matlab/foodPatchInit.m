function foodPatchInit()

global Patches
global EnvSize

foodRadius = 5;
foodPatch1X = 54;
foodPatch1Y = 54;

for i=1:EnvSize
    for j=1:EnvSize
        dist = sqrt(((Patches(i,j).position(1) - foodPatch1X)*(Patches(i,j).position(1) - foodPatch1X)) + ((Patches(i,j).position(2) - foodPatch1Y)*(Patches(i,j).position(2) - foodPatch1Y)));
        if dist < foodRadius
            Patches(i,j).isFood = true;
            Patches(i,j).foodPatchNumber = 1;
            Patches(i,j).foodValue = 5;
            Patches(i,j).H.polygon = fill(Patches(i,j).polygon(:,1), Patches(i,j).polygon(:,2), 'g', 'FaceAlpha',0.5);
        end
    end
end
