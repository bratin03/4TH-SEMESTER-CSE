/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <bits/stdc++.h>
using namespace std;

// Define the Player class
class Player
{
    double score; // variable to store current score

public:
    Player() {}  // default constructor
    ~Player() {} // destructor
    // fucntion to add score to player
    void addToScore(double x)
    {
        score += x;
    }
    // function to get score of the player
    double getScore() { return score; }
};

// Define the Zombie class
class Zombie // Zombie class
{
public: // virtual function declaration
    virtual bool isDead() = 0;
    virtual double getValue() = 0;
};

// Define the Runner class, which is a subclass of Zombie
class Runner : public Zombie
{
    bool isdead; // Data member to check if Zombie is dead

public:
    Runner(bool entry) : isdead(entry) {} // Constructor
    ~Runner() {}                          // Destructor
    bool isDead() { return isdead; }      // isDead member function to check if zombie is dead
    double getValue() { return 10; }      // Implementation of getValue function
};
// Define the Stalker class, which is a subclass of Zombie
class Stalker : public Zombie
{
    bool isdead; // Data member to check if Zombie is dead

public:
    Stalker(bool entry) : isdead(entry) {} // Constructor
    ~Stalker() {}                          // Destructor
    bool isDead() { return isdead; }       // isDead member function to check if zombie is dead
    double getValue() { return 20; }       // Implementation of getValue function
};
// Define the Clicker class, which is a subclass of Zombie
class Clicker : public Zombie
{
    bool isdead; // Data member to check if Zombie is dead

public:
    Clicker(bool entry) : isdead(entry) {} // Constructor
    ~Clicker() {}                          // Destructor
    bool isDead() { return isdead; }       // isDead member function to check if zombie is dead
    double getValue() { return 30; }       // Implementation of getValue function
};
// Define the Bloater class, which is a subclass of Zombie
class Bloater : public Zombie
{
    bool isdead; // Data member to check if Zombie is dead

public:
    Bloater(bool entry) : isdead(entry) {} // Constructor
    ~Bloater() {}                          // Destructor
    bool isDead() { return isdead; }       // isDead member function to check if zombie is dead
    double getValue() { return 50; }       // Implementation of getValue function
};
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