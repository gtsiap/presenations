/**KDELIBS CODING STYLE*/
#ifndef hellokdeprogramming_H /** etsi orizoume to onoma tou header wste na mporei o gcc na to diavasei*/
#define hellokdeprogramming_H

#include <QtGui/QDialog> /**the inheritence for the base class*/
#include <KPushButton>/**logou tou m_textButton,tha katalavete meta :P*/

/**declare ta 2 class pou tha xrisimopoihsoume*/
class KPushButton;
class KMenu;

class hellokdeprogramming : public QDialog
{
Q_OBJECT /**macro to opoio xrisimopoihsoume logo tou CMAKE,wste na mporei o moc compiler na kanei 
         swsta ta connect twn object*/

public:/**keyword gia ta public methods*/
    /** ta public methods einai accessible apo class ta opoia kanoune inherit to class mas*/
    hellokdeprogramming();/**constructor*/
    virtual ~hellokdeprogramming();/**destructor*/


public Q_SLOTS:/**keyword gia ta public SLOTS*/
    void initConfig();/**Apla ena slot*/

private:/**keyword gia private methods*/
    /** ta public methods einai accessible apo class ta opoia kanoune inherit to class mas*/

    /** ena aplo declare twn object mas*/
    KPushButton* m_menuButton;
    KPushButton m_textButton;
    KMenu* m_menu;
};

#endif // hellokdeprogramming_H
