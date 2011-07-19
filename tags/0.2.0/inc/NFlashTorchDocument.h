/*
========================================================================
 Name        : NFlashTorchDocument.h
 Author      : 
 Copyright   : Your copyright notice
 Description : 
========================================================================
*/
#ifndef NFLASHTORCHDOCUMENT_H
#define NFLASHTORCHDOCUMENT_H

#include <akndoc.h>
		
class CEikAppUi;

/**
* @class	CNFlashTorchDocument NFlashTorchDocument.h
* @brief	A CAknDocument-derived class is required by the S60 application 
*           framework. It is responsible for creating the AppUi object. 
*/
class CNFlashTorchDocument : public CAknDocument
	{
public: 
	// constructor
	static CNFlashTorchDocument* NewL( CEikApplication& aApp );

private: 
	// constructors
	CNFlashTorchDocument( CEikApplication& aApp );
	void ConstructL();
	
public: 
	// from base class CEikDocument
	CEikAppUi* CreateAppUiL();
	};
#endif // NFLASHTORCHDOCUMENT_H
