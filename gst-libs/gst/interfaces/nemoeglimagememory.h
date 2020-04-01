/*
 * Copyright (c) 2020 Open Mobile Platform LLC.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __NEMO_GST_EGL_IMAGE_MEMORY_H__
#define __NEMO_GST_EGL_IMAGE_MEMORY_H__

#include <gst/gst.h>

G_BEGIN_DECLS

#define NEMO_GST_TYPE_EGL_IMAGE_ALLOCATOR      (nemo_gst_egl_image_allocator_get_type())
#define NEMO_GST_IS_EGL_IMAGE_ALLOCATOR(obj)   (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NEMO_GST_TYPE_EGL_IMAGE_ALLOCATOR))
#define NEMO_GST_EGL_IMAGE_ALLOCATOR(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), NEMO_GST_TYPE_EGL_IMAGE_ALLOCATOR, NemoGstEglImageAllocator))
#define NEMO_GST_EGL_IMAGE_ALLOCATOR_CAST(obj) ((NemoGstEglImageAllocator*)(obj))

typedef void * EGLImageKHR;
typedef void * EGLDisplay;
typedef void * EGLContext;

typedef struct _NemoGstEglImageAllocator NemoGstEglImageAllocator;
typedef struct _NemoGstEglImageAllocatorClass NemoGstEglImageAllocatorClass;

struct _NemoGstEglImageAllocatorClass
{
  GstAllocatorClass parent_klass;

  /*< private >*/
  gpointer                 _gst_reserved[GST_PADDING];
};

struct _NemoGstEglImageAllocator
{
  GstAllocator parent;

  EGLImageKHR (* create_image) (GstMemory *mem, EGLDisplay dpy, EGLContext ctx);
};

GType   nemo_gst_egl_image_allocator_get_type          (void);

EGLImageKHR nemo_gst_egl_image_memory_create_image (GstMemory *mem, EGLDisplay dpy, EGLContext ctx);

G_END_DECLS

#endif /* __NEMO_GST_EGL_IMAGE_MEMORY_H__ */
