# push_swap

## Features
This project is the sorting data on a stack with a limited set of instructions using the lowest possible number of actions.

| Program name | push_swap |
| ---- | ---- |
| Makefile | all, clean, fclean, re, bonus |
| Arguments | numbers on integer　type |

## Requirement
- gcc compiler

## Usage
Clone this repository:
```shell
git clone https://github.com/sakku-14/push_swap
```

Generate ***push_swap***:
```shell
make
```

Generate ***checker***:
```shell
make bonus
```

Run ***push_swap***:
```shell
./push_swap 3 2 1
```

Run ***checker***:
```shell
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG;
```

***ここからまだ!!!!***

You can also edit ***map.cub*** or create other ***.cub files***:

There are 9 elements in .cub file.
- ***Resolution***
  - Identifier: ***R***
  - Has two num of x and y render size
- ***North texture***
  - Identifier: ***NO***
  - Has path to the north texture
- ***South texture***
  - Identifier: ***SO***
  - Has path to the south texture
- ***West texture***
  - Identifier: ***WE***
  - Has path to the west texture
- ***East texture***
  - Identifier: ***EA***
  - Has path to the east texture
- ***Sprite texture***
  - Identifier: ***S***
  - Has path to the sprite texture
- ***Floor color***
  - Identifier: ***F***
  - Has R,G,B colors number(0-255): ex) 0, 255, 255 
- ***Ceilling color***
  - Identifier: ***C***
  - Has R,G,B colors number(0-255): ex) 0, 255, 255
- ***Map***
  - Identifier: None
  - 0: Floor
  - 1: Wall
  - 2: Sprite
  - N,S,W,E: player(place and looking the direction of North, South, West, East)
  - Space is validated but any other characters are forbidden.
  - Must be sorrounded by wall.

Example of .cub file:

![map](https://github.com/sakku-14/image_repo/blob/master/cub3d/map_img.png)

## Note

You can create map and move around in the maze freely.

The following is image of what you can do on this program:

................MOVIE HERE......................


## Author
- Yuki Sakuma
