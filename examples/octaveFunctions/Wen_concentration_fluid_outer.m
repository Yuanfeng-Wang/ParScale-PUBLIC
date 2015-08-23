% Function to calculate the concentration of the fluid at r_m <= r <= R
% for second stage reaction for a given reaction front position and time
% Formulars according Wen, "Noncatalytic Heterogenous Solid Fluid Reaction Models"
% models p. 43 eqn. 37
% Copyright: Stefan Radl / Thomas Forgber, IPPT, TU Graz

function [concentration_fluid_outer] = Wen_concentration_fluid_outer (xi_m,N_sh,concentration_reaction_front,xi,Ca0)

    concentration_fluid_outer =  ...
                                 concentration_reaction_front  ...
                              .* xi_m./xi ...
                              .* (1-xi+xi./N_sh) ...
                               ./(1-xi_m+xi_m./N_sh)...
                              + Ca0 ...
                             .* ( ...
                                     (1-xi_m./xi)...
                                   ./(1-xi_m+xi_m./N_sh)...
                                );
end
