/*
========================================================================
 Name        : NFlashTorchAppUi.cpp
 Author      : 
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated System Includes]
#include <eikmenub.h>
#include <akncontext.h>
#include <akntitle.h>
#include <NFlashTorch.rsg>
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated User Includes]
#include "NFlashTorchAppUi.h"
#include "NFlashTorch.hrh"
// ]]] end generated region [Generated User Includes]

// [[[ begin generated region: do not modify [Generated Constants]
// ]]] end generated region [Generated Constants]

/**
 * Construct the CNFlashTorchAppUi instance
 */ 
CNFlashTorchAppUi::CNFlashTorchAppUi()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/** 
 * The appui's destructor removes the container from the control
 * stack and destroys it.
 */
CNFlashTorchAppUi::~CNFlashTorchAppUi()
	{
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

// [[[ begin generated function: do not modify
void CNFlashTorchAppUi::InitializeContainersL()
	{
	}
// ]]] end generated function

/**
 * Handle a command for this appui (override)
 * @param aCommand command id to be handled
 */
void CNFlashTorchAppUi::HandleCommandL( TInt aCommand )
	{
	// [[[ begin generated region: do not modify [Generated Code]
	TBool commandHandled = EFalse;
	switch ( aCommand )
		{ // code to dispatch to the AppUi's menu and CBA commands is generated here
	
		case EAknSoftkeySelect:
			commandHandled = HandleControlPaneMiddleSoftKeyPressedL( aCommand );
			break;
		case ENFlashTorchApplicationTurn_OffMenuItemCommand:
			commandHandled = HandleTurn_OffMenuItemSelectedL( aCommand );
			break;
		case ENFlashTorchApplicationTurn_OnMenuItemCommand:
			commandHandled = HandleTurn_OnMenuItemSelectedL( aCommand );
			break;
		default:
			break;
		}
	
		
	if ( !commandHandled ) 
		{
		if ( aCommand == EAknSoftkeyExit || aCommand == EEikCmdExit )
			{
			Exit();
			}
		}
	// ]]] end generated region [Generated Code]
	
	}

/** 
 * Override of the HandleResourceChangeL virtual function
 */
void CNFlashTorchAppUi::HandleResourceChangeL( TInt aType )
	{
	CAknViewAppUi::HandleResourceChangeL( aType );
	// [[[ begin generated region: do not modify [Generated Code]
	// ]]] end generated region [Generated Code]
	
	}
				
/** 
 * Override of the HandleKeyEventL virtual function
 * @return EKeyWasConsumed if event was handled, EKeyWasNotConsumed if not
 * @param aKeyEvent 
 * @param aType 
 */
TKeyResponse CNFlashTorchAppUi::HandleKeyEventL(
		const TKeyEvent& aKeyEvent,
		TEventCode aType )
	{
	// The inherited HandleKeyEventL is private and cannot be called
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	return EKeyWasNotConsumed;
	}

/** 
 * Override of the HandleViewDeactivation virtual function
 *
 * @param aViewIdToBeDeactivated 
 * @param aNewlyActivatedViewId 
 */
void CNFlashTorchAppUi::HandleViewDeactivation( 
		const TVwsViewId& aViewIdToBeDeactivated, 
		const TVwsViewId& aNewlyActivatedViewId )
	{
	CAknViewAppUi::HandleViewDeactivation( 
			aViewIdToBeDeactivated, 
			aNewlyActivatedViewId );
	// [[[ begin generated region: do not modify [Generated Contents]
	// ]]] end generated region [Generated Contents]
	
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here. 
 */ 
void CNFlashTorchAppUi::ConstructL() {
	// [[[ begin generated region: do not modify [Generated Contents]	
	BaseConstructL( EAknEnableSkin  | 
					 EAknEnableMSK ); 
	InitializeContainersL();
	// ]]] end generated region [Generated Contents]
	
	/// ADDING CONTROL PANE
	controlPaneButtonGroupContainer = CEikButtonGroupContainer::NewL(
			CEikButtonGroupContainer::ECba,
			CEikButtonGroupContainer::EVertical,
			this,
			R_APPLICATION_CONTROL_PANE
	);
	this->AddToStackL(controlPaneButtonGroupContainer);
	controlPaneButtonGroupContainer->DrawNow();
	// CONTROL PANE ADDED
	
	HBufC* lblTurnOn = CEikonEnv::Static()->AllocReadResourceL(R_APPLICATION_SELECT_TURN_ON);
	HBufC* lblTurnOff = CEikonEnv::Static()->AllocReadResourceL(R_APPLICATION_SELECT_TURN_OFF);
	controlPaneButtonGroupContainer->SetCommandL(3, EAknSoftkeySelect, *lblTurnOn);

#ifndef __WINSCW__
	observer = CNFlashTorchCameraObserver::NewL();
	controlPaneButtonGroupContainer->SetCommandL(3, EAknSoftkeySelect, *lblTurnOff);
#endif

	}

/** 
 * Handle the middleSoftKeyPressed event.
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CNFlashTorchAppUi::HandleControlPaneMiddleSoftKeyPressedL( TInt aCommand ) {
	HBufC* lblTurnOn = CEikonEnv::Static()->AllocReadResourceLC( R_APPLICATION_SELECT_TURN_ON );
	HBufC* lblTurnOff = CEikonEnv::Static()->AllocReadResourceLC( R_APPLICATION_SELECT_TURN_OFF );
	
#ifndef __WINSCW__	
	if (observer->observing) {
		observer->End();
		controlPaneButtonGroupContainer->SetCommandL(3, EAknSoftkeySelect, *lblTurnOn);
	} else {
		observer = CNFlashTorchCameraObserver::NewL();
		controlPaneButtonGroupContainer->SetCommandL(3, EAknSoftkeySelect, *lblTurnOff);
	}
	controlPaneButtonGroupContainer->DrawDeferred(); // or DrawNow
#endif
	
	return ETrue;
}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CNFlashTorchAppUi::HandleTurn_OnMenuItemSelectedL( TInt aCommand ) {
	HBufC* lblTurnOff = CEikonEnv::Static()->AllocReadResourceLC( R_APPLICATION_SELECT_TURN_OFF );
	
#ifndef __WINSCW__
	if (!observer->observing) {
		observer = CNFlashTorchCameraObserver::NewL();
		controlPaneButtonGroupContainer->SetCommandL(3, EAknSoftkeySelect, *lblTurnOff);
	}
#endif

	return ETrue;
	}
				
/** 
 * Handle the selected event.
 * @param aCommand the command id invoked
 * @return ETrue if the command was handled, EFalse if not
 */
TBool CNFlashTorchAppUi::HandleTurn_OffMenuItemSelectedL( TInt aCommand ) {
	HBufC* lblTurnOn = CEikonEnv::Static()->AllocReadResourceLC( R_APPLICATION_SELECT_TURN_ON );
	
#ifndef __WINSCW__
	if (observer->observing) {
		observer->End();
		controlPaneButtonGroupContainer->SetCommandL(3, EAknSoftkeySelect, *lblTurnOn);
	}
#endif
	
	return ETrue;
}
				
