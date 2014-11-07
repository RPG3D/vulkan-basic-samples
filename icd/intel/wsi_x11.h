/*
 * XGL
 *
 * Copyright (C) 2014 LunarG, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *   Chia-I Wu <olv@lunarg.com>
 */

#ifndef WSI_X11_H
#define WSI_X11_H

#include "intel.h"

struct intel_wsi_x11;
struct intel_wsi_x11_window;

#ifdef ENABLE_WSI_X11

XGL_RESULT intel_wsi_x11_wait(struct intel_wsi_x11 *x11,
                              struct intel_wsi_x11_window *win,
                              uint32_t serial, bool wait);

void intel_wsi_x11_destroy(struct intel_wsi_x11 *x11);

XGL_RESULT XGLAPI intelWsiX11AssociateConnection(
    XGL_PHYSICAL_GPU                            gpu,
    const XGL_WSI_X11_CONNECTION_INFO*          pConnectionInfo);

XGL_RESULT XGLAPI intelWsiX11GetMSC(
    XGL_DEVICE                                  device,
    xcb_window_t                                window,
    xcb_randr_crtc_t                            crtc,
    XGL_UINT64*                                 pMsc);

XGL_RESULT XGLAPI intelWsiX11CreatePresentableImage(
    XGL_DEVICE                                  device,
    const XGL_WSI_X11_PRESENTABLE_IMAGE_CREATE_INFO* pCreateInfo,
    XGL_IMAGE*                                  pImage,
    XGL_GPU_MEMORY*                             pMem);

XGL_RESULT XGLAPI intelWsiX11QueuePresent(
    XGL_QUEUE                                   queue,
    const XGL_WSI_X11_PRESENT_INFO*             pPresentInfo,
    XGL_FENCE                                   fence);

#else /* ENABLE_WSI_X11 */

static inline XGL_RESULT intel_wsi_x11_wait(struct intel_wsi_x11 *x11,
                                            struct intel_wsi_x11_window *win,
                                            uint32_t serial, bool wait)
{
    return XGL_SUCCESS;
}

static inline void intel_wsi_x11_destroy(struct intel_wsi_x11 *x11)
{
}

static inline XGL_RESULT XGLAPI intelWsiX11AssociateConnection(
    XGL_PHYSICAL_GPU                            gpu,
    const XGL_WSI_X11_CONNECTION_INFO*          pConnectionInfo)
{
    return XGL_ERROR_UNKNOWN;
}

static inline XGL_RESULT XGLAPI intelWsiX11GetMSC(
    XGL_DEVICE                                  device,
    xcb_window_t                                window,
    xcb_randr_crtc_t                            crtc,
    XGL_UINT64*                                 pMsc)
{
    return XGL_ERROR_UNKNOWN;
}

static inline XGL_RESULT XGLAPI intelWsiX11CreatePresentableImage(
    XGL_DEVICE                                  device,
    const XGL_WSI_X11_PRESENTABLE_IMAGE_CREATE_INFO* pCreateInfo,
    XGL_IMAGE*                                  pImage,
    XGL_GPU_MEMORY*                             pMem)
{
    return XGL_ERROR_UNKNOWN;
}

static inline XGL_RESULT XGLAPI intelWsiX11QueuePresent(
    XGL_QUEUE                                   queue,
    const XGL_WSI_X11_PRESENT_INFO*             pPresentInfo,
    XGL_FENCE                                   fence)
{
    return XGL_ERROR_UNKNOWN;
}

#endif /* ENABLE_WSI_X11 */

#endif /* WSI_X11_H */
