/*
   File  : Config.h
   Author: Afonso Santos, Portugal

   Last revision: 12h15 August 09 2016
*/

#pragma once

// Uncommenting the next line will enable all LOG* calls.
#define LOG

// Commenting the next line will enable antialised and thick strokes.
//#define QEMU

// Uncoment next line to "fake" running on APLITE/DIORITE B&W platforms.
//#undef PBL_COLOR

#ifdef LOG
  #define LOGT(fmt, ...) APP_LOG(APP_LOG_LEVEL_DEBUG_VERBOSE, fmt, ##__VA_ARGS__)
  #define LOGD(fmt, ...) APP_LOG(APP_LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
  #define LOGI(fmt, ...) APP_LOG(APP_LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
  #define LOGW(fmt, ...) APP_LOG(APP_LOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)
  #define LOGE(fmt, ...) APP_LOG(APP_LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)
#else
  #define LOGT(fmt, ...)
  #define LOGD(fmt, ...)
  #define LOGI(fmt, ...)
  #define LOGW(fmt, ...)
  #define LOGE(fmt, ...)
#endif