#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 8 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 37 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 32 // UTC second 0-61
#define YOTTA_BUILD_UUID 58ff8405-6c80-408a-978a-480a3d401fc3 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'6b97f71b86d64006e8c018c0d68b344248adda7b' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'6b97f71' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
