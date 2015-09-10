function envInit()

global Patches
global EnvSize

EnvSize = 100;

Patches = struct();
Patches(1:EnvSize,1:EnvSize) = struct();

figure('units', 'normalized', 'outerposition', [0 0 1 1]);
clf
set(gcf,'color','w');
hold all

axis equal
axis off

for i=1:EnvSize
    for j = 1:EnvSize
        Patches(i,j).ID = i;
        Patches(i,j).nestChemical = 0;
        Patches(i,j).foodTrailChemical = 0;
        Patches(i,j).foodPatchNumber = 0;
        Patches(i,j).deathChemical = 0;
        Patches(i,j).foodValue = 0;
        Patches(i,j).isNest = false;
        Patches(i,j).polygon = [i-1 j-1;
                            i-1 j;
                            i j;
                            i j-1;
                            i-1 j-1];
        Patches(i,j).H.polygon = fill(Patches(i,j).polygon(:,1), Patches(i,j).polygon(:,2), 'w', 'FaceAlpha', 0.5);
        Patches(i,j).position = [i-1, j-1];    
    end
end