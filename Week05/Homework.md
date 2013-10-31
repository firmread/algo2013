##Non-Code:
0. Read this paper by Mitch Resnick. http://web.media.mit.edu/~mres/papers/decentralized-modeling.pdf While we won't really get into real world modeling in this class, think about how Resnick uses particle systems to make data beautiful.  Also consider his use of governing rules for particles and how you could work this into your own work.  This paper is the beginning of what would later turn into the book "Turtles, Termites, and Traffic Jams" which is a fantastic book.  The read is dense and technical, but stick with it, and the meat starts around page 5.

After reading it, think of a situation where an individual is goverened by the rules of a system.  Write out what the situation is, and how the particle should act in plain English, not code.  An example from his paper would be his rules for cars in a traffic jam.

• If there is a car close ahead of you, slow down. 
• If there are not any cars close ahead of you, speed up (unless you are already moving at the speed limit). 
• If you detect a radar trap, slow down.

##Code:
1. Use ofxGui and build a particle system that has at least 3 adjustable parameters.  Tweak them to find 3 different sets of parameters that you really like and make a note of the settings in the comments of your program, or save them out in separate xml files.

2. Particles don't have to just be circles though you wouldn't know it from the class examples.  Use images to come up with different effects.  Use what you've learned so far about rotation, opacity, trails etc to make something special.  Dont' feel liks you have to use all of these techniques, use your design sense and good taste to build something you'd want to show to a friend.

3. We're getting to be good friend with sin() and cos() and understand that passing them in the same angle to both at the same time will start to give us nice circular motion.  Use sin/cos to start your particles in interesting positions or with interesting velocities instead of randomness.

Advanced:
4. Build a drawing tool that uses particles to draw in a unique and expressive way.  Think about how someone might use your tool.  Will the user scribble, or should it be slow and controlled? Will you leave color choice up to them?  What features make yours unique from photoshop?