#include <iostream>
#include <ctime>

void PrintIntroduction()
{
    std::cout << "**************************************************************************\n";    
    std::cout << "*     -  You are a secret agent breaking into a server room  -           *\n";
    std::cout << "*     -  Enter the correct 3 numbers to breach the security level  -     *\n";
    std::cout << "*     -  The security system has 5 levels  -                             *\n";
    std::cout << "*     -  Get through all of them to reach the core  -                    *\n";
    std::cout << "*     -  Now go, and dont mess it up  -                                  *\n";
    std::cout << "**************************************************************************\n";


}

bool PlayGame(int LevelDifficulty, int Failures)
{


    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;                         
   
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl; 
    std::cout << std::endl; 
    std::cout << "Security Level " << LevelDifficulty;
    std::cout << "\n+ The codes add-up to:  " << CodeSum << std::endl;
    std::cout << "+ And multiplies to:    " << CodeProduct << std::endl;
    std::cout << std::endl;

    int GuessA = 0, GuessB = 0, GuessC = 0;

    std::cout << "+ Enter Code:      \n";
    std::cout << " A: ";
    std::cin >> GuessA;
    std::cout << " B: ";
    std::cin >> GuessB;
    std::cout << " C: ";
    std::cin >> GuessC;
    std::cout << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "Initializing Code..." << GuessA << " " << GuessB << " " << GuessC << std::endl;
    std::cout << "Sums up to ......" << GuessSum << std::endl;
    std::cout << "Multiplies to ..." << GuessProduct << std::endl;
    std::cout << std::endl;

    // Check if Player is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "************************\n";
        std::cout << "*     Code....OK       *\n";
        std::cout << "*    Failures = " << Failures << "      *\n";
        std::cout << "************************";
        return true;
    }
    else
    {
        ++Failures;
        std::cout << "************************\n";
        std::cout << "*   Code....Invalid    *\n";
        std::cout << "*    Failures = " << Failures << "      *\n";
        std::cout << "************************";
        return false;
    }

   

}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    int Failures = 0;                   // !Still needs to be added into the Game!
    //int const MaxFailures = 3;
    PrintIntroduction();
    while (LevelDifficulty <= MaxDifficulty)        // Loops the game, until all levels shall be completed
    {
        bool bLevelCompleted = PlayGame(LevelDifficulty, Failures);
        std::cin.clear();                           //Clears any input errors to prevent wrong characters causing an endloop
        std::cin.ignore();                          //Discards the buffer after the PlayGame

        if (bLevelCompleted)
        {
            ++LevelDifficulty;
        }
        else
        {
            ++Failures;
        }
        
      
        
        
    }
    std::cout << "\n***********************************************\n";
    std::cout << "*     Security system has been breached       *\n";
    std::cout << "*            Full access granted              *\n";
    std::cout << "***********************************************\n";

    if (Failures == 0)
    {
        std::cout << " Congratulations Agent! You haven't failed us a single time. Let's talk about a promotion !";
    }
    else
    {
        std::cout << "Glad you still made it ! But you failed " << Failures << " time(s). Back to your training agent !";
    }
    
    
    return 0;
}