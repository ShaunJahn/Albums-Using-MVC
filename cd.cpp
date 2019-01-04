#include "cd.h"

CD::CD(): composer("Unknown"), title("Unknown"), cost(0.0), rating(0)
{
}

CD::CD(QString c, QString t, double p, int r): composer(c), title(t), cost(p), rating(r)
{
}

QString CD::getComposer() const
{
    return composer;
}

QString CD::getTitle() const
{
    return title;
}

double CD::getCost() const
{
    return cost;
}

int CD::getRating() const
{
    return rating;
}

void CD::setComposer(QString c)
{
    composer = c;
}

void CD::setTitle(QString t)
{
    title = t;
}

void CD::setCost(double p)
{
    cost = p;
}

void CD::setRating(int r)
{
    rating = r;
}
