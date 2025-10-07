% prueba FM vectorial
clear
%map_name = 'road2.png';
%map_name = 'constant_map.png';
%map_name = 'mountain.png';
%map_name = 'room_b.png';
map_name = 'room.png';

[Wo, cm] = imread(map_name);
Wo=flip_vertical(Wo(:,:,1));
Wo = Wo';


Wo3=bwdist(~Wo);
Wo3 = rescale( double(Wo3) );
figure(1)

% para representacion
W= rescale( double(Wo3) );

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% W=ones(size(W));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% pick starting point
% se traspone para representarlo correctamente en pantalla
%[start_points,end_points] = pick_start_end_point(W);
start_points=[7;21];
end_points=[71;35];
% FMM as usual (options)
options.nb_iter_max = Inf;
options.end_points = end_points;
alpha=0.1;

% New vectorial fields thing
% Create vectorial forces map  Fx, Fy and DFx, DFy
[dim1,dim2]=size(W);
FX =0.5*ones(dim1,dim2);
%FX(:,206:dim2)=-0.99;
FY = 1.0*ones(dim1,dim2);
%N=ones(size(W));%
N=(W+2*alpha)*max(max(sqrt(FX.^2+FY.^2)));
disp('Performing front propagation.');
[D,S] = fast_marching_vectorial_2d(W, start_points, options, FX,FY, N);
figure
imagesc(flip_vertical(W'));
axis equal
axis tight

figure
imagesc(flip_vertical(D'));
colormap jet
axis equal
axis tight
figure
disp('Extracting path.');
path = extract_path_2d(D,end_points, options);
plot_path_2d(Wo,S,path,start_points,end_points);

