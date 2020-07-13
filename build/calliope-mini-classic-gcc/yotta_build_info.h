#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 7 // UTC month 1-12
#define YOTTA_BUILD_DAY 13 // UTC day 1-31
#define YOTTA_BUILD_HOUR 15 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 37 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 34 // UTC second 0-61
#define YOTTA_BUILD_UUID a29ae9d7-2a27-49a3-b26e-7891475befed // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'3d1c76742b2276bbf7aaf2eefc3f2403e22a5f61' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'3d1c767' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
