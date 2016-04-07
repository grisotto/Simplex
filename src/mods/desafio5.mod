var a1 >= 0;
var a2 >= 0;
var a3 >= 0;
var aa >= 0;

maximize z: 
	59 * a1 + 85 * a2 + 80 * a3 + aa;

s.t. area: a1 + a2 + a3 + aa <= 10000;
s.t. homenshora: .45 * a1 + .6 * a2 + .5 * a3 <= 5400;
s.t. finan: 17 * a1 + 19 * a2 + 25 * a3 <= 180000;
s.t. deman_a2: 5 * a2 <= 25000;
s.t. deman_a3: 8 * a3 <= 30000;
