var x1 >= 0;
var x2 >= 0;

maximize z: 20 * x1 + 50 * x2;

s.t. a: 2 * x1 + 4 * x2 <= 240;
s.t. b: x1 <= 100;
s.t. c: -0.2 * x1 + 0.8 * x2 <= 0;

