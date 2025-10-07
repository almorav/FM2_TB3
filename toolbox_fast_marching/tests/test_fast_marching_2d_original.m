% test for fast marching
%
% 
% 
% %n = 200;
% %map_name = 'data/cavern.png';
% %map_name = 'data/mountain.png';
% 
% map_name = 'data/room.png';
% %map_name = 'constant-map.png';
 map_name = 'atazar_open.png';
 [Wo, cm] = imread(map_name);
 Wo=Wo(:,:,1);
% %%W = rescale( double(Wo));
% %W = W + 0.01;    
%Wo=imresize(WJJ,1/8);
%Wo=WJJ;
W=(double(rescale(FMdist(Wo)))).^0.5;
 %W=W.^0.6;
%W=double((Wo>0));


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% pick starting point
[start_points,end_points] = pick_start_end_point(Wo);

%options.nb_iter_max = Inf;
options.end_points = end_points;
%options.Tmax = Inf;

disp('Performing front propagation.');
[D,S] = perform_fast_marching_2d(W, start_points, options);
disp('Extracting path.');
tic;
path = extract_path_2d(D,end_points, options);
toc;

figure
subplot(1, 4, 1)
imagesc(imrotate(double(Wo),90))
colormap gray
axis image;
axis off

subplot(1,4, 2)
imagesc(imrotate(W,90))
colormap gray
axis image;
axis off

subplot(1,4, 3)
D(isinf(D)) = 0;
%D = D( ~any( isnan( D ) | isinf( D ), 2 ),: )
colormap parula
imagesc(imrotate(D,90))
axis image;
axis off

subplot(1,4, 4)
plot_fast_marching_2d(Wo,[],path,start_points,end_points);
colormap gray
axis tight
axis off

colormap parula