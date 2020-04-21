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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "nemoeglimagememory.h"

G_DEFINE_TYPE (NemoGstEglImageAllocator, nemo_gst_egl_image_allocator, GST_TYPE_ALLOCATOR);

static void
nemo_gst_egl_image_allocator_finalize (GObject * object)
{
  G_OBJECT_CLASS (nemo_gst_egl_image_allocator_parent_class)->finalize (object);
}

static void
nemo_gst_egl_image_allocator_init (NemoGstEglImageAllocator * allocator)
{
  allocator->create_image = NULL;
}

static void
nemo_gst_egl_image_allocator_class_init (NemoGstEglImageAllocatorClass *
    klass)
{
  GObjectClass *gobject_class = (GObjectClass *) klass;

  gobject_class->finalize = nemo_gst_egl_image_allocator_finalize;
}

EGLImageKHR
nemo_gst_egl_image_memory_create_image (GstMemory *mem, EGLDisplay dpy, EGLContext ctx)
{
  NemoGstEglImageAllocator *allocator = NEMO_GST_EGL_IMAGE_ALLOCATOR(mem->allocator);

  if (allocator && allocator->create_image) {
    return (*allocator->create_image)(mem, dpy, ctx);
  } else {
    return NULL;
  }
}
