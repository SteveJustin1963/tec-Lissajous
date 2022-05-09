: lissajous    ( -- )
    0 0 150 150 1 1 360 0 do
        dup a * sin i * c * round 300 + x !
        dup b * sin i * d * round 300 + y !
        15 putpixel
    loop
;
