# ReadMe

## How To run the file

param 1: type
param 2: width
param 3: height

./fract-ol mandelbrot "800" "800"

param 1: type
param 2: width
param 3: height
param 4: cx
param 5: cy
./fract-ol julia "800" "800" "1.234" "-1.234" 

./fract-ol burningship 800 800 x y

## Keypress

53 == escape
126 == upkey | yshift
125 == downkey | yshift
123 == left | xshift
124 == right | xshift
24 == ++ | zoomin
27 == -- | zoomout
15 == r | reset


## Important

How to draw pixels into the image?
The pixel data is initialized to 0, meaning every pixel will be black without alpha.

The pixel data is a single array of width * height * 4 bytes. 
For a 500x500 image, we would need 1’000’000 bytes or about 0.953 MB. [500*500*4 = 1,000,000]

The way I like to iterate this array when pixel_bits == 32 is:
y is the Y coordinate in the image.
y == 0 is the first (top) pixel within the image.
y * line_bytes lets us move up/down in pixel coordinates.

x is the X coordinate in the image.
x == 0 is the first (left) pixel.
x lets us move left/right in pixel coordinates.

Remember that one pixel on screen requires 4 bytes in memory.
Remember that buffer is a char *.

When you increment the pointer by one by one, you’re moving forward one byte in memory, so the final offset should be multiplied by 4.
(y * line_bytes) + (x * 4) is the beginning of the data for that screen pixel.

Manual:
1. Check how many bits per pixel
2. Convert your color with mlx_get_color_value
3. Check whether little or big endian
4. write color value byte by byte into pixel array according to endian

### Notes

1. We can add in the parameters for the window size which will be the same as image size. 

### Reference

> https://github.com/GlThibault/Fractol/?source=post_page-----6664b6b045b5--------------------------------

> https://harm-smits.github.io/42docs/libs/minilibx/events.html

> https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html?source=post_page-----6664b6b045b5--------------------------------