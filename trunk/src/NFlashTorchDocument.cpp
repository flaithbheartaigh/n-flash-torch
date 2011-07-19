/*
========================================================================
 Name        : NFlashTorchDocument.cpp
 Author      : 
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated User Includes]
#include "NFlashTorchDocument.h"
#include "NFlashTorchAppUi.h"
// ]]] end generated region [Generated User Includes]

/**
 * @brief Constructs the document class for the application.
 * @param anApplication the application instance
 */
CNFlashTorchDocument::CNFlashTorchDocument( CEikApplication& anApplication )
	: CAknDocument( anApplication )
	{
	}

/**
 * @brief Completes the second phase of Symbian object construction. 
 * Put initialization code that could leave here.  
 */ 
void CNFlashTorchDocument::ConstructL()
	{
	}
	
/**
 * Symbian OS two-phase constructor.
 *
 * Creates an instance of CNFlashTorchDocument, constructs it, and
 * returns it.
 *
 * @param aApp the application instance
 * @return the new CNFlashTorchDocument
 */
CNFlashTorchDocument* CNFlashTorchDocument::NewL( CEikApplication& aApp )
	{
	CNFlashTorchDocument* self = new ( ELeave ) CNFlashTorchDocument( aApp );
	CleanupStack::PushL( self );
	self->ConstructL();
	CleanupStack::Pop( self );
	return self;
	}

/**
 * @brief Creates the application UI object for this document.
 * @return the new instance
 */	
CEikAppUi* CNFlashTorchDocument::CreateAppUiL()
	{
	return new ( ELeave ) CNFlashTorchAppUi;
	}
				
