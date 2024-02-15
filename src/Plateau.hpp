class Plateau{
private:
    int x, y;
    int oX, oY;
public:
    Plateau();
    Plateau(int X, int Y);
    void Reset();
    int getX() const {return x;};
    int getY() const {return y;};
    void MoveUp() { y--; };
    void MoveDown() { y++; };
};