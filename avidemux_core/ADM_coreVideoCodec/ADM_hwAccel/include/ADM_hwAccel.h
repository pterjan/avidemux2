/***************************************************************************
         \fn ADM_hwAccel.h
         \brief Top class for ffmpeg hwAccel
         \author mean, fixounet@free.fr (C) 2006
    
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#pragma once
#include "ADM_coreVideoCodec6_export.h"
#include "ADM_compressedImage.h"
/**
 * 
 */
class decoderFF;
class ADM_COREVIDEOCODEC6_EXPORT ADM_acceleratedDecoderFF
{
public:
                     ADM_acceleratedDecoderFF(struct AVCodecContext *avctx,decoderFF *p) 
                     {_context=avctx;_parent=p;};
        virtual      ~ADM_acceleratedDecoderFF()
                    {
                        _context=NULL;
                        _parent=NULL;
                    }
        virtual bool uncompress (ADMCompressedImage * in, ADMImage * out)=0;
protected:
                struct AVCodecContext *_context;
                decoderFF *_parent;
};

/**
 *  \class ADM_hwAccel
 */
extern "C"
{
class ADM_hwAccelEntry
{
public:    
     const char             *name;
     virtual bool           canSupportThis(struct AVCodecContext *avctx,  const enum AVPixelFormat *fmt,enum AVPixelFormat &outputFormat)=0;
     virtual                ADM_acceleratedDecoderFF *spawn( struct AVCodecContext *avctx,  const enum AVPixelFormat *fmt )=0;     
     virtual                ~ADM_hwAccelEntry() {};
};
}
/**
 * \fn ADM_hwAccelManager
 */
class ADM_COREVIDEOCODEC6_EXPORT ADM_hwAccelManager
{
public:       
       static bool                registerDecoder(ADM_hwAccelEntry *);
       static ADM_hwAccelEntry    *lookup(struct AVCodecContext *avctx,  const enum AVPixelFormat *fmt,enum AVPixelFormat &outputFormat);
       static ADM_acceleratedDecoderFF *spawn( struct AVCodecContext *avctx,  const enum AVPixelFormat *fmt,enum AVPixelFormat &outputFormat );     
};


// EOF