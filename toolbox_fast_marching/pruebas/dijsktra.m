n = 40;
neigh = [[1;0] [-1;0] [0;1] [0;-1]];
boundary = @(x)mod(x-1,n)+1;
ind2sub1 = @(k)[rem(k-1, n)+1; (k - rem(k-1, n) - 1)/n + 1]; 
sub2ind1 = @(u)(u(2)-1)*n+u(1);
Neigh = @(k,i)sub2ind1( boundary(ind2sub1(k)+neigh(:,i)) );

W = ones(n);
x0 = [n/2;n/2];
I = sub2ind1(x0);
D = zeros(n)+Inf; 
D(I) = 0;
S = zeros(n);
S(I) = 1;


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
        D(j) = min(dx+W(j), dy+W(j));
    end
end

displ = @(D)cos(2*pi*5*D/max(D(:)));
clf;
imageplot(displ(D));
colormap jet(256);