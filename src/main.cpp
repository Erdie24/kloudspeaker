/*
Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License or (at your option) version 3 or any later version
accepted by the membership of KDE e.V. (or its successor approved
by the membership of KDE e.V.), which shall act as a proxy 
defined in Section 14 of version 3 of the license.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// application header
#include "kloudspeakerwindow.h"
#include "kloudspeakerdebug.h"

// KF headers
#include <KCrash>
#include <KDBusService>
#include <KAboutData>
#include <KLocalizedString>

// Qt headers
#include <QApplication>
#include <QCommandLineParser>
#include <QIcon>
#include <QLoggingCategory>


int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("kloudspeaker");
    KCrash::initialize();

    KAboutData aboutData( QStringLiteral("kloudspeaker"),
                          i18n("kloudspeaker"),
                          QStringLiteral("%{VERSION}"),
                          i18n("A Simple Application written with KDE Frameworks"),
                          KAboutLicense::GPL,
                          i18n("Copyright %{CURRENT_YEAR}, %{AUTHOR} <%{EMAIL}>"));

    aboutData.addAuthor(i18n("%{AUTHOR}"),i18n("Author"), QStringLiteral("%{EMAIL}"));
    aboutData.setOrganizationDomain("example.org");
    aboutData.setDesktopFileName(QStringLiteral("org.example.kloudspeaker"));

    KAboutData::setApplicationData(aboutData);
    application.setWindowIcon(QIcon::fromTheme(QStringLiteral("kloudspeaker")));

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);

    parser.process(application);
    aboutData.processCommandLine(&parser);

    KDBusService appDBusService(KDBusService::Multiple | KDBusService::NoExitOnFailure);

    kloudspeakerWindow *window = new kloudspeakerWindow;
    window->show();
    return application.exec();
}
