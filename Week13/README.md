In-class references
========
Here are some things we looked at today.

Writing our own factorial function:
------
!n = n * !(n-1);

	int testApp::factorial( int n ){
	    if( n == 0 ){
	        return 1;
	    }else{
	        return (n * factorial( n-1 ));
	    }   
	}

The coastline Paradox
--------
http://en.wikipedia.org/wiki/Coastline_paradox
http://www.youtube.com/watch?v=I_rw-AJqpCM

Benoit B Mandelbrot
---------
http://www.ted.com/talks/benoit_mandelbrot_fractals_the_art_of_roughness.html

Jared Tarbell's generative cities (Substrate)
----------
http://www.complexification.net/gallery/machines/substrate/index.php

Variations on a theme:
--------
https://vimeo.com/11382470
https://vimeo.com/11590284
https://vimeo.com/9481952