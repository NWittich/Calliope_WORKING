#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 25 // UTC day 1-31
#define YOTTA_BUILD_HOUR 16 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 28 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 9 // UTC second 0-61
#define YOTTA_BUILD_UUID 642f8048-e2e5-4add-9aea-44c2f777312d // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'cf7a081d0674378a561ae17596abdf83e48c376c' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'cf7a081' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
