#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 5 // UTC day 1-31
#define YOTTA_BUILD_HOUR 9 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 29 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 38 // UTC second 0-61
#define YOTTA_BUILD_UUID 8b4cd6f7-9de5-46d4-a2d6-530965fb0aa1 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'2b84a1c5f7bb52a7c5ee34c07025444274693855' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'2b84a1c' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
