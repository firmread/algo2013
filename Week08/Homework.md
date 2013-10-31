##Code:
1. Make two compositions using particles and vector fields, with an emphasis on the paths traveled by particles inside of the field.  In class, we saw particles moving through the vector fields, but didn't pay much attention to where they had come from and gone to.  Think about displaying the particles in a way besides just circles.  The vector field can be static or change over time.

2. We looked at a demo of a car steering to a destination.  Could you make a demo with two cars, that avoid each other if they get too close to one another?

Advanced:
3. Take the demo from number 2, and convert it to handle an arbitrary number of cars.
4. Try to create an image based on the values in your vector field.  You can do this by turning the angle of a vector into a color, and then using that in conjunction with ofImage.  You can set individual pixels in ofImage by calling setColor(), but be careful!  Before you can manipulate pixels you need to allocate memory like so: myImg.allocate(someWidth, someHeight, OF_IMAGE_COLOR);