#Thank God For UMich: https://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/glfw/
#This runs on Linux Manjaro but not particularly Windows.  TBD.
#(That's right, we're starting in Manjaro.  Why?  Because I have a box that runs Manjaro.  Weep.)
main_linux: 
	gcc src/main.c -o MelJet -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread

main_windows:
	gcc src/main.c -o MelJet -lglfw3 -lopengl32 -lgdi32 -lOpenCL