% 1) datoteka naloga1_1.txt

delimiterIn="";
headerlinesIn = 2;
data = importdata("naloga1_1.txt",delimiterIn, headerlinesIn);
t = data.data(); %podatki shranjeni v vektor


% 2) uvoz podatkov in izris grafa

fid = fopen("naloga1_2.txt", "r");

line1 = fgetl(fid);
text_npod = strsplit(line1, ": ");
npod_str = text_npod(2);
npod = str2double(npod_str);

P = zeros(0, npod);
for i = 1:1:npod
    line = fgetl(fid);
    P(i) = str2double(line);
end

plot(t, P)
title ("graf P(t)")
xlabel("t[s]")
ylabel("P[W]")


% 3) izracun integala

test_rezult = trapz(t, P)

rezult = 0;
for i = 1:1:(npod-1)
    dt = t(i+1) - t(i); 
    s = dt/2 * (P(i) + P(i+1));
    rezult = rezult + s;
end
rezult
diff = rezult - test_rezult