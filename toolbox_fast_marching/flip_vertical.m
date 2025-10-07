function W1=flip_vertical(W);
filas=size(W,1);
W1=W(filas:-1:1,:);