/**************************************************************************
 *
 * Copyright 2012 Francisco Jerez
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

#ifndef PIPE_LOADER_PRIV_H
#define PIPE_LOADER_PRIV_H

#include "pipe_loader.h"

struct pipe_loader_ops {
   struct pipe_screen *(*create_screen)(struct pipe_loader_device *dev,
                                        const struct pipe_screen_config *config);

   const char *(*get_driconf_xml)(struct pipe_loader_device *dev);

   void (*release)(struct pipe_loader_device **dev);
};

/**
 * Open the pipe driver module that contains the specified driver.
 */
struct util_dl_library *
pipe_loader_find_module(const char *driver_name,
                        const char *library_paths);

/**
 * Free the base device structure.
 *
 * Implementations of pipe_loader_ops::release must call this.
 *
 * (*dev)->driver_name must be freed by the caller if it was allocated on the
 * heap.
 */
void
pipe_loader_base_release(struct pipe_loader_device **dev);

#endif /* PIPE_LOADER_PRIV_H */
