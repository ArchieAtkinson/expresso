# XXXXXXXXXX

## Usage
### Building and running the Project
First we need to get the project onto our local machine. This can be done two ways, either by downloading the repo from the Github website by using the `Code` button (or clicking this [link](https://github.com/ArchieAtkinson/XXXXXXXXXX/archive/refs/heads/main.zip)) or by using git.

To download repo with git we will clone the repo:
- Open Git Bash and navigate to where you would like the repo stored.
- Then clone it with the following command:  
  - `git clone https://github.com/ArchieAtkinson/XXXXXXXXXX.git`  

Once it has finished downloading (and you have unzipped if not using git) you are ready to start building and running the demo project.       

- Create a build directory with:
    - `mkdir build`    
- Configure CMake with Make as the generator:
    - `cmake -S . -B build -G "MinGW Makefiles"`
- To create a debug build just add the below flag to the end of the previous command:
  -  `-DCMAKE_BUILD_TYPE=Debug`  
- Now to build the project:
  - `cmake --build build`    

## End Note
I plan to expand this project over time to cover more us cases and platforms. Feel free to create issues if you are having problem and I'll do my best to help, please be as descriptive as possible. Pull request are also welcome to improve the current template or add more.


## Notes:

TODO:
Add (^ fail to bracket checker
Add bracket detection to ^ split code

Bracket and Indices will have to be done recursively 

BIDMAS 

Brackets        ()
Indices         ^
Divide          /
Multiplication  *
Add             +
Sub             - 

negatives       -1
positive        +1 or 1
