*This project has been created as part of the 42 curriculum by matiguti.*

### Description

**so_long** is a 2D game project built using the MiniLibX graphics library. The goal is to create a small game where a player moves through a map, collects all items, and reaches the exit.

The program receives a map file (`.ber`) as argument, validates it, and launches the game window. The player moves using WASD or arrow keys, must collect all coins before the exit unlocks, and the number of moves is displayed in the terminal at each step.

Map elements:
- `1`: wall
- `0`: empty floor
- `P`: player starting position
- `C`: collectible
- `E`: exit

### Instructions

## Compilation & Execution

```
make
./so_long <map.ber>
```

Example:

```
./so_long maps/valid_small.ber
```

Controls:
- `W` / `↑` : move up
- `S` / `↓` : move down
- `A` / `←` : move left
- `D` / `→` : move right
- `ESC` : quit

### Map rules
- Must be rectangular
- Must be surrounded by walls
- Must contain exactly 1 `P`, 1 `E`, and at least 1 `C`
- All collectibles and the exit must be reachable from the player's starting position

### Resources

- https://harm-smits.github.io/42docs/libs/minilibx
- https://42-cursus.gitbook.io/guide/2-rank-02/so_long

## AI Usage

AI was used in this project for:
- **Understanding the subject**: clarifying the project requirements and constraints
- **Comprehension of the flood fill algorithm**: understanding how the algorithm works and how to use it to validate map paths
- **MiniLibX usage**: understanding how hooks, the event loop, and image rendering work
