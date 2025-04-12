#include "Headers.h"

using namespace std;

int main()
{
    srand(time(NULL));

    
    World game(25, 25, 10, 10);
    game.addOrganism(new Antelope{}, 7, 8);
    game.addOrganism(new Antelope{}, 12, 19);
    //game.addOrganism(new Belladonna{}, 8, 3);
    //game.addOrganism(new Belladonna{}, 9, 16);
    game.addOrganism(new Fox{}, 18, 16);
    game.addOrganism(new Fox{}, 6, 21);
    game.addOrganism(new Fox{}, 6, 22);
    game.addOrganism(new Fox{}, 7, 22);
    game.addOrganism(new Fox{}, 5, 22);
    game.addOrganism(new Fox{}, 7, 21);
    game.addOrganism(new Grass{}, 4, 12);
    game.addOrganism(new Grass{}, 6, 8);
    game.addOrganism(new Guarana{}, 1, 1);
    game.addOrganism(new Guarana{}, 8, 1);
    game.addOrganism(new Guarana{}, 10, 11);
    //game.addOrganism(new Hogweed{}, 4, 17);
    //game.addOrganism(new Hogweed{}, 8, 9);
    game.addOrganism(new Milt{}, 16, 15);
    game.addOrganism(new Milt{}, 6, 23);
    game.addOrganism(new Sheep{}, 22, 8);
    game.addOrganism(new Sheep{}, 21, 22);
    game.addOrganism(new Turtle{}, 5, 20);
    game.addOrganism(new Turtle{}, 3, 1);
    game.addOrganism(new Wolf{}, 19, 13);
    game.addOrganism(new Wolf{}, 21, 20);

    /*
    World game(5, 5, 3, 4);
    game.addOrganism(new Turtle{}, 3, 1);
    game.addOrganism(new Guarana{}, 1, 1);*/

    bool finish = false; 
    while (finish == false)
    {
        //system("cls");
        bool callAction = true;
        std::string s;
        std::cout << std::endl;
        game.printInformations();
        game.printWorld();
        std::cout << "Podaj dzialanie" << std::endl;
        std::cout << "Poruszanie sie 'wsad'" << std::endl;
        std::cout << "y - uzycie umiejetnosci specjalnej" << std::endl;
        std::cout << "g - zapis gry | h - odczyt zapisu" << std::endl;
        std::cout << "q - zakoncz gre" << std::endl;
        std::cout << "" << std::endl;
        getline(std::cin, s);
        switch (s[0])
        {
        case 'w':
            game.setHumanDirection(-1, 0);
            break;
        case 's':
            game.setHumanDirection(1, 0);
            break;
        case 'd':
            game.setHumanDirection(0, 1);
            break;
        case 'a':
            game.setHumanDirection(0, -1);
            break;
        case 'x':
            game.setHumanDirection(0, 0);
            break;
        case 'y':
            if (game.getHuman()->canActivateSpecialAbility())
            {
                game.getHuman()->activateSpecialAbility();
                std::cout << "Uzyto specjalnej umiejetnosci czlowieka " << std::endl;
            }
            else
            {
                std::cout << "Nie mozna wlaczyc specjalnej umiejetnosci " << std::endl;
            }
            callAction = false;
            break;
        case 'g':
        {
            string a;
            std::cout << "Podaj sciezke do zapisu " << std::endl;
            getline(cin, a);
            game.saveState(a);
            break;
        }
        case 'h':
        {
            string a;
            std::cout << "Podaj sciezke do odczytu " << std::endl;
            getline(cin, a);
            game.loadState(a);
            break;
        }
        case 'q':
            finish = true;
            callAction = false;
            break;
        }
        if (callAction == true)
        {
            system("cls");
            game.action();
            if (game.isGameFinished() == true)
            {
                std::cout << "Gra zakonczona " << std::endl;
                game.printWorld();
                finish = true;
            }

        }
    }

    return 0;
}
