
g = @(t)exp(-t);  % food residues in stomach with time
F = zeros(1,240);
F(70) = 5;
F(120) = 5;
F(180) = 3;      % diet schedule in 7am, 12am and 18am
t = linspace(0,24,240)';
G = g(t);
H = conv(F,G);   % calculate the food residues along one day following the diet schedule BY CONVOLUTION
% H = conv(G,F);

figure;
plot(H);
%stem(t,f);