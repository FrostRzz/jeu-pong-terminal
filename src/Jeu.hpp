#include "Balle.hpp"
#include "Plateau.hpp"

class Jeu{
private:
    int widht, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    Balle * balle;
    Plateau * joueur1;
    Plateau * joueur2;
public:
    Jeu(int width, int height);
    void ScoreUp(Plateau * joueur);
    void Draw();
    void Input();
    void Logic();
    void Run();
    ~Jeu();
};