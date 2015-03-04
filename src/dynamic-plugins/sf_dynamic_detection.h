/*
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * Copyright (C) 2005-2013 Sourcefire, Inc.
 *
 * Author: Steven Sturges
 *
 * Dynamic Detection Lib function declarations
 *
 */
#ifndef _SF_DYNAMIC_DETECTION_H_
#define _SF_DYNAMIC_DETECTION_H_

#include "sf_dynamic_meta.h"
#include "snort.h"

/* Function prototypes for Dynamic Detection Plugins */
void CloseDynamicDetectionLibs(void);
void LoadAllDynamicDetectionLibs(const char * const path);
int LoadDynamicDetectionLib(const char * const library_name, int indent);
int InitDynamicDetectionPlugins(SnortConfig *);
void RemoveDuplicateDetectionPlugins(void);

typedef int (*InitDetectionLibFunc)(SnortConfig *);
typedef int (*DumpDetectionRules)(void);

typedef int (*RequiredEngineLibFunc)(DynamicPluginMeta *);

void *GetNextEnginePluginVersion(void *p);
void *GetNextDetectionPluginVersion(void *p);
void *GetNextPreprocessorPluginVersion(void *p);
DynamicPluginMeta *GetDetectionPluginMetaData(void *p);
DynamicPluginMeta *GetEnginePluginMetaData(void *p);
DynamicPluginMeta *GetPreprocessorPluginMetaData(void *p);

#endif /* _SF_DYNAMIC_DETECTION_H_ */