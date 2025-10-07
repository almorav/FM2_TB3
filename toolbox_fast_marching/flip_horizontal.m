function W1=flip_horizontal(W);
col=size(W,2);
W1=W(:,col:-1:1);