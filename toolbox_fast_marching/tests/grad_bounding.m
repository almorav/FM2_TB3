function grad=grad_bounding(grad,tang)
sizegrad=size(grad);

for i=1:sizegrad(1)
    for j=1:sizegrad(2)
        
        if (grad(i,j,1)~=0)&&(atan2(grad(i,j,2),grad(i,j,1))> tang)
            grad(i,j,2)=-tang*grad(i,j,1);
        end
        if (grad(i,j,1)~=0)&&(atan2(grad(i,j,2),grad(i,j,1))< -tang)
            grad(i,j,2)=+tang*grad(i,j,1);
        end
    end
end

end