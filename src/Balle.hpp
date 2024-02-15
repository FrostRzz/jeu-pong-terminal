enum Direction {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class Balle{
private:
    int x, y;
    int oX, oY;
    Direction dir;
public:
    Balle(int x, int y);
    void Reset();
    void ChangerDirection(Direction d);
    int getX() const {return x;};
    int getY() const {return y;};
    Direction getDirection() const {return dir;};
    void randomDirection();
    void Bouger();
};