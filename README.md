# Monte-Carlo-Pi-Approximation
An approximation of pi using randomized points on a circle inscribed on a square.

## Idea:
We inscribe a circle of radius r onto a square of length 2r. The area of a circle and the area of a square are then as follows:<br>
`A_circle  = pi*r^2`<br>
`A_square  = (2r)^2 = 4r^2`<br>

We plot multiple random points (x,y) with x,y in [0,1] and count points that are within the circle only or the circle and the square. The number of points that lands within the square approximates the area of the square and the number of points landing in the circle only approximates the area of the circle. The more random points we generate, the closer we get to approximating the area of each. More random points approximate the areas more accurately. Finally, we can take<br>
`A_circle/A_square = pi/4`

Multiplying this value by 4, we get an approximation of pi.

## Usage
The following flags can be passed in when running the binary to manually set the number of threads or random points used. Both are required to be an integer greater than 0.<br>
-p <number_of_threads><br>
-n <number_of_random_points>

eg. <br>
The following will approximate pi with 1000 random points and split the work to 8 threads.<br>
./IntegralApproximation -p 8 -n 1000
