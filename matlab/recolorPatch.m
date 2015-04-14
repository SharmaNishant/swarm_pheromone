function recolorPatch()
%RECOLORPATCH Summary of this function goes here
%   Detailed explanation goes here

global Patches
global EnvSize
for i=1:EnvSize
    for j=1:EnvSize
        if Patches(i,j).isNest == true
            continue;
        elseif Patches(i,j).foodValue > 0
            continue;
        elseif Patches(i,j).foodTrailChemical > 250
            set(Patches(i,j).H.polygon, 'FaceColor','y','FaceAlpha', 1);
        elseif Patches(i,j).foodTrailChemical > 150
            set(Patches(i,j).H.polygon, 'FaceColor','y','FaceAlpha', 1);
        elseif Patches(i,j).foodTrailChemical > 100    
            set(Patches(i,j).H.polygon, 'FaceColor','y','FaceAlpha', 1);
        elseif Patches(i,j).foodTrailChemical > 50
            set(Patches(i,j).H.polygon, 'FaceColor','y','FaceAlpha', 1);
        elseif Patches(i,j).foodTrailChemical > 1
            set(Patches(i,j).H.polygon, 'FaceColor','y','FaceAlpha', 1);   
        else
            set(Patches(i,j).H.polygon, 'FaceColor','w','FaceAlpha', 1);
        end
    end
end

end

