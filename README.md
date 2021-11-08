# Physics_Formula_Class1
Physics_Formula_Class (not a visual physics library, header only, used for solving physics testbook problems)
***WARNING THIS PROJECT WAS NOT MEANT TO BE FAST OR EVEN EFFICIENT THIS IS MY OWN PERSONAL PLAYGROUND WHERE I AM STILL LEARNING ABOUT INTEGRATING DIFFERENT LIBRARIES AND HOW TO UTILIZE THEM WITHIN A PROJECT. THIS PROJECT IS HEAVLY COUPLED AND HAS A LOT OF DEPENDENCIES IF YOU WANT TO TRY TO RUN THIS PROJECT YOU WILL NEED THE FOLLOWING ENVIRONMENT:
1) Visual Studio 2019
2) VCPKG package manager with the following packages installed, be sure to run command 'vcpkg integrate install'
3) vcpkg install gsl:x64-windows
4) vcpkg install symengine:x64-windows
5) vcpkg install eigen3:x64-windows
6) vcpkg install armadillo:x64-windows
7) vcpkg install sfml:x64-windows
8) vcpkg install boost:x64-windows

Though many of these dependencies could be reduced I find myself playing around with many of them so they remain in the includes though not necessarly being used fully. If you wish to reduce coupling you could remove the symengine, gsl, armadillo, boost libraries and the project should still run okay. The eigen, and sfml libraries are used within classes and would break the funtionality of certain classes which would have a dominoe effect so I do not recommend doing this.

Original Readme below:
I decided to make a c++ class called PhysicsWorld and implement each physics example from the open stax college physics text book.
The first few chapters dealing with kinetics were initially implemented in PhysicsWorld cpp file and around chapter 4(DynamicsAndForces) I started seperating the chapters into thier onn unique classes whcih made more sense to me at that time. I will eventually go back and make a kintetics class and move all the methods related to that out of the physics world and the physics world will just be a driver with some static structs of common things like conversions and constants that are used in multiple fields of physics. The initial examples from the first few chapters are worked out and labeled in the oldProblems.txt file under the resources folder. Once I started making individual classes the methods are more from solving the problems from the back of the book as well as the examples but there is no order to it. Methods are named and labeled well so it should be easy to find what you are solving for, as that is usually in the name of the method someplace. 

I intend to extend all these mehtods into a user interface using the QT library. This is the ultimate goal of all this hard work. I envision allowing a user to spcecify what they are trying to solve for, as well as provide a list of known variables which would then open a selection of different equations that are possible for them to use. It will be the ultimate physics calculator when I am  finished. This is my hope and goal. 
