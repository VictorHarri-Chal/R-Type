# SCRIPT

## How it works

Our script reader parse the lines from the script one by one.
Each line is representing an enemy entity with all his caracteristics:


## An exemple

Ex :  5                1 1      1000   1100    1
Means sf::seconds(5.f) 1 ZIGZAG 1000.f 1100.f  true


First param -> timestamp : sf::Time elapsed since the start in second
Second param -> current wave number
Third param -> ship type : 1 if ZIGZAG - 2 if RUSHER - 3 if KAMIKAZE - 4 if TURRET - 5 if BOSS
Fourth param -> x position
Fifth param -> y position
Sixth param -> is the sprite printed ?


## Your turn

You can add new enemies as you wish, you just need to write a new line with custom caracteristics !
You can place new enemies in the order you want but keep wave amount to 15 if you want it to work

## About ship type

You maybe don't know much about the differents enemies you can create, so i'll explain it:

ZIGZAG : Moves verticaly - Normal health - Normal damage - Slow cadency
RUSHER : Moves horizontaly on you - Low health - Normal damage - Normal cadency
KAMIKAZE : Moves horizontaly on you and then explode - Low health - High damage - Don't shoot
TURRET : Place himself and then stay static - High health - Normal damage - High cadency
BOSS : Move from left to right - Spawn vertical moving mines
