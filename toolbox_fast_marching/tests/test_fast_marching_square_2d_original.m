% test for fast marching
%
clear all
%
% %n = 200;
% %map_name = 'data/cavern.png';
% %map_name = 'data/mountain.png';
%
% map_name = 'data/room.png';
% %map_name = 'constant-map.png';
% map_name = 'atazar_open.png';
%map_name = 'lasermap2.png';
map_name = 'house.png';
[Wo, cm] = imread(map_name);
Wo = im2bw(Wo, 0.9);
Wo=imresize(Wo,0.5);
figure
imagesc(imrotate(Wo,90));
axis tight
axis off
colormap gray


Wo=Wo(:,:,1);


%% %%W = rescale( double(Wo));
%W = W + 0.01;
%Wo=imresize(WJJ,1/8);
%Wo=WJJ;
%
se = strel('disk',2);
Wo=imclose(Wo,se);
% Wo = 1-imdilate(1-Wo,se);


W=(double(rescale(FMdist(Wo)))).^0.8;


%W=W.^0.6;
%W=double((Wo>0));


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% pick starting point
%[start_points,end_points] = pick_start_end_point(Wo);
end_points=[267;284];
start_points=[312;586];


 options.nb_iter_max = Inf;
 options.end_points = end_points;
 options.Tmax = Inf;
 options.method = 'continuous';

disp('Performing front propagation.');
[D,S] = perform_fast_marching_2d(W, start_points, options);
disp('Extracting path.');
tic;
path = extract_path_2d(D,end_points, options);
toc;
%
% figure
% subplot(1, 4, 1)
% imagesc(imrotate(double(Wo),90))
% colormap gray
% axis image;
% axis off
%
% subplot(1,4, 2)
% imagesc(imrotate(W,90))
% colormap gray
% axis image;
% axis off
%
% subplot(1,4, 3)
% D(isinf(D)) = 0;
% %D = D( ~any( isnan( D ) | isinf( D ), 0 ),: );
% colormap parula
% imagesc(imrotate(D,90))
% axis image;
% axis off

%subplot(1,4, 4)
figure
plot_fast_marching_2d(W,[],path,start_points,end_points);
colormap gray
axis tight
axis off
%
figure
D(isnan(D)) = 0;D(isinf(D)) = 0;
%imagesc(imrotate(D,90));
plot_fast_marching_2d((D),[],path,start_points,end_points);
colormap parula
axis tight
axis off
% colormap parula