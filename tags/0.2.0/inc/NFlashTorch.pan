
#ifndef NFLASHTORCH_PAN_H
#define NFLASHTORCH_PAN_H

/** NFlashTorch application panic codes */
enum TNFlashTorchPanics
	{
	ENFlashTorchUi = 1
	// add further panics here
	};

inline void Panic(TNFlashTorchPanics aReason)
	{
	_LIT(applicationName,"NFlashTorch");
	User::Panic(applicationName, aReason);
	}

#endif // NFLASHTORCH_PAN_H
