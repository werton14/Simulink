#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    Position();

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int x;
    int y;
};

#endif // POSITION_H
