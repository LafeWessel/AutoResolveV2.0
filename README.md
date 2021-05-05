# AutoResolveV2.0
## Introduction
This program is a companion app to a board game I created a long time ago, lovingly referred to as The Game. The Game is a 4X strategy board game that simulates managing an empire, fighting battles, conquering territory, and knocking out opponents. The Game is rather complicated, featuring two primary areas of action: the campaign map and the battle map. The campaign map is where the primary gameplay occurs, the battle map(s) only used when a battle occurs. Since battles can take a significant amount of time to play, I created a AutoResolve app to quickly simulate what would happen in the battle.
## Usage/Installation
The codebase contains all of the relevant code (.h/.cpp) files for testing and running the project. The simplest way to run would be to use Visual Studio to open the .sln file then compile and run as necessary. If using a different compilation system, there are a few things to note:
- The code in the UnitTests folder does not need to be compiled for the program to run, it only contains unit tests that I wrote to verify the code.
- The equipment.txt, units.txt, NormalData.txt, SiegeData.txt, NavalData.txt, RaidData.txt, and MonsterData.txt files must all be in the same location as the compiled executable when this program is run.
## Planned Updates
- Qt GUI
- Writing documentation (more than just comments)
