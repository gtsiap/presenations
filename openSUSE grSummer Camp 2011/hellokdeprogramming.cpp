/** Qt Libs*/
#include <QtCore/QString>
#include <QtGui/QHBoxLayout>

/**KDE libs*/
#include <KConfig>
#include <KConfigGroup>
#include <KLocalizedString>
#include <KMessageBox>
#include <KMenu>
#include <KPushButton>

/**our libs*/
#include "hellokdeprogramming.h"

/**akolouthei define tou constructor
edw tha dimiourgithei to default UI*/
hellokdeprogramming::hellokdeprogramming()
{
    setMinimumSize(300,100);/**orizoume to mikrotero megethos tou window na einai (300,100)*/
    setWindowTitle("Hello KDE Programming");/**orizoume to name tou window*/
    QHBoxLayout *hoz = new QHBoxLayout;/**kanoume allocate ena kainourgio memory*/

    m_menuButton = new KPushButton(i18n("open the menu"));/**to idio me prin,alla edw orizoume kai to name tou KPushButton*/
    m_menu = new KMenu(i18n("create config giles"));/**to idio me prin,alla edw orizoume kai to name tou KMenu*/
    m_textButton.setText("i am a seText() button");

    m_menu->addAction(i18n("create config giles"), this, SLOT(initConfig()));/**arxizoune ta wraia...*/
    /**sindeoume to method tou object mas me ena allo object kai orizoume to name tou action*/

    m_menuButton->setMenu(m_menu);/**orizoume to menu mas*/
    /**GENIKA STA QT/KDE FRAMEWORKS,otan vlepoume setFOO(),orizoume kati,kai otan vlepoume foo() epistrefoume tin timi tou
    foo.*/

    hoz->addWidget(&m_textButton);/**prosthesame to "&" epeidi to m_textButton den einai pointer.(Katalavate ti ennow:P)*/
    hoz->addWidget(m_menuButton);/**prosthetoume to button mas sto layout*/
    setLayout(hoz);/**prosthetoume to layout sto window*/
}

/**akolouthei define tou destructor*/
hellokdeprogramming::~hellokdeprogramming()
{
    /**kanoume free to memory twn "global" object*/
    delete m_menu;
    delete m_menuButton;
    /** Einai lathos i epomeni grammi,MONO POINTERS mpainoune sto destructor
    delete m_textButton;
    */
}

/**akolouthei define tou initConfig()
edw tha ginei oti exei sxesi me ta config files*/
void hellokdeprogramming::initConfig()
{
    QString dialog;/**declare*/

    dialog = i18n("Do you want to create the config files");/**define to string pou tha emfanistei*/
    const int code = KMessageBox::questionYesNo(this, dialog);/**this created the messagebox*/

    /**ena aplo flow control*/
    if (code != KMessageBox::Yes) {
        return;
    }

    dialog = i18n("hello people");/**define to orisma pou tha xreiastoume*/

    /**dimiourgoume ta Kconfig groups me 2 diaforetikous tropous*/
    KConfigGroup cg = KGlobal::config()->group("Classic way group!");
    KConfigGroup cg2(KGlobal::config(),"the parametre way!");

    /**to writeEntry den grafei sto arxeio mas,apla orizoume to ti theloume na grapsoume*/
    cg.writeEntry("entry","I am an entry");
    cg.writeEntry("welcome",dialog);
    QString welcome = i18n("welcome");
    cg2.writeEntry(welcome,dialog);

    /**to sync() einai auto to opoio "grafei" mesa sto arxeio*/
    cg.sync();
    cg2.sync();

    /**same as before*/
    dialog = i18n("Ta config files dimiourgithikan!");
    KMessageBox::information(this, dialog);
}

/**POWERED BY KDEVELOP!!!!!*/

#include "hellokdeprogramming.moc"/**just do it!
                                  ofeiletai sto CMAKE*/
