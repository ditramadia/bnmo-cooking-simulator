# Tubes Alstrukdat 1
## About
Tubes 1 of Algorithm and Data Structure (IF2110). A cooking simulator CLI based game made in C. 
## Contributors (Group D)
- 13521001 Angger Ilham Amanullah <br/>
- 13521005 Kelvin Rayhan Alkarim <br/>
- 13521010 Muhamad Salman Hakim Alfarisi <br/>
- 13521019 Ditra Rizqa Amadia <br/>
- 13521023 Kenny Benaya Nathan <br/>
- 13521031 Fahrian Afdholi <br/>
## Division of Tasks
<table>
    <tr>
        <td colspan=3 align="center">Contributors :</td>
    </tr>
    <tr>
        <td>No.</td>
        <td>Student ID</td>
        <td>Tasks</td>
    </tr>
    <tr>
        <td>1.</td>
        <td>13521001</td>
        <td>Features : Foods, Recipe, and Food Processing</td>
    </tr>
    <tr>
        <td>2.</td>
        <td>13521005</td>
        <td>Features : Inventory, Buy Foods, and Delivery</td>
    </tr>
    <tr>
        <td>3.</td>
        <td>13521010</td>
        <td>Inititation, Report, README.md</td>
    </tr>
    <tr>
        <td>4.</td>
        <td>13521019</td>
        <td>Map, Simulator, Main program, Report, and README.md</td>
    </tr>
    <tr>
        <td>5.</td>
        <td>13521023</td>
        <td>Features : Foods, Recipe, and Food Processing</td>
    </tr>
    <tr>
        <td>6.</td>
        <td>13521031</td>
        <td>Features : Foods, Recipe, and Food Processing</td>
    </tr>

</table>

## Game Features
- Configuration
  - Custom configuration file for splash screen, map, foods, and recipe.
- Simulator
  - Map visualization based on map configuration
  - Player movement based on input
  - Player inventory
  - Time mechanism
  - Food expiration
- Buy Foods
  - Buy foods from the shop
  - Delivery mechanism
- Chop Foods
  - Chop foods from inventory
- Mix Foods
  - Mix foods from inventory
- Fry Foods
  - Fry foods from inventory
- Boil Foods
  - Boil foods from inventory
- Utility
  - Undo and redo
  - Wait to skip time
  - Foods catalog
  - Show recipe
## How to Play
- Configuration
  - Create your own map by editing ```/config/map.txt``` <br/>
  `#`: Empty space <br/>
  `X`: Wall <br/>
  `S`: Player <br/>
  `T`: Telephone <br/>
  `C`: Chopping area <br/>
  `M`: Mixing area <br/>
  `F`: Frying area <br/>
  `B`: Boiling area <br/>
  - Create your own lists of foods by editing ```/config/foods.txt```
  - Create your own recipe by editing ```/config/recipe.txt```
- Commands
  - `MOVE NORTH` <br/>
  Move up.
  - `MOVE EAST`<br/>
  Move right. 
  - `MOVE SOUTH` <br/>
  Move down.
  - `MOVE WEST` <br/>
  Move left.
  - `WAIT X Y` <br/>
  Wait X hour and Y minute, used to skip time without doing anything.
  - `BUY` <br/>
  Buy foods from the shop. The delivery time is vary. You can use `WAIT X Y` to skip delivery time. Only available if player's position is adjacent to telephone `T`.
  - `CHOP` <br/>
  Chop foods from inventory. Only available if player's position is adjacent to chopping area `C`.
  - `MIX` <br/>
  Mix foods from inventory. Only available if player's position is adjacent to mixing area `M`.
  - `FRY` <br/>
  Fry foods from inventory. Only available if player's position is adjacent to frying area `F`.
  - `BOIL` <br/>
  Boil foods from inventory. Only available if player's position is adjacent to boiling area `B`.
  - `UNDO` <br/>
  Undo
  - `REDO` <br/>
  Redo
  - `EXIT` <br/>
  Exit game
## Project Structure
```bash
.
├── config --------------------------------------- Configuration folder
│   ├── config.h
│   ├── konfigResep.txt
│   ├── makanan.txt
│   ├── map.txt
│   └── welcome.txt
├── src ------------------------------------------ Folder containing source files
│   ├── adt -------------------------------------- Data Types
│   │   ├── arrayChar ---------------------------- Array of Character
│   │   │   ├── arrayChar.c
│   │   │   └── arrayChar.h
│   │   ├── boolean ------------------------------ Boolean
│   │   │   └── boolean.h
│   │   ├── charmachine -------------------------- Character Machine
│   │   │   ├── charMachine.c
│   │   │   └── charMachine.h
│   │   ├── charmachinefood ---------------------- Char Machine of Food 
│   │   │   ├── charMachine.c
│   │   │   └── charMachine.h
│   │   ├── charmachineresep --------------------- Char Machine of Recipe
│   │   │   ├── charMachine.c
│   │   │   └── charMachine.h
│   │   ├── delivery ----------------------------- Delivery
│   │   │   ├── delivery.c
│   │   │   └── delivery.c
│   │   ├── food --------------------------------- Character Machine
│   │   │   ├── food.c
│   │   │   └── food.h
│   │   ├── gameState ---------------------------- Game State
│   │   │   ├── gameState.c
│   │   │   └── gameState.h
│   │   ├── inventory --------------------------- Inventory
│   │   │   ├── inventory.c
│   │   │   │── inventory.h
│   │   ├── listdin ------------------------------ Dynamic List
│   │   │   ├── listdin.c
│   │   │   └── listdin.h
│   │   ├── liststatik --------------------------- Static List
│   │   │   ├── liststatik.c
│   │   │   └── liststatik.h
│   │   ├── map ---------------------------------- Map
│   │   │   └── map.c
│   │   ├── matrix ------------------------------- Matrix
│   │   │   ├── matrix.c
│   │   │   └── matrix.h
│   │   ├── matrixChar --------------------------- Matrix of Character
│   │   │   ├── matrixChar.c
│   │   │   └── matrixChar.h
│   │   ├── point -------------------------------- Point
│   │   │   ├── point.c
│   │   │   └── point.h
│   │   ├── queuelinked -------------------------- Queue Linked
│   │   │   ├── queuelinked.c
│   │   │   └── queuelinked.h
│   │   ├── stack -------------------------------- Stack
│   │   │   ├── stack.c
│   │   │   └── stack.h
│   │   ├── stackState --------------------------- Stack of Game State
│   │   │   ├── stackState.c
│   │   │   └── stackState.h
│   │   ├── string ------------------------------- String
│   │   │   ├── string.c
│   │   │   └── string.h
│   │   ├── time --------------------------------- Time
│   │   │   ├── time.c
│   │   │   └── time.h
│   │   ├── tree --------------------------------- Tree
│   │   │   ├── tree.c
│   │   │   └── tree.h
│   │   ├── wordmachine -------------------------- Word Machine
│   │   │   ├── wordmachine.c
│   │   │   └── wordmachine.h
│   │   ├── wordmachinefood ---------------------- Word Machine of Food
│   │   │   ├── wordmachine.c
│   │   │   └── wordmachine.h
│   │   └── wordmachineresep --------------------- Word Machine of Recipe
│   │       ├── wordmachine.c
│   │       └── wordmachine.h
│   └── app -------------------------------------- Applications
│       ├── Inisiasi ----------------------------- Main Menu App
│       │   └── splashScreen.c
│       ├── boil --------------------------------- Boil App
│       │   └── boil.c
│       ├── buy ---------------------------------- Buy App
│       │   └── buy.c
│       ├── catalog ------------------------------ Catalog App
│       │   └── catalog.c
│       ├── cookbook ----------------------------- Cookbook App
│       │   └── cookbook.c
│       ├── chop --------------------------------- Chop App
│       │   └── chop.c
│       ├── fry ---------------------------------- Fry App
│       │   └── fry.c
│       ├── mix ---------------------------------- Mix App
│       │   └── mix.c
│       ├── notifikasi --------------------------- Notifikasi App
│       │   └── notifikasi.c
│       └── simulator ---------------------------- Simulator App
│           └── simulator.c
├── BNMO Cooking Simulator.exe ------------------- Main Program
└── README.md
```
## Local Setup
1. Clone this repository
2. Edit configuration file (optional) in ```/config/*```
4. Run ```BNMO Cooking Simulator.exe```
## Technology Used
- C

