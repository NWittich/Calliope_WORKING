#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 29 // UTC day 1-31
#define YOTTA_BUILD_HOUR 10 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 37 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 6 // UTC second 0-61
#define YOTTA_BUILD_UUID a2224152-70f5-4617-9f2a-2135b69e376c // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'04cc972f8e8df008fee91760ba79197cb0a58bc5' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'04cc972' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
