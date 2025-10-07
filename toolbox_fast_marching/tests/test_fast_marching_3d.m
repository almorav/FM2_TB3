% test for fast marching
%
close all
clear

n = 40;

% gaussian weight (path will avoid center of the cube)
x = -1:2/(n-1):1;
x2=-1:2/(4*(n-1)):1;
[X,Y,Z] = meshgrid(x,x2,x);
sigma = 0.4;
W = 1./(1 + exp( -(X.^2+Y.^2+Z.^2)/sigma^2 ) );

k = 5;
% start_points = [n-k;k;k];
% end_points = [k;n-k;n-k];
start_points = [4*n-k;k;n/2+1];
end_points = [k;n-k;n/2+1];

options.end_points=end_points;
tic
[D,S] = perform_fast_marching(W, start_points, options);
toc
tic
path = compute_geodesic(D,end_points);
toc
%path = compute_discrete_geodesic(D,end_points);
%path2 = smoothn({path(1,:),path(2,:),path(3,:)},20,'robust');


% 
% % draw the path
% plot_fast_marching_3d(D,S,path,start_points,end_points);
% %plot_fast_marching_3d(D,S,[path2{1,1}',path2{1,2}',path2{1,3}'],start_points,end_points);
 xlabel('X');ylabel('Y');zlabel('Z');
 grid on
 figure;plot_fast_marching_3d(W,S,path,start_points,end_points);
 axis tight
 