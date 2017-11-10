w1=[1.2 0 0];
w2= [0 1.6 0];
u= [-0.15 0 0];
r1= [-0.75 0.3 0.6];
r2=[-0.25 0 0.6];

a= cross(w1,cross(w1,r1))+cross(w2,cross(w2,r2))+2*cross(w2,u)+2*cross(w1,(u+cross(w2,r2)));
display(a);

b= cross(w1,r1)+u+cross(w2,r2);
display(b);