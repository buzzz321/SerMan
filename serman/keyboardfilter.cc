#include "keyboardfilter.h"

KeyboardFilter::KeyboardFilter(QObject *parent) : QObject(parent)
{

}

bool KeyboardFilter::eventFilter( QObject *dist, QEvent *event )
  {
    if( event->type() == QEvent::KeyPress )
    {
      QKeyEvent *keyEvent = static_cast<QKeyEvent*>( event );
      if( keyEvent->key() == Qt::Key_Up )
      {
        return true;
      }
    }

    return false;
  }
