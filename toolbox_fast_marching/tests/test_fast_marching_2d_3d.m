clear all
close all

% test for fast marching
%


n = 200;
%map_name = 'data/cavern.png';
%map_name = 'data/mountain.png';

map_name = 'data/room.png';
%map_name = 'constant-map.png';
[Wo, cm] = imread(map_name);
%%W = rescale( double(Wo));
%W = W + 0.01;    
W=double(rescale(FMdist(Wo)));
% W=W.^0.6;



%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% pick starting point
%[start_points,end_points] = pick_start_end_point(Wo);
start_points=[8;13];
end_points=[7;65];

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
colormap parula

%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[baseWo,alturaWo]=size(Wo);
Wo3=zeros(baseWo,alturaWo,30);
for i=1:30
    Wo3(:,:,i)=Wo;
end
W3=rescale(bwdist(Wo3));

x = linspace(1, length(path),length(path));

%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

distancias=zeros(length(path),1);
for i=2:(length(path)),
distancias(i)=distancias(i-1)+sqrt(sum((path(i,:)-path(i-1,:)).^2));
end
nivel_de_vuelo_deseado=30; %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
angulo_maximo_deseado_grados=30; % 30 grados%%%%%%%%%%%%%%%%%%%%%%%%%%
angulo_maximo_deseado_rad = angulo_maximo_deseado_grados*pi/180;
tan_ang_max=(tan(angulo_maximo_deseado_rad));% 1=nivel 1 de vuelo
sigma=17/(sqrt(exp(1))*tan_ang_max); % desviacion tipica

% Ahora hay que pasar la desviación tipica a numero de puntos en el path


[val1,idx1]=min(abs(distancias-1*sigma)); % idx1 es el numero del punto correspondiente a 1*sigma
idx2=2*idx1; %% idx2 es el numero del punto correspondiente a c1-sigma=2*sigma
idx3=3*idx1;%idx3 es el numero del punto correspondiente a c1 (centro de la 1a gaussiana)=3*sigma
%minVal=distancias(idx)

long=length(path);
%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%mf=fismf('gauss2mf',[113.3 367.6 113.3 434.4]*long/801);
mf=fismf('gauss2mf',[idx1 idx3 idx1 long-idx3]);
z = nivel_de_vuelo_deseado*evalmf(mf,x);
path3=[path,z'];
figure;isosurface(Wo3,100);
hold on
isocaps(W3,0.01);
plot3(path3(:,2),path3(:,1),path3(:,3),'LineWidth',2)

figure; plot(distancias,z,'LineWidth',2)
axis ([0,80,0,32])
grid on


