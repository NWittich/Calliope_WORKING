#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 16 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 39 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 22 // UTC second 0-61
#define YOTTA_BUILD_UUID ce71788c-33e1-46f8-b469-ff31e9f9253b // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'e5096eb049e04afc6655480c89f1d02b6d95ff9a' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'e5096eb' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
