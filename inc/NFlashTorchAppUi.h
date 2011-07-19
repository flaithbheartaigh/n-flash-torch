/*
========================================================================
 Name        : NFlashTorchAppUi.h
 Author      : 
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef NFLASHTORCHAPPUI_H
#define NFLASHTORCHAPPUI_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknviewappui.h>
// ]]] end generated region [Generated Includes]

// [[[ begin generated region: do not modify [Generated Forward Declarations]
// ]]] end generated region [Generated Forward Declarations]

#include "NFlashTorchCameraObserver.h"

/**
 * @class	CNFlashTorchAppUi NFlashTorchAppUi.h
 * @brief The AppUi class handles application-wide aspects of the user interface, including
 *        view management and the default menu, control pane, and status pane.
 */
class CNFlashTorchAppUi : public CAknViewAppUi
	{
public: 
	// constructor and destructor
	CNFlashTorchAppUi();
	virtual ~CNFlashTorchAppUi();
	void ConstructL();

public:
	// from CCoeAppUi
	TKeyResponse HandleKeyEventL(
				const TKeyEvent& aKeyEvent,
				TEventCode aType );

	// from CEikAppUi
	void HandleCommandL( TInt aCommand );
	void HandleResourceChangeL( TInt aType );

	// from CAknAppUi
	void HandleViewDeactivation( 
			const TVwsViewId& aViewIdToBeDeactivated, 
			const TVwsViewId& aNewlyActivatedViewId );

private:
	void InitializeContainersL();
	// [[[ begin generated region: do not modify [Generated Methods]
public: 
	// ]]] end generated region [Generated Methods]
	
	// [[[ begin generated region: do not modify [Generated Instance Variables]
private: 
	// ]]] end generated region [Generated Instance Variables]
	CEikButtonGroupContainer *controlPaneButtonGroupContainer;
	CNFlashTorchCameraObserver *observer;
	// [[[ begin [User Handlers]
protected: 
	TBool HandleControlPaneMiddleSoftKeyPressedL( TInt aCommand );
	TBool HandleTurn_OnMenuItemSelectedL( TInt aCommand );
	TBool HandleTurn_OffMenuItemSelectedL( TInt aCommand );
	// ]]] end [User Handlers]
	
	};

#endif // NFLASHTORCHAPPUI_H			
