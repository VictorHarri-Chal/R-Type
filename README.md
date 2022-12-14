[![Build](https://img.shields.io/github/workflow/status/JohanCDev/Bomberman/Build)](https://github.com/VictorHarri-Chal/R-Type/actions/workflows/build.yml)

# :rocket:  What is R-Type ?
Our project R-Type is an ersatz of the famous [R-Type](https://www.youtube.com/watch?v=2xAX6XTzpg0) arcade game, the purpose of the game is to control a ship and navigate throught the space while shooting and destroying ennemy ships.

However, the specifity of our game is that we implemented a multiplayer mode that allow you to play in coop from 2 to 4 players.

Our game also dispose of two difficulties, EASY and HARD as well as a WAVE EDITOR in order to modify monster spawning during the game (check SCRIPT.md on the documentation to have more informations about it).

# In game preview
![Menu](menu.png)
![Classes](classes.png)
![Game](game1.png)
![Boss](game2.png)

# :star:  Pre-compiled version for the impatient ones
You can look on the right side of our repository, in the [Releases](https://github.com/VictorHarri-Chal/R-Type/releases) section in order to download a pre-compiled version depending on your operating system to play right away

# :computer:  Supported Platforms
Our project can be played on both ```Linux``` and ```Windows``` OS as well as ```MacOS``` and ```Raspberry Pi```

# :hammer:  Building
To build our project you need to execute a simple script a the root of our repository.

It will take care of dowloading the dependencies as well as compiling the code.

```./install.sh```

After that you need to call the server, you can execute this command: 

```./r-type_server```

And then, you can connect as many clients as you wish with this command:

```./r-type_client```

You can specify a ```-g``` after the ```./r-type_client``` if you want to play immediatly in solo mode without going through menus.

Or you can specify a ```-w``` if you want to have the menus and the solo mode in windowed (fullscreen by default).

### On Linux, Windows & Mac
The dependencies are [CMake](https://cmake.org/), [SFML](https://www.sfml-dev.org/index-fr.php) and [Boost](https://boost.org).

# :video_game:  How to play

  Move with the ```ARROW KEYS```, shoot with ```SPACE``` and use your class skill with ```C```

# :page_with_curl:  Documentation
To read our project documentation, you need to execute a script in order to open a local web page.

```./run_documentation.sh```

You can also look [here](https://victorharri-chal.github.io/R-Type/), to look out directly at our online documentation.

You can check our ```RFC``` that details the communication protocol between the server and the clients [here](https://simonlefourn.notion.site/Network-db4461454b9d44e78efc64aecb0cddb7).

# :dancers:  Authors
[Henri Chauvet](https://github.com/H-chauvet) - [Nathan Le Bigot](https://github.com/nlbxyz) - [Matthis Lesur](https://github.com/tistech0) - [Simon Le Fourn](https://github.com/simlf) - [Victor Harri-Chal](https://github.com/VictorHarri-Chal)
