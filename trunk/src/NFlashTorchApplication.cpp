/*
========================================================================
 Name        : NFlashTorchApplication.cpp
 Author      : 
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
// [[[ begin generated region: do not modify [Generated System Includes]
// ]]] end generated region [Generated System Includes]

// [[[ begin generated region: do not modify [Generated Includes]
#include "NFlashTorchApplication.h"
#include "NFlashTorchDocument.h"
#ifdef EKA2
#include <eikstart.h>
#endif
// ]]] end generated region [Generated Includes]

/**
 * @brief Returns the application's UID (override from CApaApplication::AppDllUid())
 * @return UID for this application (KUidNFlashTorchApplication)
 */
TUid CNFlashTorchApplication::AppDllUid() const
	{
	return KUidNFlashTorchApplication;
	}

/**
 * @brief Creates the application's document (override from CApaApplication::CreateDocumentL())
 * @return Pointer to the created document object (CNFlashTorchDocument)
 */
CApaDocument* CNFlashTorchApplication::CreateDocumentL()
	{
	return CNFlashTorchDocument::NewL( *this );
	}

#ifdef EKA2

/**
 *	@brief Called by the application framework to construct the application object
 *  @return The application (CNFlashTorchApplication)
 */	
LOCAL_C CApaApplication* NewApplication()
	{
	return new CNFlashTorchApplication;
	}

/**
* @brief This standard export is the entry point for all Series 60 applications
* @return error code
 */	
GLDEF_C TInt E32Main()
	{
	return EikStart::RunApplication( NewApplication );
	}
	
#else 	// Series 60 2.x main DLL program code

/**
* @brief This standard export constructs the application object.
* @return The application (CNFlashTorchApplication)
*/
EXPORT_C CApaApplication* NewApplication()
	{
	return new CNFlashTorchApplication;
	}

/**
* @brief This standard export is the entry point for all Series 60 applications
* @return error code
*/
GLDEF_C TInt E32Dll(TDllReason /*reason*/)
	{
	return KErrNone;
	}

#endif // EKA2
