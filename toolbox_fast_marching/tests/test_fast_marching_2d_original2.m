% test for fast marching
%


n = 200;
map_name = 'data/cavern.png';
%map_name = 'data/mountain.png';

%map_name = 'data/room.png';
%map_name = 'constant-map.png';
[Wo, cm] = imread(map_name);
Wo=double(Wo);
Wo=imresize(Wo,[200,200]);
%W1 = rescale( double(Wo));
%W = W + 0.01;    
%W=double(rescale(bwdist(1-Wo)));
W=Wo.^0.6;



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% pick starting point
[start_points,end_points] = pick_start_end_point(Wo);

options.nb_iter_max = Inf;
options.end_points = end_points;
options.Tmax = sum(size(W));

disp('Performing front propagation.');
[D,S] = perform_fast_marching_2d(W, start_points, options);
disp('Extracting path.');
tic;
path = extract_path_2d(D,end_points, options);
toc;
figure
plot_fast_marching_2d(W,[],path,start_points,end_points);
colormap gray(256);

figure;h=surf(D)
colormap jet
%set(h,'EdgeColor','none')