/***************************************************************************
                          mixxxview.cpp  -  description
                             -------------------
    begin                : Mon Feb 18 09:48:17 CET 2002
    copyright            : (C) 2002 by Tue and Ken Haste Andersen
    email                : 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "mixxxview.h"

#include <qtable.h>
#include <qdir.h>

MixxxView::MixxxView(QWidget *parent, MixxxDoc *doc) : QWidget(parent)
{
    /** connect doc with the view*/
    connect(doc, SIGNAL(documentChanged()), this, SLOT(slotDocumentChanged()));
    
    // Sub widgets
    playcontrol1 = new DlgPlaycontrol(this);
    playcontrol2 = new DlgPlaycontrol(this); playcontrol2->layoutMirror();
    channel1 = new DlgChannel(this);
    channel2 = new DlgChannel(this); channel2->layoutMirror();
    playlist = new DlgPlaylist(this);
    playlist->ListPlaylist->setColumnWidth(0,625);
    master = new DlgMaster(this);
    crossfader = new DlgCrossfader(this);
    split = new DlgSplit(this);
    flanger = new DlgFlanger(this);

    // Layout management
    mainGrid = new QGridLayout(this,6,3); // A layout on a widget
    mainGrid->addWidget(playcontrol1,0,0);
    mainGrid->addWidget(channel1,0,1);
    mainGrid->addWidget(split,0,2);
    mainGrid->addWidget(channel2,0,3);
    mainGrid->addWidget(playcontrol2,0,4);
    mainGrid->addMultiCellWidget(master,0,1,5,5);
    mainGrid->addMultiCellWidget(flanger,2,2,5,5);
    mainGrid->addMultiCellWidget(crossfader,1,1,0,4);
    mainGrid->addMultiCellWidget(playlist,2,2,0,4);

    //let the ratio between the widths of columns 0 and 1 be 2:3.
    mainGrid->setColStretch( 0, 242);
    mainGrid->setColStretch( 1,  73);
    mainGrid->setColStretch( 2,  16);
    mainGrid->setColStretch( 3,  73);
    mainGrid->setColStretch( 4, 242);
    mainGrid->setColStretch( 5, 100);

    mainGrid->setRowStretch( 0, 230);
    mainGrid->setRowStretch( 1,  43);
    mainGrid->setRowStretch( 2, 200);
}


MixxxView::~MixxxView()
{
}

void MixxxView::slotDocumentChanged()
{
  //TODO update the view

}



