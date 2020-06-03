#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 3 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 32 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 9 // UTC second 0-61
#define YOTTA_BUILD_UUID 214253f1-4294-4455-b5a9-681b28cf85f0 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'9aca81a0dda02ba2e4ac61f97c463c7d1005dd68' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'9aca81a' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
