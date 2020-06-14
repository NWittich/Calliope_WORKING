#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 14 // UTC day 1-31
#define YOTTA_BUILD_HOUR 11 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 48 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 20 // UTC second 0-61
#define YOTTA_BUILD_UUID f57a98b1-8fdb-44ee-82d7-578bf26e6d42 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'6bcdc7c28c5f116bda07287df116977937341289' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'6bcdc7c' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
