#include "NFlashTorchCameraObserver.h"

CNFlashTorchCameraObserver::CNFlashTorchCameraObserver() {
    observing = true;
}

CNFlashTorchCameraObserver::~CNFlashTorchCameraObserver() {}

CNFlashTorchCameraObserver* CNFlashTorchCameraObserver::NewL() {
	CNFlashTorchCameraObserver *self;
    self = new CNFlashTorchCameraObserver();

    self->camera = CCamera::New2L(*self, 0, 0);
    self->camera->Reserve();

    return self;
}


void CNFlashTorchCameraObserver::HandleEvent(const TECAMEvent &event) {
    //__cout << "HANDLE_EVENT";
    if (event.iEventType == KUidECamEventReserveComplete) {
        //__cout << "RESERVE_COMPLETE";
        camera->PowerOn();
    }

    if (event.iEventType == KUidECamEventPowerOnComplete) {
        //__cout << "POWERON_COMPLETE";

        TCameraInfo info;
        camera->CameraInfo(info);
/*
        if ( info.iImageFormatsSupported & CCamera::EFormatMonochrome ) cout << "____FMT1____";
        if ( info.iImageFormatsSupported & CCamera::EFormat16bitRGB444 ) cout << "____FMT2____";
        if ( info.iImageFormatsSupported & CCamera::EFormat16BitRGB565 ) cout << "____FMT3____";
        if ( info.iImageFormatsSupported & CCamera::EFormat32BitRGB888 ) cout << "____FMT4____";
        if ( info.iImageFormatsSupported & CCamera::EFormatJpeg ) cout << "____FMT5____";
        if ( info.iImageFormatsSupported & CCamera::EFormatExif ) cout << "____FMT6____";
        if ( info.iImageFormatsSupported & CCamera::EFormatFbsBitmapColor4K ) cout << "____FMT7____";
        if ( info.iImageFormatsSupported & CCamera::EFormatFbsBitmapColor64K ) cout << "____FMT8____";
        if ( info.iImageFormatsSupported & CCamera::EFormatFbsBitmapColor16M ) cout << "____FMT9____";
        if ( info.iImageFormatsSupported & CCamera::EFormatUserDefined ) cout << "____FMT10____";
        if ( info.iImageFormatsSupported & CCamera::EFormatYUV420Interleaved ) cout << "____FMT11____";
        if ( info.iImageFormatsSupported & CCamera::EFormatYUV420Planar ) cout << "____FMT12____";
        if ( info.iImageFormatsSupported & CCamera::EFormatYUV422 ) cout << "____FMT13____";
        if ( info.iImageFormatsSupported & CCamera::EFormatYUV422Reversed ) cout << "____FMT14____";
        if ( info.iImageFormatsSupported & CCamera::EFormatYUV444 ) cout << "____FMT15____";
        if ( info.iImageFormatsSupported & CCamera::EFormatYUV420SemiPlanar ) cout << "____FMT16____";
        if ( info.iImageFormatsSupported & CCamera::EFormatFbsBitmapColor16MU ) cout << "____FMT17____";
        if ( info.iImageFormatsSupported & CCamera::EFormatMJPEG ) cout << "____FMT18____";
        if ( info.iImageFormatsSupported & CCamera::EFormatEncodedH264 ) cout << "____FMT19____";
*/
        //formati supportati:
        //CCamera::EFormatExif
        //CCamera::EFormatFbsBitmapColor4K
        //CCamera::EFormatFbsBitmapColor64K
        //CCamera::EFormatFbsBitmapColor16M
/*
        if ( info.iFlashModesSupported & CCamera::EFlashAuto ) cout << "____FLA1____SUPPORTED";
        if ( info.iFlashModesSupported & CCamera::EFlashFillIn ) cout << "____FLA2____";
        if ( info.iFlashModesSupported & CCamera::EFlashForced) cout << "____FLA3____SUPPORTED";
        if ( info.iFlashModesSupported & CCamera::EFlashManual ) cout << "____FLA4____";
        if ( info.iFlashModesSupported & CCamera::EFlashNone ) cout << "____FLA5____";
        if ( info.iFlashModesSupported & CCamera::EFlashRedEyeReduce ) cout << "____FLA6____SUPPORTED";
        if ( info.iFlashModesSupported & CCamera::EFlashSlowFrontSync ) cout << "____FLA7____";
        if ( info.iFlashModesSupported & CCamera::EFlashSlowRearSync) cout << "____FLA8____";
        if ( info.iFlashModesSupported & CCamera::EFlashVideoLight ) cout << "____FLA9____SUPPORTED";

        if ( info.iVideoFrameFormatsSupported & CCamera::EFormatYUV420Planar ) cout << "____FMT12____SUPPORTEDDDDDDDDD";
        if ( info.iVideoFrameFormatsSupported & CCamera::EFormatYUV422 ) cout << "____FMT13____SUPPORTEDDDDDDDDDDDDDDD";
*/
        CCamera::TFormat tFormat;
        CCamera::TFormat tFormatVideo;

        tFormat = CCamera::EFormatExif;
        tFormatVideo = CCamera::EFormatYUV422;

        //__ cout << "PREPARE";
        camera->PrepareVideoCaptureL(tFormatVideo,0,0,1,info.iMaxFramesPerBufferSupported);
        //__ cout << "FLASH";
        camera->SetFlashL(CCamera::EFlashVideoLight);
        //__ cout << "CAPTURE";
        camera->StartVideoCapture();
        //__ cout << "CAPTURE2";
    }
}

void CNFlashTorchCameraObserver::ViewFinderReady(MCameraBuffer &b, TInt _int) {
}

void CNFlashTorchCameraObserver::ImageBufferReady(MCameraBuffer &b, TInt _int) {
    b.Release(); //do nothing
}

void CNFlashTorchCameraObserver::VideoBufferReady(MCameraBuffer &b, TInt _int) {
    b.Release(); //do nothing
}

void CNFlashTorchCameraObserver::End() {
	TRAP_IGNORE( camera->SetFlashL(CCamera::EFlashNone) );
	camera->StopVideoCapture();
	TRAP_IGNORE( camera->SetFlashL(CCamera::EFlashNone) );
	camera->PowerOff();
    camera->Release();
    observing = false;
}
