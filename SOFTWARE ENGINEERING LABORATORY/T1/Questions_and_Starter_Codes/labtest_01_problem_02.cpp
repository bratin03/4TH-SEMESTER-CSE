#include <bits/stdc++.h>
using namespace std;

// Define the Player class

// Define the Zombie class

// Define the Runner class, which is a subclass of Zombie

// Define the Stalker class, which is a subclass of Zombie

// Define the Clicker class, which is a subclass of Zombie

// Define the Bloater class, which is a subclass of Zombie

// The main function of the program
int main()
{
    // Create an instance of the Player class and initialize the number of zombies
    Player ellie;
    int numZombies = 4;

    // Create a pointer array of Zombie objects and dynamically allocate memory for them
    Zombie **zombies = new Zombie *[numZombies];

    // Initialize the array with instances of the various Zombie subclasses
    zombies[0] = new Runner(true);
    zombies[1] = new Stalker(false);
    zombies[2] = new Clicker(true);
    zombies[3] = new Bloater(true);

    // Loop through the array and add the value of each dead zombie to the player's score
    for (int i = 0; i < numZombies; i++)
    {
        if (zombies[i]->isDead())
            ellie.addToScore(zombies[i]->getValue());
    }

    // Print the player's score to the console
    cout << "Ellie's score: " << ellie.getScore() << endl;

    // Deallocate memory for the Zombie array
    for (int i = 0; i < numZombies; i++)
    {
        delete zombies[i];
    }
    delete[] zombies;

    // Return 0 to indicate successful program execution
    return 0;
}