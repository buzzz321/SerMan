#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H

#include <QObject>
#include <QKeyEvent>

class KeyboardFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardFilter(QObject *parent = 0);

signals:

public slots:

protected:
  bool eventFilter( QObject *dist, QEvent *event );
};

#endif // KEYBOARDFILTER_H
