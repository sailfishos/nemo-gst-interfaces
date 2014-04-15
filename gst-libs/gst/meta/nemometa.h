/*
 * Copyright (C) 2014 Mohammed Sameer <msameer@foolab.org>
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

#ifndef __NEMO_META_H__
#define __NEMO_META_H__

#include <gst/gst.h>

G_BEGIN_DECLS

#define NEMO_GST_BUFFER_ORIENTATION_META_API_TYPE (nemo_gst_buffer_orientation_meta_api_get_type())
#define NEMO_GST_BUFFER_ORIENTATION_META_INFO     (nemo_gst_buffer_orientation_meta_get_info())

typedef struct _NemoGstBufferOrientationMeta NemoGstBufferOrientationMeta;

typedef enum
{
  NEMO_GST_META_BUFFER_ORIENTATION_0 = 0,
  NEMO_GST_META_BUFFER_ORIENTATION_90,
  NEMO_GST_META_BUFFER_ORIENTATION_180,
  NEMO_GST_META_BUFFER_ORIENTATION_270,
} NemoGstBufferOrientation;

typedef enum
{
  NEMO_GST_META_DEVICE_DIRECTION_BACK = 0,
  NEMO_GST_META_DEVICE_DIRECTION_FRONT,
} NemoGstDeviceDirection;

struct _NemoGstBufferOrientationMeta {
  GstMeta       meta;

  NemoGstBufferOrientation orientation;
  NemoGstDeviceDirection direction;
};

GType nemo_gst_buffer_orientation_meta_api_get_type (void);
const GstMetaInfo * nemo_gst_buffer_orientation_meta_get_info (void);

#define gst_buffer_get_nemo_gst_buffer_orientation_meta(b)		\
  ((GstDroidMeta*)gst_buffer_get_meta((b),NEMO_GST_BUFFER_ORIENTATION_META_API_TYPE))

NemoGstBufferOrientationMeta *
gst_buffer_add_gst_buffer_orientation_meta (GstBuffer * buffer,
					    NemoGstBufferOrientation orientation,
					    NemoGstDeviceDirection direction);

G_END_DECLS

#endif /* __NEMO_META_H__ */
