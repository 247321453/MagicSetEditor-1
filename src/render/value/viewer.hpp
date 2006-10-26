//+----------------------------------------------------------------------------+
//| Description:  Magic Set Editor - Program to make Magic (tm) cards          |
//| Copyright:    (C) 2001 - 2006 Twan van Laarhoven                           |
//| License:      GNU General Public License 2 or later (see file COPYING)     |
//+----------------------------------------------------------------------------+

#ifndef HEADER_RENDER_VALUE_VIEWER
#define HEADER_RENDER_VALUE_VIEWER

// ----------------------------------------------------------------------------- : Includes

#include <util/prec.hpp>
#include <util/rotation.hpp>
#include <util/real_point.hpp>

class DataViewer;
class ValueAction;
DECLARE_POINTER_TYPE(Style);
DECLARE_POINTER_TYPE(Value);

// ----------------------------------------------------------------------------- : ValueViewer

/// The virtual viewer control for a single field on a card (or in the set data)
/** A viewer can only display a value, not edit it, ValueEditor is used for that */
class ValueViewer {
  public:
	/// Construct a ValueViewer, set the value at a later time
	ValueViewer(DataViewer& parent, const StyleP& style);
	virtual ~ValueViewer();
	
	// Draw this value
	virtual void draw(RotatedDC& dc) = 0;
	
	/// Does this field contian the given point?
	virtual bool containsPoint(const RealPoint& p) const;
	/// Get a bounding rectangle for this field (including any border it may have)
	virtual RealRect boundingBox() const;
	
	/// Called when the associated value is changed
	/** Both when we are associated with another value,
	 *  and by default when the value itself changes (called from onAction)
	 */
	virtual void onValueChange() {}
	/// Called when a (scripted) property of the associated style has changed
	virtual void onStyleChange() {}
	/// Called when an action is performed on the associated value
	virtual void onAction(const ValueAction&, bool undone) { onValueChange(); }
	
	/// Change the associated value
	void setValue(const ValueP&);
	
  protected:
	DataViewer& viewer;	///< Our parent object
	StyleP style_;		///< The style of this viewer
	ValueP value_;		///< The value we are currently viewing
	
	/// Should this viewer render using a platform native look?
	bool nativeLook() const;
	/// Is this the currently selected viewer?
	/** Usually only the editor allows selection of viewers */
	bool isCurrent() const;
	
	/// Draws a border around the field
	void drawFieldBorder(RotatedDC& dc);
};

// ----------------------------------------------------------------------------- : Utility

#define VALUE_VIEWER(Base, Type)								\
  public:														\
	Type(DataViewer& parent, const Type ## StyleP& style)		\
  private:														\
	inline Type##Style style() const { return *value_; }		\
	inline Type##Value value() const { return *value_; }


// ----------------------------------------------------------------------------- : EOF
#endif