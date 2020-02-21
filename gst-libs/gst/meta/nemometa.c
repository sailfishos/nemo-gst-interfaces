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

#include "nemometa.h"
#include <gst/video/video.h>

static gboolean
nemo_gst_buffer_orientation_meta_transform (GstBuffer * dest, GstMeta * meta,
    GstBuffer * buffer, GQuark type, gpointer data);

static gboolean
nemo_gst_buffer_orientation_meta_init (GstMeta *meta, gpointer params, GstBuffer *buffer)
{
  return TRUE;
}

GType
nemo_gst_buffer_orientation_meta_api_get_type (void)
{
  static volatile GType type = 0;
  static const gchar *tags[] =
    { GST_META_TAG_VIDEO_STR, NULL
    };

  if (g_once_init_enter (&type)) {
    GType _type = gst_meta_api_type_register ("NemoGstBufferOrientationMetaAPI", tags);
    g_once_init_leave (&type, _type);
  }

  return type;
}

const GstMetaInfo *
nemo_gst_buffer_orientation_meta_get_info (void)
{
  static const GstMetaInfo *meta_info = NULL;

  if (g_once_init_enter (&meta_info)) {
    const GstMetaInfo *meta =
      gst_meta_register (NEMO_GST_BUFFER_ORIENTATION_META_API_TYPE, "NemoGstBufferOrientationMeta",
			 sizeof (NemoGstBufferOrientationMeta),
			 nemo_gst_buffer_orientation_meta_init,
			 (GstMetaFreeFunction) NULL,
			 nemo_gst_buffer_orientation_meta_transform);

    g_once_init_leave (&meta_info, meta);
  }

  return meta_info;
}

NemoGstBufferOrientationMeta *
gst_buffer_add_gst_buffer_orientation_meta (GstBuffer * buffer,
    NemoGstBufferOrientation orientation, NemoGstDeviceDirection direction)
{
  NemoGstBufferOrientationMeta *meta = (NemoGstBufferOrientationMeta *)
    gst_buffer_add_meta (buffer, NEMO_GST_BUFFER_ORIENTATION_META_INFO, NULL);

  meta->orientation = orientation;
  meta->direction = direction;

  return meta;
}

static gboolean
nemo_gst_buffer_orientation_meta_transform (GstBuffer * dest, GstMeta * meta,
    GstBuffer * buffer, GQuark type, gpointer data)
{
  NemoGstBufferOrientationMeta *smeta = (NemoGstBufferOrientationMeta *) meta;

  // This meta is about how the buffer is created. So, `type` doesn't matter.
  if (!gst_buffer_add_gst_buffer_orientation_meta (dest, smeta->orientation,
          smeta->direction)) {
    return FALSE;
  }

  return TRUE;
}
