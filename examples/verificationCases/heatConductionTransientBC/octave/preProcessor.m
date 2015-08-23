% * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
% Main preprocessing file for a ParScale Simulation
% Copyright: Stefan Radl, TU Graz, 2015
% * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

clear
clc
more off
close all 

runDir = '../';

radialIndex = 10;

iVariable=1;
file{iVariable} =           '0/gasPhaseFraction.json';
variableName{iVariable} =   'data.all';
value{iVariable}        =   0.1;
valueBC{iVariable}      =   0;
upToId{iVariable}       =   999;

iVariable=iVariable+1;
file{iVariable} =           '0/gasPhaseFraction.json';
variableName{iVariable} =   'data.all';
value{iVariable}        =   0.1;
valueBC{iVariable}      =   0;
upToId{iVariable}       =   radialIndex;

iVariable=iVariable+1;
file{iVariable} =           '0/liquidPhaseFraction.json';
variableName{iVariable} =   'data.all';
value{iVariable}        =   0.1;
valueBC{iVariable}      =   0;
upToId{iVariable}       =   999;

iVariable=iVariable+1;
file{iVariable} =           '0/liquidPhaseFraction.json';
variableName{iVariable} =   'data.all';
value{iVariable}        =   0.1;
valueBC{iVariable}      =   0;
upToId{iVariable}       =   radialIndex;

iVariable=iVariable+1;
file{iVariable} =           '0/species.json';
variableName{iVariable} =   'data.all';
value{iVariable}        =   0.00;
valueBC{iVariable}      =   0.0;
upToId{iVariable}       =   999;

iVariable=iVariable+1;
file{iVariable} =           '0/liquidSpecies.json';
variableName{iVariable} =   'data.all';
value{iVariable}        =   1.0;
valueBC{iVariable}      =   0.0;
upToId{iVariable}       =   999;

iVariable=iVariable+1;
file{iVariable} =           '0/heat.json';
variableName{iVariable} =   'data.all';
value{iVariable}        =   800;
valueBC{iVariable}      =   400;
upToId{iVariable}       =   999;

iVariable=iVariable+1;
file{iVariable} =           'settings/liquidToGasEvaporation.json';
variableName{iVariable} =   'vaporPressureModel.evaporationRateConstant';
value{iVariable}        =   0;  
valueBC{iVariable}      =   -1; %not relevant
upToId{iVariable}       =   999;
% * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
% END USER INPUT
% * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

for iter=1:iVariable
    disp(['applying change to: ', runDir,file{iter}])
    [errorValue] = jsonChangeVariable([runDir,'/',file{iter}], variableName{iter}, value{iter}, valueBC{iter}, upToId{iter})
   
    %on some systems the parsing/writing of JSON files does not work! Must manually change the particle id 
    sysCommand=["sed -i 's/I/1/g' ", runDir,'/',file{iter}];
    system(sysCommand);
end
