#include <kapplication.h>
#include "hellokdeprogramming.h"
#include <kaboutdata.h>
#include <KCmdLineArgs>
#include <KLocale>

int main(int argc, char** argv)
{ 
    KAboutData aboutData(
                         /** The program name used internally.*/
                         "hellokdeprogramming",

                         /** The message catalog name
                         If null, program name is used instead.*/
                         0,
                         /** A displayable program name string*/
                         ki18n("Hello KDE Programming"),

                         // The program version string.*/
                         "Alpha 1",

                         /** Short description of what the app does.*/
                         ki18n("Just a simple KDE application.."),

                         /** The license this code is released under*/
                         KAboutData::License_GPL,

                         /** Copyright Statement*/
                         ki18n("(c) 2011"),

                         /**Optional text shown in the About box.
                         Can contain any information desired.*/
                         ki18n("Powered by the KDE Frameworks"),

                         /** The program homepage string.*/
                         "http://kde.org",

                         /** The bug report email address*/
                         "http://redmine.terietor.gr");
    /**Sets the authors information*/
    aboutData.addAuthor(ki18n("Giorgos Tsiapaliwkas"),ki18n("Author"),"terietor@gmail.com");

    /**Sets the application's icons.
    Hello PLASMATE!!!:P*/
    aboutData.setProgramIconName("plasmagik");

    KCmdLineArgs::init(argc,argv,&aboutData );

    KApplication app;
    hellokdeprogramming* widget = new hellokdeprogramming();
    widget->show();

    return app.exec();
}