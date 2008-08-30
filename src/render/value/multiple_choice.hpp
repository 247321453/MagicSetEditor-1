//+----------------------------------------------------------------------------+
//| Description:  Magic Set Editor - Program to make Magic (tm) cards          |
//| Copyright:    (C) 2001 - 2008 Twan van Laarhoven and "coppro"              |
//| License:      GNU General Public License 2 or later (see file COPYING)     |
//+----------------------------------------------------------------------------+

#ifndef HEADER_RENDER_VALUE_MULTIPLE_CHOICE
#define HEADER_RENDER_VALUE_MULTIPLE_CHOICE

// ----------------------------------------------------------------------------- : Includes

#include <util/prec.hpp>
#include <render/value/viewer.hpp>
#include <data/field/multiple_choice.hpp>

// ----------------------------------------------------------------------------- : MultipleChoiceValueViewer

/// Viewer that displays a multiple choice value
class MultipleChoiceValueViewer : public ValueViewer {
  public:
	DECLARE_VALUE_VIEWER(MultipleChoice) : ValueViewer(parent,style), item_height(0) {}
	
	virtual bool prepare(RotatedDC& dc);
	virtual void draw(RotatedDC& dc);
	virtual void onStyleChange(int);
	virtual bool containsPoint(const RealPoint& p) const;
  protected:
	double item_height; ///< Height of a single item, or 0 if non uniform
  private:
	void drawChoice(RotatedDC& dc, RealPoint& pos, const String& choice, bool active = true);
	/// Draws a border around the field
	void drawFieldBorder(RotatedDC& dc, const AlphaMask& alpha_mask);
	/// Load the AlphaMask for this field
	const AlphaMask& getMask(int w, int h) const;
};

// ----------------------------------------------------------------------------- : EOF
#endif
