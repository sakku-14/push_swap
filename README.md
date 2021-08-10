# push_swap

## Features
This project is sorting the data on a stack with a limited set of instructions using the lowest possible number of actions.

push_swap program is to show the list of instructions to sort data.

checker program is to check the list of instructions and if it sorts the data, shows "OK". If it is not, shows "KO".

![mov3](https://user-images.githubusercontent.com/65479630/128793172-5ef26317-53fe-469a-8e8e-f533a1054505.gif)


## Requirement
- gcc compiler

## Usage
Clone this repository:
```bash
git clone https://github.com/sakku-14/push_swap
```

Generate ***push_swap***:
```bash
make
```

Generate ***checker***:
```bash
make bonus
```

Run ***push_swap***:
```bash
./push_swap 3 2 1
```

Run ***checker*** in bash:
```bash
./checker 3 2 1
<some instructions here for stdin>
```

Run ***push_swap checker*** in bash:
```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG;
```

## Note

## Author
- Yuki Sakuma
