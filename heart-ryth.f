
: main
   0.1 10 t!
   : loop
      t@ 2 M_PI * sin 1 + 0.5 * H!
      H@ 0 do
         i@ *
      loop
      CR
   t@ 10 < 
   IF t@ 0.1 + t! THEN
   loop
;
