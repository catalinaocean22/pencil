/*

Pencil - Traditional Animation Software
Copyright (C) 2005-2007 Patrick Corrieri & Pascal Naidon

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation;

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

*/
#ifndef TIMELINE_H
#define TIMELINE_H

#include "basedockwidget.h"
#include "timecontrols.h"

class QScrollBar;
class Editor;
class TimeLineCells;


class TimeLine : public BaseDockWidget
{
	Q_OBJECT
public:
    TimeLine( QWidget* parent );
    
    void initUI() override;
    void updateUI() override;

    void updateFrame( int frameNumber );
    void updateLayerNumber( int number );
    void updateLayerView();
    void updateLength( int frameLength );
    void updateContent();
    void forceUpdateLength( QString newLength ); //when Animation -> Add Frame is clicked, this will auto update timeline
    void setFps( int );
    int getFrameLength();

signals :
	void modification();
	void lengthChange( QString );
	void frameSizeChange( int );
	void fontSizeChange( int );
	void labelChange( int );
	void scrubChange( int );
	void addKeyClick();
	void removeKeyClick();
	void duplicateKeyClick();
	void newBitmapLayer();
	void newVectorLayer();
	void newSoundLayer();
	void newCameraLayer();
	void deleteCurrentLayer();

	void playClick();
	void loopClick( bool );
    void loopToggled( bool );

    void loopControlClick( bool );
    void loopStartClick(int);
    void loopEndClick(int);

	void soundClick();
	void endplayClick();
	void startplayClick();
	void fpsClick( int );
	void onionPrevClick();
	void onionNextClick();

public:
    bool scrubbing;

protected:
	void resizeEvent( QResizeEvent* event );

private:
    QScrollBar* hScrollBar;
    QScrollBar* vScrollBar;
	TimeLineCells* cells;
	TimeLineCells* list;
	int numberOfLayers;
	TimeControls* timeControls;
};

#endif
