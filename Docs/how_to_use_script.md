# SCRIPT

## How it works

Our script reader parse the lines from the script one by one.
There is 2 types of lines :
- A solo number -> representing a new wave arrival
- Multiple numbers -> representing an enemy entity with all her caracteristics


## An exemple

Ex :  5                1      0     1    1 1000   1100    1
Means sf::seconds(5.f) ZIGZAG false true 1 1000.f 1100.f  true


First param -> timestamp : sf::Time elapsed since the start in second
Second param -> ship type : 1 if ZIGZAG - 2 if RUSHER - 3 if KAMIKAZE - 4 if TURRET
Third param -> horizontal direction : 0 if left - 1 if right
Fourth param -> vertical direction : 0 if up - 1 if down
Fifth param -> current wave number
Sixth param -> x position
Seventh param -> y position
Eight param -> is the sprite printed ?


## Your turn

You can add new enemies as you wish, you just need to write a new line with custom caracteristics !

## About ship type

You maybe don't know much about the differents enemies you can create, so i'll explain it

ZIGZAG : Moves verticaly - Normal health - Normal damage - Slow cadency
RUSHER : Moves horizontaly on you - Low health - Normal damage - Normal cadency
KAMIKAZE : Moves horizontaly on you and then explode - Low health - High damage - Don't shoot
TURRET : Place himself and then stay static - High health - Normal damage - High cadency

