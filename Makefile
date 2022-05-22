#Thank God For UMich: https://web.eecs.umich.edu/~sugih/courses/eecs487/glut-howto/glfw/
#This runs on Linux Manjaro but not particularly Windows.  TBD.
#(That's right, we're starting in Manjaro.  Why?  Because I have a box that runs Manjaro.  Weep.)

CC := g++

default: main_linux

main_linux: utils
	${CC} src/*.cc *.o -o MelJet -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -lGLEW

main_windows:
	${CC} -c src/utils/util_files.c
	${CC} src/main.cc -o MelJet -lglfw3 -lopengl32 -lgdi32 -lOpenCL

utils:
	${CC} -c src/utils/*.c

clean:
	rm MelJet