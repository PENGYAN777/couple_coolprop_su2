%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                              %
% SU2 configuration file                                                       %
% Case description: Supersonic flow over a wedge in a channel.                 %
% Author: Thomas D. Economon                                                   %
% Institution: Stanford University                                             %
% Date: 2012.10.07                                                             %
% File Version 5.0.0 "Raven"                                                   %
%                                                                              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% ------------- DIRECT, ADJOINT, AND LINEARIZED PROBLEM DEFINITION ------------%
%
% Physical governing equations (EULER, NAVIER_STOKES,
%                               WAVE_EQUATION, HEAT_EQUATION, FEM_ELASTICITY,
%                               POISSON_EQUATION)
SOLVER= EULER
%
% Mathematical problem (DIRECT, CONTINUOUS_ADJOINT)
MATH_PROBLEM= DIRECT
%
% Restart solution (NO, YES)
RESTART_SOL= YES

% ----------- COMPRESSIBLE AND INCOMPRESSIBLE FREE-STREAM DEFINITION ----------%
%
% Mach number (non-dimensional, based on the free-stream values)
MACH_NUMBER= 1.7
%
FREESTREAM_OPTION = DENSITY_FS
FREESTREAM_PRESSURE= 1499900
%
FREESTREAM_DENSITY= 202.8878

FLUID_MODEL= PR_GAS
%
% Ratio of specific heats (1.4 default and the value is hardcoded
%                          for the model STANDARD_AIR, compressible only)
GAMMA_VALUE= 1.0125
% Specific gas constant (287.058 J/kg*K default and this value is hardcoded
%                        for the model STANDARD_AIR, compressible only)
GAS_CONSTANT= 35.152
%
% Critical Temperature (131.00 K by default)
CRITICAL_TEMPERATURE= 564.09
%
% Critical Pressure (3588550.0 N/m^2 by default)
CRITICAL_PRESSURE= 1415000
%
% Acentric factor (0.035 (air))
ACENTRIC_FACTOR= 0.528

% -------------------- BOUNDARY CONDITION DEFINITION --------------------------%
%
% Euler wall boundary marker(s) (NONE = no marker)
MARKER_EULER= ( 4,5 )
MARKER_RIEMANN = (1, STATIC_SUPERSONIC_INFLOW_PD, 1499900, 202.8878, 1.7, 0.0, 0.0, 3, STATIC_PRESSURE, 4e5, 0.0, 0.0, 0.0, 0.0)
MARKER_SYM = (2)

% ------------- COMMON PARAMETERS DEFINING THE NUMERICAL METHOD ---------------%
%
% Numerical method for spatial gradients (GREEN_GAUSS, LEAST_SQUARES, 
%                                         WEIGHTED_LEAST_SQUARES)
NUM_METHOD_GRAD= WEIGHTED_LEAST_SQUARES
%
% Courant-Friedrichs-Lewy condition of the finest grid
CFL_NUMBER= 0.1
%
% Adaptive CFL number (NO, YES)
CFL_ADAPT= YES
%
% Parameters of the adaptive CFL number (factor down, factor up, CFL min value,
%                                        CFL max value )
CFL_ADAPT_PARAM= ( 0.1, 2.0, 0.1, 100 )
%
% Number of total iterations
ITER= 3000
%
% Linear solver for the implicit formulation (BCGSTAB, FGMRES)
LINEAR_SOLVER= FGMRES
%
% Preconditioner of the Krylov linear solver (ILU, JACOBI, LINELET, LU_SGS)
LINEAR_SOLVER_PREC= ILU
%
% Min error of the linear solver for the implicit formulation
LINEAR_SOLVER_ERROR= 1E-6
%
% Max number of iterations of the linear solver for the implicit formulation
LINEAR_SOLVER_ITER= 20

% -------------------- FLOW NUMERICAL METHOD DEFINITION -----------------------%
%
% Convective numerical method (JST, LAX-FRIEDRICH, CUSP, ROE, AUSM, HLLC,
%                              TURKEL_PREC, MSW)
CONV_NUM_METHOD_FLOW= ROE
%
% Monotonic Upwind Scheme for Conservation Laws (TVD) in the flow equations.
%           Required for 2nd order upwind schemes (NO, YES)
MUSCL_FLOW= YES
%
% Slope limiter (NONE, VENKATAKRISHNAN, VENKATAKRISHNAN_WANG,
%                BARTH_JESPERSEN, VAN_ALBADA_EDGE)
SLOPE_LIMITER_FLOW= VENKATAKRISHNAN
%
% Coefficient for the limiter (smooth regions)
VENKAT_LIMITER_COEFF= 0.001
%
% Time discretization (RUNGE-KUTTA_EXPLICIT, EULER_IMPLICIT, EULER_EXPLICIT)
TIME_DISCRE_FLOW= EULER_IMPLICIT

% --------------------------- CONVERGENCE PARAMETERS --------------------------%
%
% Convergence criteria (CAUCHY, RESIDUAL)
CONV_FIELD= RMS_DENSITY
%
% Min value of the residual (log10 of the residual)
CONV_RESIDUAL_MINVAL= -11
%
% Start convergence criteria at iteration number
CONV_STARTITER= 10
%
% Number of elements to apply the criteria
CONV_CAUCHY_ELEMS= 100
%
% Epsilon to control the series convergence
CONV_CAUCHY_EPS= 1E-10

% ------------------------- INPUT/OUTPUT INFORMATION --------------------------%
%
% Mesh input file
MESH_FILENAME= mesh.su2
%
% Mesh input file format (SU2, CGNS, NETCDF_ASCII)
MESH_FORMAT= SU2
%
% Mesh output file
MESH_OUT_FILENAME= mesh_out.su2
%
% Restart flow input file
SOLUTION_FILENAME= solution_flow.dat
%
% Restart adjoint input file
SOLUTION_ADJ_FILENAME= solution_adj.dat
%
% Output tabular format (CSV, TECPLOT)
TABULAR_FORMAT= CSV
%
% Output file convergence history (w/o extension) 
CONV_FILENAME= history
%
% Output file restart flow
RESTART_FILENAME= restart_flow.dat
%
% Output file restart adjoint
RESTART_ADJ_FILENAME= restart_adj.dat
%
% Output file flow (w/o extension) variables
VOLUME_FILENAME= flow
%
% Output file adjoint (w/o extension) variables
VOLUME_ADJ_FILENAME= adjoint
%
% Output objective function gradient (using continuous adjoint)
GRAD_OBJFUNC_FILENAME= of_grad.dat
%
% Output file surface flow coefficient (w/o extension)
SURFACE_FILENAME= surface_flow
%
% Output file surface adjoint coefficient (w/o extension)
SURFACE_ADJ_FILENAME= surface_adjoint
%
% Writing solution file frequency
OUTPUT_WRT_FREQ = 100
%
% Writing convergence history frequency
SCREEN_WRT_FREQ_INNER = 1
% 
% Screen output
SCREEN_OUTPUT=(INNER_ITER, WALL_TIME, RMS_DENSITY)
