/*
========================================================================
 Name        : NFlashTorchApplication.h
 Author      : 
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef NFLASHTORCHAPPLICATION_H
#define NFLASHTORCHAPPLICATION_H

// [[[ begin generated region: do not modify [Generated Includes]
#include <aknapp.h>
// ]]] end generated region [Generated Includes]

// [[[ begin generated region: do not modify [Generated Constants]
const TUid KUidNFlashTorchApplication = { 0xE4D0D3C7 };
// ]]] end generated region [Generated Constants]

/**
 *
 * @class	CNFlashTorchApplication NFlashTorchApplication.h
 * @brief	A CAknApplication-derived class is required by the S60 application 
 *          framework. It is subclassed to create the application's document 
 *          object.
 */
class CNFlashTorchApplication : public CAknApplication
	{
private:
	TUid AppDllUid() const;
	CApaDocument* CreateDocumentL();
	
	};
			
#endif // NFLASHTORCHAPPLICATION_H		
