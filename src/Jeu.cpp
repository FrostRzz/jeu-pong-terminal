#include "Jeu.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>

using namespace std;

Jeu::Jeu(int w, int h){
    srand(time(nullptr));
    quit = false;
    up1 = 'z';
    up2 = 'i';
    down1 = 's';
    down2 = 'k';
    score1 = 0;
    score2 = 0;
    widht = w;
    height = h;
    balle = new Balle{w/2, h/2};
    joueur1 = new Plateau{1, h/2 - 3};
    joueur2 = new Plateau{w - 2, h/2 - 3};
}

void Jeu::ScoreUp(Plateau * joueur){
    if(joueur == joueur1){
        score1++;
    }
    else if(joueur == joueur2){
        score2++;
    }

    balle->Reset();
    joueur1->Reset();
    joueur2->Reset();
}

Jeu::~Jeu(){
    delete balle;
    delete joueur1;
    delete joueur2;
}

void Jeu::Draw(){
    system("cls");
    for(int i = 0; i < widht + 2; i++){
        cout << "#";
    }
    cout << endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < widht; j++){
            int ballx = balle->getX();
            int bally = balle->getY();
            int joueur1x = joueur1->getX();
            int joueur2x = joueur2->getX();
            int joueur1y = joueur1->getY();
            int joueur2y = joueur2->getY();

            if( j == 0){
                cout << "#";
            }

            if(ballx == j && bally == i){
                cout << "O";
            }
            else if(joueur1x == j && joueur1y == i){
                cout << "█";
            }
            else if(joueur1x == j && joueur1y + 1 == i){
                cout << "█";
            }
            else if(joueur1x == j && joueur1y + 2 == i){
                cout << "█";
            }
            else if(joueur1x == j && joueur1y + 3 == i){
                cout << "█";
            }
            else if(joueur2x == j && joueur2y == i){
                cout << "█";
            }
            else if(joueur2x == j && joueur2y + 1 == i){
                cout << "█";
            }
            else if(joueur2x == j && joueur2y + 2 == i){
                cout << "█";
            }
            else if(joueur2x == j && joueur2y + 3 == i){
                cout << "█";
            }

            else{
                cout << " ";
            }

            if(j == widht - 1){
                cout << "#";
            }
        }
        cout << endl;
    }

    for(int i = 0; i < widht + 2; i++){
        cout << "#";
    }
    cout << endl;

    cout << "SCORES :" << endl;
    cout << "Joueur 1: " << score1 << endl;
    cout << "Joueur 2: " << score2 << endl;
}

void Jeu::Input(){
    balle->Bouger();
    int ballx = balle->getX();
    int bally = balle->getY();
    int joueur1x = joueur1->getX();
    int joueur2x = joueur2->getX();
    int joueur1y = joueur1->getY();
    int joueur2y = joueur2->getY();

    if (_kbhit()){
        char current = _getch();
        if(current == up1){
            if(joueur1y > 0){
                joueur1->MoveUp();
            }
        }
        if(current == up2){
            if(joueur2y > 0){
                joueur2->MoveUp();
            }
        }
        if(current == down1){
            if(joueur1y + 4 < height){
                joueur1->MoveDown();
            }
        }
        if(current == down2){
            if(joueur2y + 4 < height){
                joueur2->MoveDown();
            }
        }

        if(balle->getDirection() == STOP){
            balle->randomDirection();
        }

        if(current == 'q'){
            quit = true;
        }
    }

}

void Jeu::Logic(){
    int ballx = balle->getX();
    int bally = balle->getY();
    int joueur1x = joueur1->getX();
    int joueur2x = joueur2->getX();
    int joueur1y = joueur1->getY();
    int joueur2y = joueur2->getY();

    for(int i = 0; i < 4; i++){
        if(ballx == joueur1x + 1){
            if(bally == joueur1y + i){
                balle->ChangerDirection((Direction)((rand() % 3)+ 4));
            }
        }
    }

    for(int i = 0; i < 4; i++){
        if(ballx == joueur2x - 1){
            if(bally == joueur2y + i){
                balle->ChangerDirection((Direction)((rand() % 3) + +1));
            }
        }
    }

    if(bally == height - 1){
        balle->ChangerDirection(balle->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
    }
    if(bally == 0){
        balle->ChangerDirection(balle->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
    }
    if(ballx == widht - 1){
        ScoreUp(joueur1);
    }
    if(ballx == 0){
        ScoreUp(joueur2);
    }
}

void Jeu::Run(){
    while(!quit){
        Draw();
        Input();
        Logic();
    }
}