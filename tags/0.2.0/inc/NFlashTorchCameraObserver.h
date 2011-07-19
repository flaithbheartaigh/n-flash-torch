#ifndef NFLASHTORCHCAMERAOBSERVER_H
#define NFLASHTORCHCAMERAOBSERVER_H

#include <ecam.h>
#include <e32debug.h>

class CNFlashTorchCameraObserver : public MCameraObserver2
{
public:
   CCamera *camera;
   bool observing;
   static CNFlashTorchCameraObserver* NewL();
   void End();
   virtual ~CNFlashTorchCameraObserver();
private:
   CNFlashTorchCameraObserver();
   virtual void HandleEvent(const TECAMEvent &event);
   virtual void ViewFinderReady(MCameraBuffer &b, TInt _int);
   virtual void ImageBufferReady(MCameraBuffer &b, TInt _int);
   virtual void VideoBufferReady(MCameraBuffer &b, TInt _int);
};

#endif // NFLASHTORCHCAMERAOBSERVER_H
