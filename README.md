Winter in MTL
============

This game is a platform game where you have to throw salt at the ice in front of you, or else you'll fall and die.

GLUT setup
==========

Include your GLUT files in your project properties.
C/C++ -> General -> Additional Include Directories: add the folder where the GLUT include file is located.
Linkers -> General -> Additional Lirbary Directories: add the folder where the GLUT library file is located.
Linkers -> Input -> add the following:
opengl32.lib
glu32.lib
freeglut.lib
glut32.lib
