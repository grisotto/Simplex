
var x1 >= 0; #, integer;
var x2 >= 0; #, integer;
var x3 >= 0; #, integer;

maximize z: x1 + 1.2 * x2 + 1.5 * x3;

s.t. a: 4 * x1 + x2 + 0.8 * x3 <= 100;
s.t. b: 0.9 * x1 + x2 + 5 * x3 <= 9.50;
s.t. c: 1.2 * x1 + 3 * x2 + 1.5 * x3 <= 110;
s.t. d: x3 <= 1;
s.t. e: -x1 <= -2;
s.t. f: -x2 <= -2;

