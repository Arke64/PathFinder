# PathFinder

Given a file that represents a rectangular grid, find the shortest path from the provided start and end coordinates. Each cell in the grid has a cost to pass through it, with unpassable cells having a cost of zero.

Input format:
```
[width] [height]
[start x] [start y]
[end x] [end y]
[x0 y0] ... [xn y0]
...
[x0 yn] ... [xn yn]
```

Example input:
```
5 4
0 0
3 0
1 1 6 1 0
0 1 0 1 0
0 1 1 1 0
0 0 0 0 0
```

Output format:
```
[total cost]
[x0 y0] ... [xn y0]
...
[x0 yn] ... [xn yn]
```

Example output (from above input):
```
8
X X 0 X 0
0 X 0 X 0
0 X X X 0
0 0 0 0 0
```
