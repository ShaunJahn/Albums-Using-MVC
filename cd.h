#ifndef CD_H
#define CD_H

#include <QString>

class CD
{
public:
    CD();
    CD(QString c, QString t, double p, int r);
    QString getComposer() const;
    QString getTitle() const;
    double getCost() const;
    int getRating() const;
    void setComposer(QString c);
    void setTitle(QString t);
    void setCost(double p);
    void setRating(int r);
private:
    QString composer;
    QString title;
    double cost;
    int rating;
};

#endif // CD_H
