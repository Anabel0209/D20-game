# COMP345 - Assignment 1
## D20 Game Instructions
The solution for the game is inside the Game.
The solution is split into 2 projects: 
- **Game** - The main project that contains the game logic and the game driver.
- **TestGame** - The project that contains the unit tests for the game. There will be error as the file structure might be different for whoever wants to run the tests. The tests use the external library CppUnit. Instructions to setup CppUnit are below.

There is a driver file 'Game.cpp' that showcases every part of the assignment.
The TestGame project also contains a driver file 'TestGame.cpp' that runs the unit tests.



## Instructions to install and setup CppUnit
Download from: https://sourceforge.net/projects/cppunit/files/cppunit/1.12.1/

First, to install cppUnit :

    1. Unpack the CppUnit archive file to a directory of your choice, in this example I assume it is D:\.
    2. Go to D:/cppunit-1.12.1/src and open the CppUnitLibraries.dsw in Visual Studio.
    3. Right - click on the cppunit project in the Solution Explorer pane and choose Build.
	4. After successful compilation, cppunit.lib is produced which you then need to setup the Visual Studio Linker with (see below).

To setup a project from scratch for Compilation / Linking:

	  1. Activate 'Project > Properties > C/C++ >  Code Generation > Runtime Library > Multi - threaded Debug DLL'
	  2. Go to 'Project > Properties > C/C++ > General'. Put "D:\cppunit-1.12.1\include" in the 'Additional Include Directories' text box.
	  3. Go to 'Project > Properties > Linker > Input'. Put "D:\cppunit-1.12.1\lib\cppunit.lib" in the 'Additional Dependences' text box.
	  4. Go to 'Project > Properties > Build Events > Post-Build Event'. Put '"$(TargetPath)"' in the 'Command Line' textbox.Put 'Unit Tests...' in the 'Description' textbox.



Team Members:
- **Leila Djeffal**
- **Chance Sztyk**
- **Anabel Prevost**
- **Sebastian Bulgac**