# Cars Cheats

This project is focussed on trying to create a cheat client for the almost 20 year old video "Cars: The video Game" (2006).

As a kid, I played the disk of this game gray. I used to find this game so cool, and always thought the game was way ahead of its time.

Unfortunately, I can't really find a modding community for this game, so I wanted to start experimenting a bit with it myself. This repo will contain some basic cheats, but don't expect a full mod.

## Supported features

- [x] Increase score (press Enter)
- [x] Teleport the car in all directions (M, I, J, L, K)

## Todo

- [ ] Full Freecam
- [ ] Unlimited nitrous (is an existing feature, but idc)
- [ ] Speedhack
- [ ] Change into any car
- [ ] UI overlay (ImGui?)

## Tools used

- [DxWnd](https://sourceforge.net/projects/dxwnd/) (for running the game windowed, easier with debugging)
- [Cheat Engine](https://www.cheatengine.org/) for memory analysing & assembly debugging
- [Ghidra](https://ghidra-sre.org/) for reverse engineering and understanding game mechanics
