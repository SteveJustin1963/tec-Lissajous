program lissajous;

uses
  crt;

var
  i, j, x, y, a, b, c, d: integer;

begin
  clrscr;
  x := 0;
  y := 0;
  a := 150;
  b := 150;
  c := 1;
  d := 1;
  for i := 0 to 360 do
  begin
    x := round(a * sin(i * c));
    y := round(b * sin(i * d));
    putpixel(x + 300, y + 300, 15);
  end;
  readln;
end.
