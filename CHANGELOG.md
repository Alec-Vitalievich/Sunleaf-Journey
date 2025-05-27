Changelog:
- Water class now slows the player (and allows swimming - repeated jumping inputs without being on ground) when entered instead of teleporting the player to the start of the level.

- Custom display function moved to Level class instead of Game class, and does not use operator overloading (GUI-based instead).

- Replaced original CLI-based setup class with individual Save_Data and Save_Manager classes (for value retrieval from the save file, and storing values to the save file) and an interactive, GUI-based user menu (which created classes: Menu_Screen, Pause_Screen, End_Screen, 
Game_Over_Screen, Control_Screen, which house their assets for display in the window)

- Replaced banner across the top of the window that would have shown valid user input with the Control Screen in the Menu that explains to the player how certain pieces of the environment works, and what the keyboard controls are. Splash text prompting the user to the next level still appears when entering the Level_Loader object.