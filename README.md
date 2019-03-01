# NQueensProblem
Implementation to solve the NQueensProblem using a depth first search

## Usage
```
$ NQueens.out <n> [-d]
```
The executable takes in one required parameter, and one optional
* `n` is the size of the board
* `-d` enables the debugging message, which displays which queen will kill a queen placed at a position

## Error codes
* `0`: success
* `1`: invalid arguments

## Example Outputs
* Without debugging messages  
```
$ ./NQueens.out 8
  0 1 2 3 4 5 6 7
0 q . . . . . . .
1 . . . . . . q .
2 . . . . q . . .
3 . . . . . . . q
4 . q . . . . . .
5 . . . q . . . .
6 . . . . . q . .
7 . . q . . . . .
```
* With debugging messages
```
$ ./NQueens.out 4 -d
Queen at 1,0 would be killed by 0,0
Queen at 1,1 would be killed by 0,0
Queen at 2,0 would be killed by 0,0
Queen at 2,1 would be killed by 1,2
Queen at 2,2 would be killed by 1,2
Queen at 2,3 would be killed by 1,2
Queen at 2,0 would be killed by 0,0
Queen at 3,0 would be killed by 0,0
Queen at 3,1 would be killed by 2,1
Queen at 3,2 would be killed by 2,1
Queen at 3,3 would be killed by 1,3
Queen at 2,2 would be killed by 0,0
Queen at 2,3 would be killed by 1,3
Queen at 1,0 would be killed by 0,1
Queen at 1,1 would be killed by 0,1
Queen at 1,2 would be killed by 0,1
Queen at 3,0 would be killed by 2,0
Queen at 3,1 would be killed by 0,1
  0 1 2 3
0 . . q .
1 q . . .
2 . . . q
3 . q . .
```
