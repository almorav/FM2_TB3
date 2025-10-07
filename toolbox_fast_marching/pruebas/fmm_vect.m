n = 80;
neigh = [[1;0] [-1;0] [0;1] [0;-1]];
boundary = @(x)mod(x-1,n)+1;
ind2sub1 = @(k)[rem(k-1, n)+1; (k - rem(k-1, n) - 1)/n + 1]; 
sub2ind1 = @(u)(u(2)-1)*n+u(1);
Neigh = @(k,i)sub2ind1( boundary(ind2sub1(k)+neigh(:,i)) );

map_name = 'room_b.png';

[Wo, cm] = imread(map_name);
Wo=flip_vertical(Wo(:,:,1));
Wo = Wo';


Wo3=bwdist(~Wo);
W = rescale( double(Wo3) );
W=W(200:n+200,200:n+200);
W = ones(n);

x0 = [n/2;n/2];
I = sub2ind1(x0);
D = zeros(n)+Inf; 
D(I) = 0;
S = zeros(n);
S(I) = 1;
Fx=-0.6;
Fy=0.2;
Q=1;

while ~isempty(I);
    [tmp,j] = sort(D(I)); j = j(1);
    i = I(j); I(j) = [];
    S(i) = -1;
    J = [Neigh(i,1); Neigh(i,2); Neigh(i,3); Neigh(i,4)];
    J(S(J)==-1) = [];
    J1 = J(S(J)==0);
    I = [I; J1];
    S(J1) = 1;
    for j=J'
        dx = min( D([Neigh(j,1) Neigh(j,2)]) );
        dy = min( D([Neigh(j,3) Neigh(j,4)]) );
        Delta = 2*W(j) - (dx-dy)^2;
        if Delta>=0
            D(j) = (dx+dy+sqrt(Delta))/2;
            D(j)=sqrt(D(j)^2+(Fx^2*(D(Neigh(j,1))> D(Neigh(j,2)))-(Fx^2*(D(Neigh(j,1))< D(Neigh(j,2)))))+(Fy^2*(D(Neigh(j,3))> D(Neigh(j,4))))-(Fy^2*(D(Neigh(j,3))< D(Neigh(j,4)))));
        else
            D(j) = min(dx+W(j), dy+W(j)) ;
            D(j)=sqrt(D(j)^2+(Fx^2*(D(Neigh(j,1))> D(Neigh(j,2)))-(Fx^2*(D(Neigh(j,1))< D(Neigh(j,2)))))+(Fy^2*(D(Neigh(j,3))> D(Neigh(j,4))))-(Fy^2*(D(Neigh(j,3))< D(Neigh(j,4)))));
        end
    end
end

displ = @(D)cos(2*pi*5*D/max(D(:)));
clf;
imageplot(displ(D));
colormap jet(256);