function diffusionAndEvaporation()

global Patches
global EnvSize
global diffusionRate
global evaporationRate

global tempTrail
tempTrail = zeros(EnvSize,EnvSize);



for i=1:100
    for j=1:100
        for k = (i-1):(i+1)
            for l= (j-1) : (j+1)
                if k < 1 || k > 100 || l < 1 || l > 100 
                    continue;
                elseif k == i && l == j
                   %Patches(i,j).nestChemical = Patches(i,j).nestChemical * (1 - diffusionRate);
                   tempTrail(k,l) = tempTrail(k,l) + ( Patches(i,j).foodTrailChemical * (1 - diffusionRate) );
                else
                  % Patches(k,l).nestChemical = Patches(k,l).nestChemical + (Patches(i,j).nestChemical * (diffusionRate/8));  
                   tempTrail(k,l) = tempTrail(k,l) + (Patches(i,j).foodTrailChemical * (diffusionRate/8));   
                end
            end
        end
    end
end


for i=1:100
    for j=1:100
        %Patches(i,j).nestChemical = Patches(i,j).nestChemical * (1 - evaporationRate);
       tempTrail(i,j) = tempTrail(i,j) * (1 - evaporationRate);
    end
end

for i=1:100
    for j=1:100
        Patches(i,j).foodTrailChemical = tempTrail(i,j);
    end
end


% 
% function diffusionAndEvaporation()
% 
% global Patches
% 
% global diffusionRate
% global evaporationRate
% 
% for i=1:100
%     for j=1:100
%         for k = (i-1):(i+1)
%             for l= (j-1) : (j+1)
%                 if k < 1 || k > 100 || l < 1 || l > 100 
%                     continue;
%                 elseif k == i || l == j
%                    %Patches(i,j).nestChemical = Patches(i,j).nestChemical * (1 - diffusionRate);
%                    Patches(i,j).foodTrailChemical = Patches(i,j).foodTrailChemical * (1 - diffusionRate);
%                 else
%                   % Patches(k,l).nestChemical = Patches(k,l).nestChemical + (Patches(i,j).nestChemical * (diffusionRate/8));  
%                    Patches(k,l).foodTrailChemical = Patches(k,l).foodTrailChemical + (Patches(i,j).foodTrailChemical * (diffusionRate));   
%                 end
%             end
%         end
%     end
% end
% 
% 
% for i=1:100
%     for j=1:100
%         %Patches(i,j).nestChemical = Patches(i,j).nestChemical * (1 - evaporationRate);
%        % Patches(i,j).foodTrailChemical = Patches(i,j).foodTrailChemical * (1 - evaporationRate);
%     end
% end
% 
% end
% 
% end