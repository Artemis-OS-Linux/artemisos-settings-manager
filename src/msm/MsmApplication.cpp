/*
 *  This file is part of Manjaro Settings Manager.
 *
 *  Ramon Buldó <ramon@manjaro.org>
 *  Kacper Piwiński
 *
 *  Manjaro Settings Manager is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Manjaro Settings Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Manjaro Settings Manager.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MsmApplication.h"
#include "MsmWindow.h"

#include <QtWidgets/QDesktopWidget>

#include <QDebug>

MsmApplication::MsmApplication( int& argc, char* argv[] )
    : QApplication( argc, argv ),
      m_mainwindow( 0 )
{
    setOrganizationName( "Artemis OS" );
    setOrganizationDomain( "Artemis OS" );
    setApplicationName( "Artemis OS Settings Manager" );
    setApplicationVersion( "0.5.6" );
}


MsmApplication::~MsmApplication()
{
    qDebug() << "Shutting down Artemis OS Settings Manager...";
}


void
MsmApplication::init()
{
    setWindowIcon( QIcon::fromTheme( "preferences-system" ) );

    m_mainwindow = new MsmWindow();

    m_mainwindow->move(
        this->desktop()->availableGeometry().center() - m_mainwindow->rect().center()
    );
    if ( m_startModule != nullptr )
        m_mainwindow->loadModule( m_startModule );
    m_mainwindow->show();
}


MsmApplication*
MsmApplication::instance()
{
    return qobject_cast<MsmApplication*>( QApplication::instance() );
}


void
MsmApplication::setDebug( bool enabled )
{
    m_debugMode = enabled;
}


void
MsmApplication::setStartModule( QString module )
{
    m_startModule = module;
}


bool
MsmApplication::isDebug()
{
    return m_debugMode;
}


MsmWindow*
MsmApplication::mainWindow()
{
    return m_mainwindow;
}

