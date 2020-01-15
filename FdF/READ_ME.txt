Instructions :

-To view a Wireframe map, type "./fdf [map] [color]".
-The color is optional. If none is typed in, 0xFFFFFF(White) will be used.
-Controls to manipulate the map are in the fdf window. You can hide those with 'H'.

-------------------------------------

On the topic of colors :

-It is required that a ',' is put before the actual color, otherwise, the
program will not process the color as intended.
Exemple : "./fdf 42.fdf ,0x979797" works (provided the file exists)

-------------------------------------

Particulars cases :

-No/Invalid colors lead to the program using 0xFFFFFF(white) by default.
-No/Invalid coordinates lead to the program using 0 by default.
-One point will not show, not only is it pointless (haha) but the program links
dots together, it doesn't show the points themselves.

