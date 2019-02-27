/*
 * Xournal++
 *
 * Zoom gesture handling
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

#include <gtk/gtk.h>

class ZoomControl;

class ZoomGesture
{
public:
	ZoomGesture(GtkWidget* parent, ZoomControl* zoomControl);
	virtual ~ZoomGesture();

public:
	bool isGestureActive();

private:
	void zoomBegin();
	void zoomChanged(double zoom);
	void zoomEnd();

private:
	XOJ_TYPE_ATTRIB;

	ZoomControl* zoomControl = NULL;
	GtkGesture* gesture = NULL;

	bool gestureActive = false;
};
