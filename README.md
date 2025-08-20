# so_long  

A small 2D game written in **C** using the **MiniLibX graphics library**.  
---

## 📖 Project Description  
- Loads a map from a `.ber` file.  
- Map contains walls, a player, collectibles, and an exit.  
- The player must collect all collectibles and reach the exit to win.  
- Invalid maps (wrong shape, missing exit, etc.) are detected and rejected.  
- Flood-fill algorithm ensures the map is solvable.  

---

## ⚙️ Features  
- **Map parsing and validation**  
  - Reads `.ber` maps line by line (`get_next_line`).  
  - Checks rectangular shape and valid characters.  
  - Ensures at least one player, one exit, and one collectible.  
- **Flood-fill algorithm** → verifies that all collectibles and the exit are reachable.  
- **Event handling** with MiniLibX:  
  - Arrow keys / WASD to move the player.  
  - ESC key or window close button to quit.  
- **Graphics rendering** with MiniLibX:  
  - Displays walls, player, collectibles, and exit using `.xpm` images.  
- **Error handling**  
  - Prints clear error messages for invalid maps or missing files.  

---
## 📂 Project Structure  


```
so_long/
├── Makefile
├── so_long.c
├── flood_fill.c
├── is_map_valid.c
├── key_handler.c
├── read_map.c
├── get_next_line.c
├── get_next_line_utils.c
├── assets/
│ ├── libft/ # Custom C library
│ ├── mini-libx/ # Graphics library
│ └── images/ # .xpm files for game graphics
└── maps/
└── example.ber # Example map
```
---
## 🚀 Usage  

### Build  
```bash
make
```
Run
```bash
./so_long maps/example.ber
```
Clean
```bash
make clean    # remove object files
make fclean   # full clean (binary + objects)
```
---
### 🎮 Controls
```
    W / ↑ → Up

    A / ← → Left

    S / ↓ → Down

    D / → → Right

    ESC → Exit
```
---
### 📑 Example Map (.ber)
```
111111
1P0C01
100001
1C0E01
111111
```
    1 = wall
    0 = empty space
    P = player
    C = collectible
    E = exit
