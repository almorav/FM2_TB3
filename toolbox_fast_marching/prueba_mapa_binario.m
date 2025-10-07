
clear all
clc
%%
mex -setup
compile_mex;

%%
addpath('/home/alicia/Documentos/toolbox_fast_marching','/home/alicia/Documentos/toolbox_fast_marching/data','/home/alicia/Documentos/toolbox_fast_marching/toolbox');

%% 
load('pruebaMapaRobotnik.mat');
M=BW;
n=307;
n2=535;
start_points = [247;58];
% use constant metric
W = ones(n,n2);
% create a mask to restrict propagation
L = zeros(n,n2)-Inf; L(M==1) = +Inf;
options.constraint_map = L;
%  do the FM computation
[D,S,Q] = perform_fast_marching(W, start_points, options);
%
% end_points = [165;239];
% end_points = [166;487];
end_points = [163;309];
D1 = D; D1(M==0) = 1e9;
paths = compute_geodesic(D1,end_points);

ms = 30; lw = 3; % size for plot
% display
A = convert_distance_color(D);
clf; hold on;
imageplot(A); axis image; axis off;

h = plot( paths(2,:), paths(1,:), 'k' );
set(h, 'LineWidth', lw);
h = plot(end_points(2),end_points(1), '.b');
set(h, 'MarkerSize', ms);

h = plot(start_points(2),start_points(1), '.r');
set(h, 'MarkerSize', ms);
hold off;
colormap jet(256);
axis ij;