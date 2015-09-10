Patches = struct();
Patches(1:100,1:100) = struct();

figure('units', 'normalized', 'outerposition', [0 0 1 1]);
clf
set(gcf,'color','w');
hold all

axis equal
axis off

rectangle('Position', [0,0,100,100]);

BOX = [0 0;
    100 0;
    100 100
    0 100; 
    0 0];

k=0;
for i=1:100
    for j = 1:100
        Patches(i,j).ID = i;
        Patches(i,j).nestChemical = 0;
        Patches(i,j).FoodTrailChemical = 0;
        Patches(i,j).FoodPatchNumber = 0;
        Patches(i,j).FoodValue = 0;
        Patches(i,j).polygon = [i-1 j-1;
                            i-1 j;
                            i j;
                            i j-1;
                            i-1 j-1];
        Patches(i,j).H.polygon = fill(Patches(i,j).polygon(:,1), Patches(i,j).polygon(:,2), 'w');
        Patches(i,j).position = [i-1, j-1];    
    end
end